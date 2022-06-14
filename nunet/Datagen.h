#pragma once
#ifndef DATA_GEN_H

#include <time.h>
#include <random>

#include "Util.h"
#include "matrix.h"

class DataGen {
public:
	DataGen();
	DataGen(int points, int classes);
	DataGen(int points, int classes, int seed);
	~DataGen();

	void dataSpiral();
	void linspace(double, double, int);
	VectorRow randGen(int);

private:
	int points,
		classes;
	Matrix X;
	//Vector<int> y;
	VectorRow lincon;  // linspace container
};

#endif // !DATA_GEN_H

