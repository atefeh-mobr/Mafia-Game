#ifndef DAYSWAPERROR_H
#define DAYSWAPERROR_H

#include <iostream>

using namespace std;

class DaySwapError : public exception {
public:
	DaySwapError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

