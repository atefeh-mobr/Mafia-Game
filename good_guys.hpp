#ifndef GOODGUYS_H
#define GOODGUYS_H

#include <iostream>
#include "person.hpp"

using namespace std;

class GoodGuys : public Person {
public:
	GoodGuys(string username, string role);
	virtual int die();
	virtual void showNightRoleOrNot() = 0;
	virtual bool isPlayerSleepy() = 0;
	virtual void doJob(Person* votee) = 0;
};

#endif
