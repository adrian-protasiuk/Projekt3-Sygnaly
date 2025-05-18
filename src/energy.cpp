#include "energy.hpp"
#include <cmath>

double compute_energy(const std::vector<double>& signal) {
	double energy = 0.0;
	for (double x : signal) {
		energy += x * x;
	}
	return energy;
}
