#ifndef HEALEDDOCTORERROR_H
#define HEALEDDOCTORERROR_H

#include <iostream>

using namespace std;

class HealedDoctorError : public std::exception {
public:
	HealedDoctorError(string err) {
		error = err;
}

	void what() {
		cout << error << endl;
}
private:
	std::string error;
};

#endif

