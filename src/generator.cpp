#define _USE_MATH_DEFINES
#include "generator.hpp"
#include <cmath>

std::vector<double> generate_sine(int length, double frequency, double sampling_rate) {
	std::vector<double> signal(length);
	for(int i = 0; i < length; ++i) {
		signal[i] = sin(2 * M_PI * frequency * i / sampling_rate);
	}
	return signal;
}

std::vector<double> generate_cosine(int length, double frequency, double sampling_rate) {
	std::vector<double> signal(length);
	for (int i = 0; i < length; ++i) {
		signal[i] = cos(2 * M_PI * frequency * i / sampling_rate);
	}
	return signal;
}

std::vector<double> generate_square(int length, double frequency, double sampling_rate) {
	std::vector<double> signal(length);
	for (int i = 0; i < length; ++i) {
		double t = static_cast<double>(i) / sampling_rate;
		signal[i] = sin(2 * M_PI * frequency * t) >= 0 ? 1.0 : -1.0;
	}
	return signal;
}

std::vector<double> generate_sawtooth(int length, double frequency, double sampling_rate) {
	std::vector<double> signal(length);
	for (int i = 0; i < length; ++i) {
		double t = static_cast<double>(i) / sampling_rate;
		signal[i] = 2.0 * (t * frequency - floor(t * frequency + 0.5));
	}
	return signal;
}
