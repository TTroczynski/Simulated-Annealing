#pragma once
#include "Solution.h"
#include <fstream>
#include <sstream>
#include <iostream>

class SimulatedAnnealing
{
public:

	SimulatedAnnealing(double initialTemperature, unsigned timesToDecreaseTemperature, double step, unsigned neighbors, double decreaseAmount);

	Solution run();

private:
	double kInitialTemperature;
	unsigned kTimesToDecreaseTemperature;

	double kStep;
	unsigned kNeighbors;
	double kDecreaseAmount;

	unsigned yes;
	unsigned no;
	double probTemp;

};

