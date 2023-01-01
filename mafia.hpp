#ifndef MAFIA_H
#define MAFIA_H

#include <iostream>
#include "bad_guys.hpp"

using namespace std;

class Mafia : public BadGuys {
public:
	Mafia(string username, string role);
	virtual bool isPlayerSleepy();
private:
};

#endif
