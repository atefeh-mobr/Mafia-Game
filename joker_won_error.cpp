#ifndef JOKERWONERROR_H
#define JOKERWONERROR_H

#include <iostream>

using namespace std;

class JokerWonError : public exception {
public:
	JokerWonError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

