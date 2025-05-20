cmake_minimum_required(VERSION 3.15...3.26)
project(scikit_build_example VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};L:/Libs/matplotpp-install/lib/cmake/Matplot++")
find_package(matplot++ REQUIRED)

find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 REQUIRED CONFIG)

set(SOURCES
		src/bindings.cpp
		src/fourier.cpp
		src/signal_processing.cpp
		src/filtering.cpp
		src/generator.cpp
		src/peak_detection.cpp
		src/energy.cpp
		src/visualization.cpp
)

pybind11_add_module(scikit_build_example ${SOURCES})

target_link_libraries(scikit_build_example
		PRIVATE
		pybind11::module
		Matplot++::matplot
)

target_compile_definitions(scikit_build_example PRIVATE
		VERSION_INFO=${PROJECT_VERSION}
)

install(TARGETS scikit_build_example
		DESTINATION .
		LIBRARY DESTINATION .
)
