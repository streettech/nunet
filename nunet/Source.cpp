/*
* 
* 
* Project NuNET! 
* 
* A neural net program in dev for drone navigation, maneuverability, and connectivity.
* 
* Aims to assist with drone identification and knowledge of self and position/job within
* hive.
* Aims to assist with drone ability to move unassisted and with purpose towards set 
* goals/check-points.
* Aims to allow drones to formulate and interprete commands.
* Aims to give drones interpretation of and reaction to sensory data.
* 
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "matrix.h"

#define R_LOW -1
#define R_HIGH 1
#define BIASSEED 0

class ActivationReLU {
public:
	void forward(Matrix& data) {
		for (int i = 0; i < data.rows(); i++) {
			for (int j = 0; j < data.cols(); j++) {
				if (data(i, j) <= 0)
					data(i, j) = 0;
			}
		 }
	}
};

class Layer {
public:
	Layer(int n_inputs, int n_neurons) {
		srand(time(0));

		double** w = new double* [n_inputs];
		double** b = new double* [1];

		for (int i = 0; i < n_inputs; i++) {
			w[i] = new double[n_neurons];
			for (int j = 0; j < n_neurons; j++) {
				w[i][j] = R_LOW + static_cast<double>(rand()) * static_cast<double>(R_HIGH - R_LOW) / RAND_MAX;
			}
		}

		b[0] = new double[n_neurons];
		for (int i = 0; i < n_neurons; i++) {
			b[0][i] = BIASSEED;
		}

		this->weights = Matrix(w, n_inputs, n_neurons);
		this->biases = VectorRow(b, n_neurons);
		this->currentOutput = weights;
	}

	void forward(Matrix data) {
		this->currentOutput = data * this->weights + this->biases;
	}

	Matrix ret() {
		return currentOutput;
	}

private:
	Matrix weights;
	VectorRow biases;
	Matrix currentOutput;
};
/*
int main() {
	double** i = new double* [] {
		new double[] { 1, 2, 3, 2.5 },
		new double[] { 2, 5, -1, 2 },
		new double[] { -1.5, 2.7, 3.3, -0.8 }
	};

	Matrix inputs = Matrix(i, 3, 4);

	////////////////////////////////////////////////////////////////////////// ---- object all below

	/*
	// fisrt layer
	double** w = new double* [] {
		new double[] { 0.2, 0.8, -0.5, 1 },
		new double[] { 0.5, -0.91, 0.26, -0.5 },
		new double[] { -0.26, -0.27, 0.17, 0.87 }
	};
	double** b = new double* [] {
		new double[] {2, 3, 0.5}
	};

	///
	Matrix weights = Matrix(w, 3, 4);
	VectorRow biases = VectorRow(b, 3);

	// second layer
	double** w2 = new double* [] {
		new double[] { 0.1, -0.14, 0.5 },
		new double[] { -0.5, 0.12, -0.33 },
		new double[] { -0.44, 0.73, -0.13 }
	};
	double** b2 = new double* [] {
		new double[] {-1, 2, -0.5}
	};

	///
	Matrix weights2 = Matrix(w2, 3, 3);
	VectorRow biases2 = VectorRow(b2, 3);

	Matrix layer_output = inputs * weights.transpose() + biases;
	Matrix layer2_output = layer_output * weights2.transpose() + biases2;

	std::cout << layer2_output << "\n";

	delete[] i, w, w2, b, b2;

	

	Layer testLayer1(4, 5);
	Layer testLayer2(5, 2);

	testLayer1.forward(inputs);
	testLayer2.forward(testLayer1.ret());

	//std::cout << testLayer2.ret() << "\n";

	ActivationReLU test;
	test.forward(inputs);

	std::cout << inputs << "\n";

	return 0;
} */