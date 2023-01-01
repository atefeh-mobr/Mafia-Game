#include <iostream>
#include "mafia.hpp"
#include "bad_guys.hpp"

using namespace std;

Mafia::Mafia(string username, string role)
				: BadGuys(username, role) {
	roleNight = true;
	answerToDetective = true;
}

bool Mafia::isPlayerSleepy() {
	return false;
}




