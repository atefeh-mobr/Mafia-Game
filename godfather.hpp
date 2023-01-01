#ifndef GODFATHER_H
#define GODFATHER_H

#include <iostream>
#include "bad_guys.hpp"

using namespace std;

class Godfather : public BadGuys {
public:
	Godfather(string username, string role);
	virtual bool isPlayerSleepy();
private:
};

#endif

