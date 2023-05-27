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

// Return a new MultiLayerPerceptron object with the specified parameters.
MultiLayerPerceptron::MultiLayerPerceptron(vector<int> layers, double bias, double eta) {
	this->layers = layers;
	this->bias = bias;
	this->eta = eta;

	for (int i = 0; i < layers.size(); i++) {
		values.push_back(vector<double>(layers[i], 0.0));
		network.push_back(vector<Perceptron>());
		if (i > 0) // network[0] is the input layer, so it has no neurons.
			for (int j = 0; j < layers[i]; j++)
				network[i].push_back(Perceptron(layers[i - 1], bias));
	}
}

// w_init has following structure
//  |
//  |--layer
//       |
//       |--Perceptron
//              |
//              |--W0
//              |--W1
//              |--W2
//     
void MultiLayerPerceptron::set_weights(vector<vector<vector<double> > > w_init) {
	// Loop through one layer at a time.
	for (int i = 0; i < w_init.size(); i++) {
		// Loop through one perceptron at a time.
		for (int j = 0; j < w_init[i].size(); j++) {
			// Specify weights for this perceptron.
			network[i+1][j].set_weights(w_init[i][j]);
		}
	}
}

// Outputs weights for testing purposes.
void MultiLayerPerceptron::print_weights() {
	cout << endl;
	for (int i = 1; i < network.size(); i++) {
		for (int j = 0; j < layers[i]; j++) {
			cout << "Layer " << i + 1 << " Neuron " << j << ": ";
			for (auto &it: network[i][j].weights)
				cout << it << "   ";
			cout << endl;
		}
	}
}

vector<double> MultiLayerPerceptron::run(vector<double> x) {
	values[0] = x;
	for (int i = 1; i < network.size(); i++) {
		for (int j = 0; j < layers[i]; j++) {
			values[i][j] = network[i][j].run(values[i - 1]);
		}
	}
	return values.back();
}