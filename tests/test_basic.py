import math
import cmath
import scikit_build_example


def test_hello():
    assert scikit_build_example.hello() == "Hello from C++!"


def test_generate_sine_length_and_values():
    result = scikit_build_example.generate_sine(5, 1.0, 10.0)
    assert isinstance(result, list)
    assert len(result) == 5
    assert all(isinstance(x, float) for x in result)
    assert math.isclose(result[0], 0.0, abs_tol=1e-6)
    # Nie sprawdzamy ostatniego punktu — może nie być zerem, zależy od częstotliwości


def test_dft_and_idft_inverse():
    signal = [0.0, 1.0, 0.0, -1.0]
    spectrum = scikit_build_example.dft(signal)
    restored = scikit_build_example.idft(spectrum)
    assert len(restored) == len(signal)
    for x, y in zip(signal, restored):
        assert math.isclose(x, y.real, rel_tol=1e-6, abs_tol=1e-10)

def test_generate_cosine():
    x = scikit_build_example.generate_cosine(10, 1.0, 10.0)
    assert len(x) == 10

def test_low_pass_filter():
    x = [0.0, 1.0, 0.0, -1.0, 0.0]
    y = scikit_build_example.low_pass_filter(x, 1.0, 10.0)
    assert len(y) == len(x)

def test_detect_peaks():
    signal = [0.0, 1.0, 0.5, 2.0, 1.5, 0.0]
    peaks = scikit_build_example.detect_peaks(signal, 1.0)
    assert peaks == [1, 3]

def test_compute_energy():
    signal = [1.0, 2.0, 3.0]
    energy = scikit_build_example.compute_energy(signal)
    assert isinstance(energy, float)
    assert math.isclose(energy, 14.0, rel_tol=1e-6)

def test_plot_signal():
    import scikit_build_example as sbe
    sbe.plot_signal([0.0, 1.0, 0.0, -1.0], title="Test Plot")


