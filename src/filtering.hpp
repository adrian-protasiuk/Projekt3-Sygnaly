#pragma once
#include <vector>

std::vector<double> low_pass_filter(const std::vector<double>& signal, double cutoff_freq, double sampling_rate);
std::vector<std::vector<double>> filter_2d(const std::vector<std::vector<double>>& image, const std::vector<std::vector<double>>& kernel);
