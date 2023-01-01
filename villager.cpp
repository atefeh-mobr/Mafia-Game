#include <iostream>
#include "villager.hpp"
#include "good_guys.hpp"

using namespace std;

const string SPACE = ": ";

Villager::Villager(string username, string role)
				: GoodGuys(username, role) {
	roleNight = false;
}

void Villager::showNightRoleOrNot() {}

bool Villager::isPlayerSleepy() {
	return true;
}

void Villager::doJob(Person* votee) {}



