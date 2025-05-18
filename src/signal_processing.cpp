#include "signal_processing.hpp"
#include "fourier.hpp"

std::vector<double> low_pass_filter_1d(const std::vector<double>& signal, int window_size) {
	std::vector<double> filtered(signal.size(), 0.0);
	int half = window_size / 2;
	for (size_t i = 0; i < signal.size(); ++i) {
		double sum = 0.0;
		int count = 0;
		for (int j = -half; j <= half; ++j) {
			int idx = i + j;
			if (idx >= 0 && idx < signal.size()) {
				sum += signal[idx];
				count++;
			}
		}
		filtered[i] = sum / count;
	}
	return filtered;
}

std::vector<double> remove_high_frequencies(const std::vector<double>& signal, double threshold_ratio) {
	auto freq = dft(signal);
	size_t N = freq.size();
	size_t threshold = static_cast<size_t>(threshold_ratio * N);
	for (size_t i = threshold; i < N - threshold; ++i) {
		freq[i] = 0.0;
	}
	return idft(freq);
}
