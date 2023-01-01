#include <iostream>
#include "bad_guys.hpp"
#include "person.hpp"
#include "dead_player_error.cpp"

using namespace std;

const string DEADPLAYER = "Votee already dead";
const string SPACE = ": ";

BadGuys::BadGuys(string username, string role)
				: Person(username, role) {}

int BadGuys::die() {
	if(!isHealed)
		alive = false;
	else
		isHealed = false;
	return -1;
}

void BadGuys::showNightRoleOrNot() {
	if(alive)
		cout << username << SPACE << role << endl;
}

void BadGuys::doJob(Person* voteePerson) {
	if(!(voteePerson->isPlayerAlive()))  {
		throw DeadPlayerError(DEADPLAYER);
	}
	if(nightVotee != NULL)
		nightVotee->deleteOneNightVote();
	nightVotee = voteePerson;
	voteePerson->countNightVotes();
}