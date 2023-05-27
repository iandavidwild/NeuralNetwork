#include "MLP.h"

double frand() {
	return (2.0 * (double)rand() / RAND_MAX) - 1.0;
}

// Return a new Perceptron object with the specified number of inputs (+1 for the bias).
Perceptron::Perceptron(int inputs, double bias) {
	this->bias = bias;
	weights.resize(inputs + 1);
	generate(weights.begin(), weights.end(), frand);
}

// Run the perceptron. x is a vector with the input values.
double Perceptron::run(vector<double> x) {
	x.push_back(bias);
	double sum = inner_product(x.begin(), x.end(), weights.begin(), (double)0.0);
	return sigmoid(sum);
}

// Set the weights. w_init is a vector with the weights.
void Perceptron::set_weights(vector<double> w_init) {
	if (weights.size() != w_init.size()) {
		throw std::invalid_argument("w_init has unexpected size");
	}
	weights = w_init;
}

// Evaluate the sigmoid function for the floating point input x.
double Perceptron::sigmoid(double x) {
	return 1.0 / (1.0 + exp(-x));
}