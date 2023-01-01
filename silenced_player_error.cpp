#ifndef SILENCEDPLAYERERROR_H
#define SILENCEDPLAYERERROR_H

#include <iostream>

using namespace std;

class SilencedPlayerError : public exception {
public:
	SilencedPlayerError(string err) {
		error = err;
}
	
	void what() {
		cout << error << endl;
}
private:
	string error;
};

#endif

