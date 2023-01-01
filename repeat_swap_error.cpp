#ifndef REPEATSWAPERROR_H
#define REPEATSWAPERROR_H

#include <iostream>

using namespace std;

class RepeatSwapError : public exception {
public:
	RepeatSwapError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

