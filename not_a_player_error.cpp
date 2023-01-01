#ifndef NOTAPLAYERERROR_H
#define NOTAPLAYERERROR_H

#include <iostream>

using namespace std;

class NotAPlayerError : public exception {
public:
	NotAPlayerError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

