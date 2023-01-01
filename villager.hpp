#ifndef VILLAGER_H
#define VILLAGER_H

#include <iostream>
#include "good_guys.hpp"

using namespace std;

class Villager : public GoodGuys {
public:
	Villager(string username, string role);
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy();
	virtual void doJob(Person* votee);
private:
};

#endif
