#ifndef BADGUYS_H
#define BADGUYS_H

#include <iostream>
#include "person.hpp"

using namespace std;

class BadGuys : public Person {
public:
	BadGuys(string username, string role);
	virtual int die();
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy() = 0;
	void doJob(Person* voteePerson);
};

#endif
