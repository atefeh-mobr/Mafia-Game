#ifndef SLEEPYPLAYERERROR_H
#define SLEEPYPLAYERERROR_H

#include <iostream>

using namespace std;

class SleepyPlayerError : public exception {
public:
	SleepyPlayerError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

