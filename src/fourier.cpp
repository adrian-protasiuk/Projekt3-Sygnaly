#define _USE_MATH_DEFINES

#include "fourier.hpp"
#include <complex>
#include <vector>
#include <cmath>

std::vector<std::complex<double>> dft(const std::vector<double>& signal) {
	size_t N = signal.size();
	std::vector<std::complex<double>> result(N);
	for (size_t k = 0; k < N; ++k) {
		std::complex<double> sum(0.0, 0.0);
		for (size_t n = 0; n < N; ++n) {
			double angle = -2 * M_PI * k * n / N;
			sum += signal[n] * std::complex<double>(cos(angle), sin(angle));
		}
		result[k] = sum;
	}
	return result;
}

std::vector<double> idft(const std::vector<std::complex<double>>& freq) {
	size_t N = freq.size();
	std::vector<double> result(N);
	for (size_t n = 0; n < N; ++n) {
		std::complex<double> sum(0.0, 0.0);
		for (size_t k = 0; k < N; ++k) {
			double angle = 2 * M_PI * k * n / N;
			sum += freq[k] * std::complex<double>(cos(angle), sin(angle));
		}
		result[n] = sum.real() / N;
	}
	return result;
}
