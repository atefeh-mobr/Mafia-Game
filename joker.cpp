#include <iostream>
#include "joker.hpp"
#include "person.hpp"
#include "joker_won_error.cpp"

using namespace std;

const string JOKERWON = "Joker won";


Joker::Joker(string username, string role)
				: Person(username, role) {
	roleNight = false;
	answerToDetective = false;
}

int Joker::die() {
	alive = false;
	throw JokerWonError(JOKERWON);
	return 0;
}

void Joker::showNightRoleOrNot() {}

bool Joker::isPlayerSleepy() {
	return true;
}

void Joker::doJob(Person* votee) {}




