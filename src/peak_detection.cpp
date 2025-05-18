#include "peak_detection.hpp"

std::vector<int> detect_peaks(const std::vector<double>& signal, double threshold) {
	std::vector<int> peaks;
	for (size_t i = 1; i + 1 < signal.size(); ++i) {
		if (signal[i] > signal[i - 1] && signal[i] > signal[i + 1] && signal[i] >= threshold) {
			peaks.push_back(static_cast<int>(i));
		}
	}
	return peaks;
}
