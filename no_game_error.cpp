#ifndef NOGAMEERROR_H
#define NOGAMEERROR_H

#include <iostream>

using namespace std;

class NoGameError : public exception {
public:
	NoGameError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

