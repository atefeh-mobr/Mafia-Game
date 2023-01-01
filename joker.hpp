#ifndef JOKER_H
#define JOKER_H

#include <iostream>
#include "person.hpp"

using namespace std;

class Joker : public Person {
public:
	Joker(string username, string role);
	virtual int die();
	virtual void showNightRoleOrNot();
	virtual bool isPlayerSleepy();
	virtual void doJob(Person* votee);
private:
};

#endif