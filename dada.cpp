#include <iostream>
#include <iomanip>
using namespace std;

// Funkcja obliczająca wartość pochodnej y' = y^2 / (x + 1)
double derivative(double x, double y) {
    return y * y / (x + 1);
}

// Metoda Eulera do rozwiązywania równania różniczkowego
double eulerMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    // Iteracja w celu obliczenia kolejnych wartości funkcji
    for (int i = 0; i < n; ++i) {
        double slope = derivative(x, y); // Obliczenie wartości pochodnej w punkcie (x, y)
        y = y + h * slope; // Obliczenie wartości przy pomocy metody Eulera
        x = x + h; // Zwiększenie wartości x o krok czasowy h
    }

    return y;
}

int main() {
    double x0 = 0; // Początkowa wartość x
    double y0 = 3; // Początkowa wartość y
    double h = 0.2; // Krok czasowy
    int n = 5; // Liczba iteracji

    double result = eulerMethod(x0, y0, h, n);
    cout << "Przyblizona wartosc y(1) = " << result << endl;

    return 0;
}
