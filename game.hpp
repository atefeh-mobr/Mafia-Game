#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include "person.hpp"

using namespace std;

class Game {
public:
	Game();
	Game(int start);
	void createGame(string allNames);
	void assignRole(string information);
	void checkToStart();
	void getGameState();
	bool isFinish();
private:
	int day;
	int night;
	int numberOfPlayers;
	bool isStarted;
	bool readyOrStart;
	bool middleDay;
	bool middleNight;
	bool isSwap;
	int numberOfGoodPlayers;
	int numberOfBadPlayers;
	vector<string> userNames;
	vector<Person*> people;
	Person* findPerson(string name);
	string findSmallestName();
	void showNightInformation();
	void doNightOrders();
	void isPlayerSleepy(string doer);
	void isDoerDead(string doer);
	void showFinalNightResult(Person* wantToDie);
	void showSilencedPeople() ;
	void printSilents(vector<string> silents);
	void showNightResult();
	void swapCharacter();
	void repeatSwap();
	void checkDay();
	void checkNight();
	void doSwap(string playerOne, string playerTwo);
	void findNames(string allNames);
	void isValidGame();
	void isValidPlayer(string userName);
	void assignJob(string name, string role);
	string isAssignedRole(string name);
	void changeRole(string name, string role);
	void isAssigningFinish();
	void isMiddleOfGame();
	string showStartingInformation();
	void getVotes();
	void isPlayerSilenced(string voterName);
	void isPlayerDead(string voteeName);
	void saveVote(string voterName, string voteeName);
	void killSomeOne();
	void decideToKill(vector<Person*> canDie);
	void startNight(Person* died);
	void plusDay(Person* died);
};

#endif