#ifndef BULLETPROOF_H
#define BULLETPROOF_H

#include <iostream>
#include "good_guys.hpp"

using namespace std;

class Bulletproof : public GoodGuys {
public:
	Bulletproof(string username, string role);
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy();
	virtual void doJob(Person* votee);
	void useSecondLife();
private:
	bool canSurvive;
};

#endif

