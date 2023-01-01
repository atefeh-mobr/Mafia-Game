#include <iostream>
#include <string>
#include <sstream>
#include "person.hpp"

using namespace std;

const string SPACE = ": ";

Person::Person(string name, string roleName) {
	username = name;
	role = roleName;
	numberOfvoted = 0;
	numberOfNightVotes = 0;
	alive = true;
	silenced = false;
	isHealed = false;
	isBulletproof = false;
}

string Person::toString() {
	ostringstream os;
	os << username << SPACE << role << endl;
	return os.str();
}

void Person::changeRole(string roleName) {
	role = roleName;
}

string Person::getUsername() {
	return username;
}

bool Person::isPlayerSilenced() {
	if(silenced)
		return true;
	else 
		return false;
}

bool Person::isPlayerAlive() {
	if(alive)
		return true;
	else
		return false;
}

void Person::setVote(Person* voteePerson){
	if(votee != NULL)
		votee->deleteOneVote();
	votee = voteePerson;
}

Person* Person::getVotee() {
	return votee;
}

void Person::countNumberOfVotes() {
	numberOfvoted++;
}

void Person::deleteOneVote() {
	numberOfvoted--;
}

void Person::countNightVotes() {
	numberOfNightVotes++;
}

void Person::deleteOneNightVote() {
	numberOfNightVotes--;
}

int Person::getNumberOfVotes() {
	return numberOfvoted;
}

int Person::getNumberOfNightVotes() {
	return numberOfNightVotes;
}

void Person::silencePerson() {
	silenced = true;
}

void Person::makeSpeakPerson() {
	silenced = false;
}

bool Person::getDetectiveAnswer() {
	return answerToDetective;
}

bool Person::getHealedSituation() {
	return isHealed;
}

void Person::doHeal() {
	isHealed = true;
}

bool Person::isValidBulletproof() {
	return isBulletproof;
}

void Person::useSecondLife() {}

void Person::changeUsername(string newUsername) {
	username = newUsername;
}




