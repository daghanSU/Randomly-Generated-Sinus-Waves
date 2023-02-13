#pragma once
#include <iostream>
#define PI  3.14159265358979323846
using namespace std;

class Wave
{
private:
	double amp, period;
	double* phase;
public:
	Wave(double amp,double period,double phase);
	~Wave();

	double f(double x);
	void update();
};

