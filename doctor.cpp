#include <iostream>
#include "doctor.hpp"
#include "healed_doctor_error.cpp"
#include "dead_player_error.cpp"

using namespace std;

const string SPACE = ": ";
const string DEADPATIENT = "Patient is dead";
const string HEALEDDOCTOR = "Doctor has alrady healed";


Doctor::Doctor(string username, string role)
				: GoodGuys(username, role) {
	roleNight = true;
	healDone = false;
}

void Doctor::showNightRoleOrNot() {
	if(alive)
		cout << username << SPACE << role << endl;
}

bool Doctor::isPlayerSleepy() {
	return false;
}

void Doctor::doJob(Person* healedPerson) {
	if(healDone)
		throw HealedDoctorError(HEALEDDOCTOR);
	if(!(healedPerson->isPlayerAlive()))
		throw DeadPlayerError(DEADPATIENT);
	if(!(healedPerson->getHealedSituation())) {
		healedPerson->doHeal();
		healDone = true;
	}
}


