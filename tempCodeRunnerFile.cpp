#include <iostream>
using namespace std;

// Funkcja obliczająca wartość pochodnej y' = y / x^2
double derivative(double x, double y) {
    return y / (x * x);
}

// Metoda Heuna do rozwiązywania równania różniczkowego
double heunsMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    // Iteracja w celu obliczenia kolejnych wartości funkcji
    for (int i = 0; i < n; ++i) {
        double k1 = derivative(x, y); // Pochodna w punkcie (x, y)
        double k2 = derivative(x + h, y + h * k1); // Pochodna w punkcie (x+h, y+h*k1)
        
        y = y + (h / 2.0) * (k1 + k2); // Obliczenie wartości przy pomocy metody Heuna
        x = x + h; // Zwiększenie wartości x o krok czasowy h
    }

    return y;
}

int main() {
    double x0 = 1; // Początkowa wartość x
    double y0 = 2; // Początkowa wartość y
    double h = 0.25; // Krok czasowy
    int n = 2; // Liczba iteracji

    double result = heunsMethod(x0, y0, h, n);
    cout << "Przyblizona wartosc f(1.5) = " << result << endl;

    return 0;
}
