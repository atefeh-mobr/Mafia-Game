#include <iostream>
#include "good_guys.hpp"
#include "person.hpp"

using namespace std;

GoodGuys::GoodGuys(string username, string role)
				: Person(username, role) {
	answerToDetective = false;
}

int GoodGuys::die() {
	if(!isHealed) {
		if(!isBulletproof)
			alive = false;
		else
			useSecondLife();
	}
	else
		isHealed = false;
	return 1;
}




