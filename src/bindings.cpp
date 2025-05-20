#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>

#include "signal_processing.hpp"
#include "fourier.hpp"
#include "filtering.hpp"
#include "generator.hpp"
#include "peak_detection.hpp"
#include "energy.hpp"
#include "visualization.hpp"

namespace py = pybind11;

PYBIND11_MODULE(scikit_build_example, m) {
	m.doc() = "Signal processing module - grupa 7";

	m.def("low_pass_filter_1d", &low_pass_filter_1d, "Simple 1D low-pass filter", py::arg("signal"), py::arg("window_size"));
	m.def("remove_high_frequencies", &remove_high_frequencies, "Remove high frequencies", py::arg("signal"), py::arg("threshold_ratio"));

	m.def("dft", &dft, "Discrete Fourier Transform");
	m.def("idft", &idft, "Inverse Discrete Fourier Transform");

	m.def("low_pass_filter", &low_pass_filter, "Low-pass filter",
	  py::arg("signal"), py::arg("cutoff_frequency"), py::arg("sampling_rate"));

	m.def("filter_2d", &filter_2d, "2D convolution filter",
		  py::arg("image"), py::arg("kernel"));

	m.def("generate_sine", &generate_sine);
	m.def("generate_cosine", &generate_cosine);
	m.def("generate_square", &generate_square);
	m.def("generate_sawtooth", &generate_sawtooth);

	m.def("detect_peaks", &detect_peaks,
	"Detect peaks in a signal above a given threshold",
	py::arg("signal"), py::arg("threshold"));

	m.def("compute_energy", &compute_energy,
	"Compute the energy of a signal",
	py::arg("signal"));

	m.def("plot_signal", &plot_signal, "Plot a 1D signal",
	  py::arg("signal"), py::arg("title") = "Signal");

}
