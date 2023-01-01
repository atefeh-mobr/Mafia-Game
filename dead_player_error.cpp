#ifndef DEADPLAYERERROR_H
#define DEADPLAYERERROR_H

#include <iostream>

using namespace std;

class DeadPlayerError : public exception {
public:
	DeadPlayerError(string err) {
	error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

