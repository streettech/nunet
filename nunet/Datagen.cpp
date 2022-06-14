#include "Datagen.h"

#define PI 3.1415926535
#define MAX_DER 6
#define MIN_DER 2

DataGen::DataGen() {
	this->points , this->classes = 1;
	srand(time(0));
	this->X = Matrix(points * classes, 2);
}

DataGen::DataGen(int points, int classes) : points(points), classes(classes) {
	srand(time(0));
	this->X = Matrix(points * classes, 2);
}

DataGen::DataGen(int points, int classes, int seed) : points(points), classes(classes) {
	srand(seed);
	this->X = Matrix(points * classes, 2);
}

DataGen::~DataGen() {

}

void DataGen::dataSpiral() {
	for (int i = 0; i < this->classes; i++) {
		for (int j = this->points * i; j < this->points * (i + 1); j++) {
			linspace(0.0, 1, this->points);
			VectorRow r = lincon;
			linspace((double(i)*4), (double(i)+1)*4, this->points);
			VectorRow t = lincon + randGen(this->points);
		}
	}
}

void DataGen::linspace(double start, double end, int len) {
	double temp = (end - start)/(double(len)-1);
	double **temp2 = new double*[1];
	temp2[0] = new double[len];
	int i = 1;
	temp2[0][0] = start;
	while (i < len) {
		temp2[0][i] = temp2[0][i - 1] + temp;
		i++;
	}
	this->lincon = VectorRow(temp2, len);
}

VectorRow DataGen::randGen(int cols) {

	if (cols == 0)
		return VectorRow();

	double** data = new double* [1];
	
	for (int i = 0; i < 1; i++) {
		data[i] = new double[cols];
		std::default_random_engine gen(time(0));
		std::normal_distribution<double> dist(cols / PI, MIN_DER + static_cast<double>(rand()) * static_cast<double>(MAX_DER - MIN_DER) / RAND_MAX);
		for (int j = 0; j < cols; j++) {
			data[i][j] = dist(gen);
		}
	}
	return VectorRow(data, cols);
}