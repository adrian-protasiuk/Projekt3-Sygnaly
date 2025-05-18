#define _USE_MATH_DEFINES
#include <cmath>

#include "filtering.hpp"
#include <cmath>

std::vector<double> low_pass_filter(const std::vector<double>& signal, double cutoff_freq, double sampling_rate) {
	std::vector<double> output(signal.size());
	double rc = 1.0 / (2.0 * M_PI * cutoff_freq);
	double dt = 1.0 / sampling_rate;
	double alpha = dt / (rc + dt);
	output[0] = signal[0];
	for (size_t i = 1; i < signal.size(); ++i) {
		output[i] = output[i - 1] + alpha * (signal[i] - output[i - 1]);
	}
	return output;
}

std::vector<std::vector<double>> filter_2d(const std::vector<std::vector<double>>& image, const std::vector<std::vector<double>>& kernel) {
	int rows = image.size();
	int cols = image[0].size();
	int k_rows = kernel.size();
	int k_cols = kernel[0].size();
	int k_center_y = k_rows / 2;
	int k_center_x = k_cols / 2;

	std::vector<std::vector<double>> output(rows, std::vector<double>(cols, 0.0));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			double sum = 0.0;
			for (int m = 0; m < k_rows; ++m) {
				for (int n = 0; n < k_cols; ++n) {
					int x = j + n - k_center_x;
					int y = i + m - k_center_y;
					if (x >= 0 && x < cols && y >= 0 && y < rows) {
						sum += image[y][x] * kernel[m][n];
					}
				}
			}
			output[i][j] = sum;
		}
	}

	return output;
}
