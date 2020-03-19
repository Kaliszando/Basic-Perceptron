#pragma once
#include <vector>
#include <ctime>
#include <string>
#include "gnuplot_utils.h"

class Neuron {
private:
	float step_rate = 0.2;
	std::vector<float> weights;

public:
	Neuron(int size) {
		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			weights.push_back((float)rand() / RAND_MAX * 2 - 1);
		}
	}

	int calculate_inputs(std::vector<int> inputs) {
		// Sumator
		float sum = 0;
		for (int i = 0; i < weights.size(); i++) {
			sum += weights[i] * inputs[i];
		}

		// Activation function
		if (sum >= 0) return 1;
		else return 0;
	}

	void train(std::vector<int> inputs, float d) {
		int y = calculate_inputs(inputs);
		if (y == d) return;

		for (int i = 0; i < weights.size(); i++) {
			weights[i] = weights[i] + (d - y) * inputs[i] * step_rate;
		}
	}

	std::string weightsToString() {
		std::string str = "";
		for (auto w : weights) {
			str += std::to_string(w) + " ";
		}
		return str + "\n";
	}

	void plot_line() {
		float A = weights[0];
		float B = weights[1];
		float C = weights[2];
		gp.set_style("lines");
		gp.plot_equation(std::to_string(-A / B) + "* x +" + std::to_string(-C / B));
	}
};

