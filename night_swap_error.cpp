#ifndef NIGHTSWAPERROR_H
#define NIGHTSWAPERROR_H

#include <iostream>

using namespace std;

class NightSwapError : public std::exception {
public:
	NightSwapError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	std::string error;
};

#endif

