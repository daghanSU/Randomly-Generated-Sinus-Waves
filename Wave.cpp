#include "Wave.h"

Wave::Wave(double amp, double period, double phase)
{
	this->amp = amp;
	this->period = period;
	this->phase = new double(phase);
}

Wave::~Wave()
{
	
	/*delete phase;*/
}

double Wave::f(double x)
{
	return sin(x * 2 * PI / period + (*phase)) * amp;
}

void Wave::update()
{
	*(this->phase) += 0.07;
}
