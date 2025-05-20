#include "visualization.hpp"
#include <matplot/matplot.h>

void plot_signal(const std::vector<double>& signal, const std::string& plot_title) {
	using namespace matplot;
	plot(signal);
	title(plot_title);
	show();
}
