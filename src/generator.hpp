#pragma once
#include <vector>

std::vector<double> generate_sine(int length, double frequency, double sampling_rate);
std::vector<double> generate_cosine(int length, double frequency, double sampling_rate);
std::vector<double> generate_square(int length, double frequency, double sampling_rate);
std::vector<double> generate_sawtooth(int length, double frequency, double sampling_rate);
