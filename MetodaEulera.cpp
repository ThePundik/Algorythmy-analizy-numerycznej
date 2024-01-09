#include <iostream>
using namespace std;

// Funkcja obliczająca wartość pochodnej y' = y / x^2
double pochodna(double x, double y) {
    return y / (x * x);
}

// Metoda Heuna do rozwiązywania równania różniczkowego
double heunsMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    // Iteracja w celu obliczenia kolejnych wartości funkcji
    for (int i = 0; i < n; ++i) {
        double k1 = pochodna(x, y); // Pochodna w punkcie (x, y)
        double k2 = pochodna(x + h, y + h * k1); // Pochodna w punkcie (x+h, y+h*k1)
        
        y = y + (h / 2.0) * (k1 + k2); // Obliczenie wartości przy pomocy metody Heuna
        x = x + h; // Zwiększenie wartości x o krok czasowy h
    }

    return y;
}

double pochodna2(double x, double y) {
    return 2 * x * y;
}

// Zmodyfikowana metoda Eulera do rozwiązywania równania różniczkowego
double modifiedEulerMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    // Iteracja w celu obliczenia kolejnych wartości funkcji
    for (int i = 0; i < n; ++i) {
        double k1 = pochodna2(x, y); // Obliczenie wartości pochodnej w punkcie (x, y)
        double k2 = pochodna2(x + h, y + h * k1); // Obliczenie wartości pochodnej w punkcie (x+h, y+h*k1)

        // Obliczenie wartości przy pomocy zmodyfikowanej metody Eulera
        y = y + (h / 2.0) * (k1 + k2);
        x = x + h; // Zwiększenie wartości x o krok czasowy h
    }

    return y;
}

int main() {
    int wybor, n;
    double x0, y0, h;
    double result;
    cout << "Prosze wybrac zadanie :)\n" << endl;
    cout << "\t1 - Zadanie 14.1\n" << endl;
    cout << "\t2 - Zadanie 14.2\n" << endl;
    cout << "\t3 - Zadanie 14.3\n" << endl;
    cin >> wybor;

    switch (wybor)
    {
    case 2:
        result = heunsMethod(1, 2, 0.25, 2);
        cout << "Przyblizona wartosc f(1.5) = " << result << endl;
        return 0;
        break;
    
    case 3:
        result = modifiedEulerMethod(0, 1, 0.25, 2);
        cout << "Przyblizona wartosc y(0.5) = " << result << endl;
    
    default:
        break;
    }
}
