#ifndef DETECTIVE_H
#define DETECTIVE_H

#include <iostream>
#include "good_guys.hpp"

using namespace std;

class Detective : public GoodGuys {
public:
	Detective(string username, string role);
	virtual void doJob(Person* suspectedPerson);
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy();
private:
	bool isAsked;
};

#endif

