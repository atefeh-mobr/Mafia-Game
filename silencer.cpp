#include <iostream>
#include "person.hpp"
#include "silencer.hpp"
#include "bad_guys.hpp"
#include "dead_player_error.cpp"

using namespace std;

const string DEADPERSON = "Person is dead";

Silencer::Silencer(string username, string role)
				: BadGuys(username, role) {
	roleNight = true;
	silenceDone = false;
	answerToDetective = true;
}

bool Silencer::isPlayerSleepy() {
	return false;
}

void Silencer::doJob(Person* votee) {
	if(silenceDone)
		BadGuys::doJob(votee);
	else {
		if(!(votee->isPlayerAlive()))
			throw DeadPlayerError(DEADPERSON);
		votee->silencePerson();
		silenceDone = true;
	}
}


