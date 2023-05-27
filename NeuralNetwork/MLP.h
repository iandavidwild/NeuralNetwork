#pragma once
#include <algorithm>
#include <vector>
#include <iostream>
#include <random>
#include <numeric>
#include <cmath>
#include <time.h>

using namespace std;

class Perceptron {
	public:
		vector<double> weights;
		double bias;
		Perceptron(int inputs, double bias = 1.0);
		double run(vector<double> x);
		void set_weights(vector<double> w_init);
		double sigmoid(double x);
};

class MultiLayerPerceptron {
	public:
		MultiLayerPerceptron(vector<int> layers, double bias = 1.0, double eta = 0.5);
		void set_weights(vector<vector<vector<double>>> w_init);
		void print_weights();
		vector<double> run(vector<double> x);
		double bp(vector<double> x, vector<double> y);

		vector<int> layers; // Represents number of neutrons per layer.
		double bias;
		double eta; // Learning rate.
		vector<vector<Perceptron> > network;
		vector<vector<double> > values; // Holds output values of neurons.
		vector<vector<double> > d; // Holds error terms of the neurons.
};