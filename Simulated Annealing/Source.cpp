//not population based like other optimization algorithms
//It is trajectory based
//Annealing - process of heat treating steel by heating to a specific temperature and cooling at controlled rate to achieve
//desired characteristics

//Simulated Annealing:
// 
// start:
//Random first solution - starting from an initial high temperature
// 
// loop:
//Pick a better neighboring solution.
//otherwise, with a certain probability, choose a random solution                    probability: 1/(Fpossible - Fcurrent)/Tcurrent
//go to loop (N times - for N neighbors)
// 
//decrease the temperature
//Go to start (M times - for M temperatures)

//the probability of choosing worst solutions is high to start. The probability of selecting
//worst solutions decreases over time.


//similar to hill climb
//difference is that there are random pushes that push us out of a global maximum or minimum
//if enough randomness is used with a slow cooling rate, the probability of finding a global maximum increases.

//This program...
//finds one of the 4 minimum points of the Himmelblau's function.

#include "SimulatedAnnealing.h"
#include <ctime>

int main(void) {
	double initialTemperature = 100;
	unsigned timesToDecreaseTemperature = 100;
	double step = 1;
	unsigned neighbors = 10;
	double decreaseAmount = 0.85;
	
	srand(time(NULL));

	SimulatedAnnealing sa(initialTemperature, timesToDecreaseTemperature, step, neighbors, decreaseAmount);

	Solution best = sa.run();

	std::cout << "Best Solution: " << best.toString() << std::endl;
	

	return 0;
}