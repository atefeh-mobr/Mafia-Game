#include <iostream>
#include "detective.hpp"
#include "asked_detective_error.cpp"
#include "dead_player_error.cpp"

using namespace std;

const string DEADSUSPECT = "Suspect is dead";
const string ASKEDDETECTIVE = "Detective has already asked";
const string SPACE = ": ";
const string YES = "Yes";
const string NO = "No";

Detective::Detective(string username, string role)
				: GoodGuys(username, role) {
	roleNight = true;
	isAsked = false;
}

void Detective::showNightRoleOrNot() {
	if(alive)
		cout << username << SPACE << role << endl;
}

bool Detective::isPlayerSleepy() {
	return false;
}

void Detective::doJob(Person* suspectedPerson) {
	if(isAsked)
		throw AskedDetectiveError(ASKEDDETECTIVE);
	if(!(suspectedPerson->isPlayerAlive()))
		throw DeadPlayerError(DEADSUSPECT);
	if(suspectedPerson->getDetectiveAnswer())
	cout << YES << endl;
	else
		cout << NO << endl;
	isAsked = true;
}

