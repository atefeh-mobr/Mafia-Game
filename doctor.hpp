#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "good_guys.hpp"

using namespace std;

class Doctor : public GoodGuys {
public:
	Doctor(string username, string role);
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy();
	virtual void doJob(Person* healedPerson);
private:
	bool healDone;
};

#endif
