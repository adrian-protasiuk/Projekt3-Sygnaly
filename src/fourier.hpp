#pragma once
#include <vector>
#include <complex>

std::vector<std::complex<double>> dft(const std::vector<double>& signal);
std::vector<double> idft(const std::vector<std::complex<double>>& freq);
