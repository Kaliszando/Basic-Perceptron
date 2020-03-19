#include "Neuron.h"
#include "gnuplot_utils.h"

int main() {
	std::ifstream file;
	file.open("data.txt");
	if (!file.good()) {
		std::cout << "File error" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::vector<Point> data;
	data.reserve(100);

	int x, y, label;

	for (int i = 0; i < 100; i++) {
		file >> x >> y >> label;
		data.push_back(Point(x, y, label));
	}
	file.close();

	draw_graph(-5, 5, 100);
	draw_set_of_points(data);

	Neuron n(3);

	std::cout << n.weightsToString();
	n.plot_line();

	std::vector<int> inputs;
	inputs.resize(3);
	int epoch = 4;
	for (int j = 0; j < epoch; j++) {
		for (int i = 0; i < data.size(); i++) {
			inputs[0] = data[i].x;
			inputs[1] = data[i].y;
			inputs[2] = data[i].bias;
			n.train(inputs, data[i].label);
		}

		if (j == 2) {
			std::cout << n.weightsToString();
			n.plot_line();
		}
	}

	std::cout << n.weightsToString();
	n.plot_line();

	system("PAUSE");
	gp.remove_tmpfiles();
	return EXIT_SUCCESS;
}

