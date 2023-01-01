#ifndef COMPLETEROLEERROR_H
#define COMPLETEROLEERROR_H

#include <iostream>

using namespace std;

class CompleteRoleError : public exception {
public:
	CompleteRoleError(string err) {
	error = err;
}
	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

