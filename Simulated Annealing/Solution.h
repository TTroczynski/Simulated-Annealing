#pragma once
#include <string>
#include <sstream>
#include <iostream>

class Solution
{
public:
	Solution();
	Solution(double x, double y);
	std::string toString() const;
	double value() const;
	Solution randomWalk(double maxStep) const;

private:

	double x;
	double y;
};

