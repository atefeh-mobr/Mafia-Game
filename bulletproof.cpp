#include <iostream>
#include "bulletproof.hpp"
#include "good_guys.hpp"

using namespace std;

const string SPACE = ": ";

Bulletproof::Bulletproof(string username, string role)
				: GoodGuys(username, role) {
	roleNight = false;
	canSurvive = true;
	isBulletproof = true;
}

void Bulletproof::showNightRoleOrNot() {}

bool Bulletproof::isPlayerSleepy() {
	return true;
}

void Bulletproof::doJob(Person* votee) {}

void Bulletproof::useSecondLife() {
	canSurvive = false;
}

