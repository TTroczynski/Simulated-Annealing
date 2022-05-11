#include "SimulatedAnnealing.h"

SimulatedAnnealing::SimulatedAnnealing(double initialTemperature, unsigned timesToDecreaseTemperature, double step, unsigned neighbors, double decreaseAmount):
	kInitialTemperature{ initialTemperature }, kTimesToDecreaseTemperature{ timesToDecreaseTemperature }, kStep{ step }, kNeighbors{ neighbors }, kDecreaseAmount{ decreaseAmount }
{
	yes = 0;
	no = 0;
	probTemp = 0;
}

Solution SimulatedAnnealing::run()
{
	Solution currentSolution;

	std::ofstream csv("results.csv", std::ofstream::out);

	double currentTemperature = kInitialTemperature;

	for (unsigned i = 0; i < kTimesToDecreaseTemperature; i++) {
		std::cout << "------------------Temperature = " << currentTemperature << std::endl;
		std::cout << "Solution = " << currentSolution.toString() << std::endl;

		for (unsigned j = 0; j < kNeighbors; j++) {
			
			Solution candidate = currentSolution.randomWalk(kStep);
			std::cout << "Candidate = " << candidate.toString() << std::endl;

			if (candidate.value() < currentSolution.value()) {
				std::cout << "Found a better solution" << std::endl;
				currentSolution = candidate;
			}
			else {
				double frac = candidate.value() - currentSolution.value();
				double probability = 1 / exp(frac / currentTemperature);

				std::cout << "New Candidate < current solution. Selection Probability = " << probability << std::endl;
				probTemp = probability;

				double r = (double)(rand() % 1000) / 1000;

				if (r < probability) {
					std::cout << "Taking the worse solution" << std::endl;
					currentSolution = candidate;
					yes++;
				}
				else{
					std::cout << "Taking better solution" << std::endl;
					no++;
				}
			}
		}
		std::cout << " Worse solution? yes: " << yes << " no: " << no << std::endl;
		currentTemperature = currentTemperature * kDecreaseAmount;
		csv << currentSolution.value() << ", " << yes << ", " << no << ", " << probTemp << '\n';
	}
	csv.close();
	return currentSolution;
}
