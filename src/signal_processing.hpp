#pragma once
#include <vector>

// Przefiltruj 1D sygnał za pomocą prostej maski średniej ruchomej
std::vector<double> low_pass_filter_1d(const std::vector<double>& signal, int window_size);

// Usuń wysokie częstotliwości z sygnału
std::vector<double> remove_high_frequencies(const std::vector<double>& signal, double threshold_ratio);
