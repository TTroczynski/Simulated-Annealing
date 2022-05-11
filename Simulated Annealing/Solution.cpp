#include "Solution.h"

Solution::Solution() {
	x = rand() % 10 - 5;
	y = rand() % 10 - 5;
}
Solution::Solution(double x, double y) {
	this->x = x;
	this->y = y;
}
std::string Solution::toString() const {
	std::ostringstream stream;
	stream << "x = " << x << " y = " << y << " z = " << value() << std::endl;
	return stream.str();
}
double Solution::value() const {
	return pow((x * x) + y - 11, 2) + pow(x + (y * y) - 7, 2);
}
Solution Solution::randomWalk(double maxStep) const {
	std::cout << "Random walk " << this->toString() << std::endl;

	double step = rand() % (2 * (int)maxStep * 1000) / (double)1000;
	step = step - maxStep;

	double newX = x + step;
	double newY = y + step;

	Solution newSolution(newX, newY);
	return newSolution;
}
