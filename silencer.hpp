#ifndef SILENCER_H
#define SILENCER_H

#include <iostream>
#include "person.hpp"
#include "bad_guys.hpp"

using namespace std;

class Silencer : public BadGuys {
public:
	Silencer(string username, string role);
	virtual bool isPlayerSleepy();
	virtual void doJob(Person* votee);
private:
	bool silenceDone;
};

#endif
