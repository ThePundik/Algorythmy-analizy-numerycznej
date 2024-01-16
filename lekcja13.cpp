#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Funkcja do obliczenia macierzy trójkątnej dolnej L
vector<vector<double>> choleskyDecomposition(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2);
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; k++) {
                    sum += (L[i][k] * L[j][k]);
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}

// Funkcja do rozwiązania układu o macierzy trójkątnej dolnej L
vector<double> solveLowerTriangular(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n, 0.0);

    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}

// Funkcja do rozwiązania układu o macierzy trójkątnej górnej LT (transpozycja L)
vector<double> solveUpperTriangular(const vector<vector<double>>& L, const vector<double>& y) {
    int n = L.size();
    vector<double> x(n, 0.0);

    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += L[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / L[i][i];
    }

    return x;
}

int main() {
    int n;
    cout << "Podaj rozmiar macierzy kwadratowej: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n, 0.0));
    vector<double> b(n, 0.0);

    cout << "Wprowadź elementy macierzy A:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Wiersz " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    cout << "Wprowadź wektor wyrazów wolnych b:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    // Obliczenie rozkładu Choleskiego
    vector<vector<double>> L = choleskyDecomposition(A);

    // Rozwiązanie układu równań
    vector<double> y = solveLowerTriangular(L, b);
    vector<double> x = solveUpperTriangular(L, y);

    // Wyświetlenie wyniku
    cout << "Rozwiązanie układu równań:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    return 0;
}
