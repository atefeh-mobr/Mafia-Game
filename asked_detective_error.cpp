#ifndef ASKEDDETECTIVEERROR_H
#define ASKEDDETECTIVEERROR_H

#include <iostream>

using namespace std;

class AskedDetectiveError : public exception {
public:
	AskedDetectiveError(string err) {
	error = err;
}
	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif
