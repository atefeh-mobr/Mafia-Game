#ifndef PERSON_H
#define PERSON_H

#include <iostream>

using namespace std;

class Person {
public:
	Person(string name, string roleName);
	void changeRole(string roleName);
	string toString();
	string getUsername();
	bool isPlayerSilenced();
	bool isPlayerAlive();
	void setVote(Person* voteePerson);
	Person* getVotee();
	void countNumberOfVotes();
	void countNightVotes();
	void deleteOneVote();
	void deleteOneNightVote();
	int getNumberOfVotes();
	int getNumberOfNightVotes();
	void silencePerson();
	void makeSpeakPerson();
	bool getDetectiveAnswer();
	bool getHealedSituation();
	bool isValidBulletproof();
	void doHeal();
	void useSecondLife();
	void changeUsername(string newUsername);
	virtual int die() = 0;
	virtual void showNightRoleOrNot() = 0;
	virtual bool isPlayerSleepy() = 0;
	virtual void doJob(Person* doing) = 0;
protected:
	string username;
	string role;
	int numberOfvoted;
	int numberOfNightVotes;
	bool alive;
	bool silenced;
	bool roleNight;
	bool answerToDetective;
	bool isHealed;
	bool isBulletproof;
	Person* votee;
	Person* nightVotee;
};

#endif