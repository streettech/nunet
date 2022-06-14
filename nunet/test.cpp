#include <iostream>

#include "matrix.h"

int main() {

	double** b = new double* [] {
		new double[] {2, 3, 0.5}
	};

	VectorRow v(b, 3);

	std::cout << v;

	return 0;
}