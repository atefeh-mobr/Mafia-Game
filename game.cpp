#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "game.hpp"
#include "person.hpp"
#include "villager.hpp"
#include "joker.hpp"
#include "detective.hpp"
#include "doctor.hpp"
#include "bulletproof.hpp"
#include "mafia.hpp"
#include "godfather.hpp"
#include "silencer.hpp"

#include "no_game_error.cpp"
#include "not_a_player_error.cpp"
#include "incomplete_role_error.cpp"
#include "complete_role_error.cpp"
#include "silenced_player_error.cpp"
#include "dead_player_error.cpp"
#include "joker_won_error.cpp"
#include "sleepy_player_error.cpp"
#include "asked_detective_error.cpp"
#include "healed_doctor_error.cpp"
#include "repeat_swap_error.cpp"
#include "night_swap_error.cpp"
#include "day_swap_error.cpp"

using namespace std;

const int stage0 = 0;
const string NOGAME = "No game created"; 
const string NOTAPLAYER = "User not joined";
const string REMAININGROLES = "One or more players do not have a role";
const string VALIDGAME = "Game has already started";
const string STARTMESSAGE = "Ready? Set! Go.";
const string DAY = "Day ";
const string NIGHT = "Night ";
const string ENDVOTE = "end_vote";
const string ENDNIGHT = "end_night";
const string SILENCEDPLAYER = "Voter is silenced";
const string DEADPLAYER = "Votee already dead";
const string SLEEPYPLAYER = "User can not wake up during night";
const string DEADDOER = "User is dead";
const string DIED = " died";
const string MAFIAKILLED = "Mafia tried to kill ";
const string KILLEDATNIGHT = " was killed";
const string SPACE = " ";
const string SILENTS = "Silenced";
const string SWAPCHARACTER = "swap_character";
const string REPEATSWAP = "Characters already swapped";
const string NIGHTSWAPERROR = "Can't swap before end of night";
const string DAYSWAPERROR = "Voting in progress";
const string MAFIAS = "Mafia = ";
const string VILLAGERS = "Villager = ";

const string JOKER = "joker";
const string VILLAGER = "villager";
const string DETECTIVE = "detective";
const string DOCTOR = "doctor";
const string BULLETPROOF = "bulletproof";
const string MAFIA = "mafia";
const string GODFATHER = "godfather";
const string SILENCER = "silencer";

const string NOTASSIGNED = "notAssigned";

Game::Game() {}

Game::Game(int Start) {
	numberOfPlayers = 0;
	numberOfGoodPlayers = 0;
	numberOfBadPlayers = 0;
	isStarted = false;
	readyOrStart = false;
	isSwap = false;
	middleDay = false;
	middleNight = false;
	people.clear();
	userNames.clear();
}

void Game::createGame(string allNames) {
	day = stage0;
	night = stage0;
	isStarted = true;
	findNames(allNames);
}

void Game::findNames(string allNames) {
	string name;
	vector<string> names;
	stringstream lineStream(allNames);
	while(lineStream >> name) {
		userNames.push_back(name);
		numberOfPlayers ++;
	}
}

void Game::assignRole(string information) {
	try {
		vector<string> nameAndRole;
		string sample;
		isValidGame();
		stringstream sampleTest(information);
		while(sampleTest >> sample)
			nameAndRole.push_back(sample);
		isValidPlayer(nameAndRole[0]);
		assignJob(nameAndRole[0], nameAndRole[1]);
	}
	catch(NoGameError& ex) {
		ex.what();
	}
	catch(NotAPlayerError& ex) {
		ex.what();
	}
}

void Game::isValidGame() {
	if(!isStarted)
		throw NoGameError(NOGAME);
}

void Game::isValidPlayer(string userName) {
	int numberOfChecks = 0;
	for(int i = 0; i < userNames.size(); i++) {
		if(userNames[i] != userName)
			numberOfChecks ++;
		else
			break;
	}
	if(numberOfChecks == numberOfPlayers) {
		throw NotAPlayerError(NOTAPLAYER);
	}
}

string Game::isAssignedRole(string name) {
	int numberOfChecks = 0;
	for(int i = 0; i < people.size(); i++) {
		if(name == people[i]->getUsername())
			return name;
	}
	return NOTASSIGNED;
}

void Game::changeRole(string name, string role) {
	for(int i = 0; i < people.size(); i++) {
		if(people[i]->getUsername() == name) {
			people.erase(people.begin() + i);
			assignJob(name, role);
		}
	}
}

void Game::assignJob(string name, string role) {
	if(isAssignedRole(name) == NOTASSIGNED) {
		if(role == VILLAGER) {
			Villager *villager = new Villager(name, role);
			people.push_back(villager);
			numberOfGoodPlayers ++;
		}
		else if(role == JOKER) {
			Joker *joker = new Joker(name, role);
			people.push_back(joker);
		}
		else if(role == DETECTIVE) {
			Detective *detective = new Detective(name, role);
			people.push_back(detective);
			numberOfGoodPlayers ++;
		}
		else if(role == DOCTOR) {
			Doctor *docotr = new Doctor(name, role);
			people.push_back(docotr);
			numberOfGoodPlayers ++;
		}
		else if(role == BULLETPROOF) {
			Bulletproof *bulletproof = new Bulletproof(name, role);
			people.push_back(bulletproof);
			numberOfGoodPlayers ++;
		}
		else if(role == MAFIA) {
			Mafia *mafia = new Mafia(name, role);
			people.push_back(mafia);
			numberOfBadPlayers ++;
		}
		else if(role == GODFATHER) {
			Godfather *godfather = new Godfather(name, role);
			people.push_back(godfather);
			numberOfBadPlayers ++;
		}
		else if(role == SILENCER) {
			Silencer *silencer = new Silencer(name, role);
			people.push_back(silencer);
			numberOfBadPlayers ++;
		}
	}
	else
		changeRole(name, role);
}

void Game::isAssigningFinish() {
	if(numberOfPlayers != people.size() && numberOfPlayers > 0)
		throw IncompleteRoleError(REMAININGROLES);
}

void Game::isMiddleOfGame() {
	if(readyOrStart)
		throw CompleteRoleError(VALIDGAME);
}

string Game::showStartingInformation() {
	string information;
	for(int i = 0; i < userNames.size(); i++) {
		for(int j = 0; j < people.size(); j++) {
			if(userNames[i] == people[j]->getUsername()) {
				information += people[j]->toString();
			}
		}
	}
	return information;
}

void Game::isPlayerSilenced(string voterName) {
	Person* person = findPerson(voterName);
	if(person->isPlayerSilenced())
		throw SilencedPlayerError(SILENCEDPLAYER);
}

void Game::isPlayerDead(string voteeName) {
	Person* person = findPerson(voteeName);
	if(!(person->isPlayerAlive()))
		throw DeadPlayerError(DEADPLAYER);
}

Person* Game::findPerson(string name) {
	Person* person;
	for(int i = 0; i < people.size(); i++)
		if(people[i]->getUsername() == name)
			person = people[i];
	return person;
}

void Game::saveVote(string voterName, string voteeName) {
	Person* voter = findPerson(voterName);
	Person* votee = findPerson(voteeName);
	voter->setVote(votee);
	votee->countNumberOfVotes();
}

string Game::findSmallestName() {
	string min = "";
	for(int i = 0; i < people.size(); i++) {
		for(int j = i + 1; j < people.size(); j++) {
			if(people[i]->getUsername() < people[j]->getUsername())
				min = people[i]->getUsername();
			else
				min = people[j]->getUsername();
		}
	}
	return min;
}

void Game::showNightInformation() {
	for(int i = 0; i < userNames.size(); i++) {
		for(int j = 0; j < people.size(); j++) {
			if(userNames[i] == people[j]->getUsername())
				people[j]->showNightRoleOrNot();
		}
	}
}

void Game::isPlayerSleepy(string doer) {
	Person* person = findPerson(doer);
	if(person->isPlayerSleepy())
		throw SleepyPlayerError(SLEEPYPLAYER);
}

void Game::isDoerDead(string doer) {
	Person* person = findPerson(doer);
	if(!(person->isPlayerAlive()))
		throw DeadPlayerError(DEADDOER);
}

void Game::printSilents(vector<string> silents) {
	cout << SILENTS;
	for(int i = 0; i < silents.size(); i++) 
		cout << SPACE << silents[i];
	cout << endl;
}

void Game::showSilencedPeople() {
	vector<string> silents;
	for(int i = 0; i < people.size(); i++) {
		if(people[i]->isPlayerSilenced())
			silents.push_back(people[i]->getUsername());
	}
	if(silents.size() > 0){
		sort(silents.begin(),silents.end());
		printSilents(silents);
	}
}

void Game::showFinalNightResult(Person* wantToDie) {
	int whatToDo = wantToDie->die();
	if(!(wantToDie->isPlayerAlive())) {
		if(whatToDo)
			numberOfGoodPlayers --;
		else
			numberOfBadPlayers --;
		cout << wantToDie->getUsername() << KILLEDATNIGHT << endl;
	}
	showSilencedPeople();
}

void Game::showNightResult() {
	int max = 0;
	Person* died;
	vector<Person*> canDie;
	for(int i = 0; i < people.size(); i++)
		if(max <= people[i]->getNumberOfNightVotes())
			max = people[i]->getNumberOfNightVotes();
	for(int i = 0; i < people.size(); i++)
		if(people[i]->getNumberOfNightVotes() == max)
			canDie.push_back(people[i]);
	if(canDie.size() == 1)
		died = canDie[0];
	else
		died = findPerson(findSmallestName());
	cout << MAFIAKILLED << died->getUsername() << endl;
	plusDay(died);
}

void Game::doNightOrders() {
	middleNight = true;
	string lastOrder, doer, doing;
	while(true) {
		try{
			cin >> lastOrder;
			if(lastOrder == ENDNIGHT) {
				middleNight = false;
				break;
			}
			if(lastOrder == SWAPCHARACTER)
				swapCharacter();
			doer = lastOrder;
			cin >> doing;
			isValidPlayer(doer);
			isValidPlayer(doing);
			isPlayerSleepy(doer);
			isDoerDead(doer);
			Person* doerPlayer = findPerson(doer);
			Person* doingPlayer = findPerson(doing);
			doerPlayer->doJob(doingPlayer);
		}
		catch(SleepyPlayerError& ex) {
			ex.what();
		}
		catch(DeadPlayerError& ex) {
			ex.what();
		}
		catch(NotAPlayerError& ex) {
			ex.what();
		}
		catch(AskedDetectiveError& ex) {
			ex.what();
		}
		catch(HealedDoctorError& ex) {
			ex.what();
		}
		catch(RepeatSwapError& ex) {
			ex.what();
		}
		catch(DaySwapError& ex) {
			ex.what();
		}
		catch(NightSwapError& ex) {
			ex.what();
		}
	}
}

void Game::startNight(Person* died) {
	try {
		middleNight = true;
		int whatToDo = findPerson(died->getUsername())->die();
		if(whatToDo)
			numberOfGoodPlayers --;
		else
			numberOfBadPlayers --;
		night++;
		cout << NIGHT << night << endl;
	}
	catch(JokerWonError& ex) {
		ex.what();
	}
}


void Game::decideToKill(vector<Person*> canDie) {
	Person* died;
	if(canDie.size() == 1)
		died = canDie[0];
	else
		died = findPerson(findSmallestName());
	cout << died->getUsername() << DIED << endl;
	startNight(died);
}

void Game::killSomeOne() {
	int max = 0;
	vector<Person*> canDie;
	for(int i = 0; i < people.size(); i++)
		if(max <= people[i]->getNumberOfVotes())
			max = people[i]->getNumberOfVotes();
	for(int i = 0; i < people.size(); i++)
		if(people[i]->getNumberOfVotes() == max)
			canDie.push_back(people[i]);
	decideToKill(canDie);
}

void Game::getVotes() {
	string lastOrder, voterName, voteeName;
	while(true) {
		cin >> lastOrder;
		if(lastOrder == ENDVOTE) {
			middleDay = false;
			break;
		}
		if(lastOrder == SWAPCHARACTER)
			swapCharacter();
		voterName = lastOrder;
		cin >> voteeName;
		isSwap = true;
		middleDay = true;
		try {
			isValidPlayer(voterName);
			isValidPlayer(voteeName);
			isPlayerSilenced(voterName);
			isPlayerDead(voteeName);
			saveVote(voterName, voteeName);
		}
		catch(NotAPlayerError& ex) {
			ex.what();
		}
		catch(SilencedPlayerError& ex) {
			ex.what();
		}
		catch(DeadPlayerError& ex) {
			ex.what();
		}
	}
}

void Game::plusDay(Person* died) {
	day ++;
	cout << DAY << day << endl;
	showFinalNightResult(died);
	getVotes();
	killSomeOne();
	showNightInformation();
	doNightOrders();
	showNightResult();
}

void Game::checkToStart() {
	try {			
		isValidGame();
		isAssigningFinish();
		isMiddleOfGame();
		readyOrStart = true;
		day ++;
		cout << showStartingInformation() << STARTMESSAGE << endl << DAY << day << endl; 
		getVotes();
		killSomeOne();
		showNightInformation();
		doNightOrders();
		showNightResult();
	}
	catch(IncompleteRoleError& ex) {
		ex.what();
	}
	catch(NoGameError& ex) {
		ex.what();
	}
	catch(CompleteRoleError& ex) {
		ex.what();
	}
}

void Game::repeatSwap() {
	if(isSwap)
		throw RepeatSwapError(REPEATSWAP);
}

void Game::checkDay() {
	if(middleDay)
		throw DaySwapError(DAYSWAPERROR);
}

void Game::checkNight() {
	if(middleNight)
		throw NightSwapError(NIGHTSWAPERROR);
}

void Game::doSwap(string playerOne, string playerTwo) {
	Person* firstPlayer = findPerson(playerOne);
	Person* secondPlayer = findPerson(playerTwo);
	Person* temp = firstPlayer;
	firstPlayer = secondPlayer;
	secondPlayer = temp;
	firstPlayer->changeUsername(playerOne);
	secondPlayer->changeUsername(playerTwo);

}

void Game::swapCharacter() {
	string playerOne, playerTwo;
	cin >> playerOne >> playerTwo;
	isValidPlayer(playerOne);
	isValidPlayer(playerTwo);
	isDoerDead(playerOne);
	isDoerDead(playerTwo);
	checkDay();
	checkNight();
	repeatSwap();
	doSwap(playerOne, playerTwo);
	isSwap = true;
}

void Game::getGameState() {
	cout << MAFIAS << numberOfBadPlayers << endl << VILLAGERS << numberOfGoodPlayers << endl;
}

bool Game::isFinish() {
	if(numberOfGoodPlayers <= numberOfBadPlayers)
		return true;
	else if(numberOfBadPlayers == 0)
		return true;
	else
		return false;
}


















