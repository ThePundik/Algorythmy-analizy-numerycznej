#include <iostream>

using namespace std;

double lagrange_interpolation(double x_values[], double y_values[], int n, double p) {
    double result = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y_values[i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (p - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }
        result += term;
    }

    return result;
}


int main(){

    double p;
    double result;
    int n;
    cout << "Podaj liczbe wezlow: " << endl;
    cin >> n;
    cout << "Podaj wartosci wezlow: " << endl;
    double* x_values = new double [n];
    double* y_values = new double [n];
    for (int i = 0; i < n; i++){
        cout << "X[" << i << "] - ";
        cin >> x_values[i];
    }
    
    for(int i = 0; i<n; i++){
        cout << "Y[" << i << "] - ";
        cin >> y_values[i];
    }
    cout << "Podaj wartosc P: " << endl;
    cin >> p;

    result = lagrange_interpolation(x_values, y_values, n, p);

    cout << "Wynik: " << result << endl;
    return 0;
}