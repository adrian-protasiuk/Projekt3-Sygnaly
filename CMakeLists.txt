cmake_minimum_required(VERSION 3.15...3.26)  # Wymagana aktualizacja wersji
project(scikit_build_example VERSION 0.0.1 LANGUAGES CXX)

# Ścieżka do zainstalowanej biblioteki Matplot++
set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH};L:/Libs/matplotpp-install/lib/cmake/Matplot++")
find_package(matplot++ REQUIRED)


# 1. Znajdź zależności
find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
find_package(pybind11 REQUIRED CONFIG)  # Użyj wersji CONFIG zamiast add_subdirectory

# 2. Źródła
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

# 3. Stwórz moduł
pybind11_add_module(scikit_build_example ${SOURCES})  # Nazwa TAKA SAMA jak w PYBIND11_MODULE!

# 4. Ustawienia dodatkowe
target_link_libraries(scikit_build_example
		PRIVATE
		pybind11::module
		Matplot++::matplot   # ✅ Poprawna wielkość liter i nazwa
)



target_compile_definitions(scikit_build_example PRIVATE
		VERSION_INFO=${PROJECT_VERSION}  # Używamy wersji z projektu
)

# 5. Instalacja
install(TARGETS scikit_build_example
		DESTINATION .
		LIBRARY DESTINATION .
)
