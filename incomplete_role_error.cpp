#ifndef INCOMPLETEROLEERROR_H
#define INCOMPLETEROLEERROR_H

#include <iostream>

using namespace std;

class IncompleteRoleError : public exception {
public:
	IncompleteRoleError(string err) {
			error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

