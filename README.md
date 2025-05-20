# Projekt nr 3 – Przetwarzanie sygnałów z pybind11
# Grupa Adrian i Kajetan, ACiR 3B, grupa nr 7
# Indeksy kolejno: 203374 i 203627

Ten projekt to biblioteka C++ do przetwarzania sygnałów, udostępniona jako moduł Pythona za pomocą pybind11.

## Funkcjonalności podstawowe:
- Wizualizacja sygnału z wykorzystaniem biblioteki matplotplusplus 
- DFT i transformata odwrotna 
- Filtracja 1D i 2D 
- Generowanie sygnałów o zadanej częstotliwości (sin, cos, prostokątny, piłokształtny)

## Funckjonalność dodatkowa (grupa nr 7):
- Usuwanie wysokich częstotliwości z sygnału (korzystajac z DFT)

## Instalacja (np. w git bash przy pomocy condy po sklonowaniu projektu i przejściu do jego lokalizacji):
1. conda create -n (nazwa_środowiska) python=(wybrana_wersja_pythona - np. 3.11) pip
2. conda activate (nazwa_środowiska)
3. pip install scikit-build-core pybind11 pytest cmake ninja build
4. pip install . 

# Wyjaśnienie kroków:
1. Stworzenie środowiska pythonowego 
2. Aktywowanie tego środowiska
3. Zainstlowanie w środowisku odpowiednich bibliotek potrzebnych do zbudowania modułu pythonowego
4. Zbudowanie projektu

## Uruchomienie wcześniej przygotowanych testów po instalacji i budowie projektu:
- pytest -v -s tests