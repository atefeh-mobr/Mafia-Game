#include <iostream>
#include "godfather.hpp"
#include "bad_guys.hpp"

using namespace std;

Godfather::Godfather(string username, string role)
				: BadGuys(username, role) {
	roleNight = true;
	answerToDetective = false;
}

bool Godfather::isPlayerSleepy() {
	return false;
}



