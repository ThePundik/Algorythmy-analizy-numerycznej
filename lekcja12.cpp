#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            cout << val << "\t";
        }
        cout << endl;
    }
}


vector<vector<double>> choleskyDecomposition(const vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> L(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;
            if (j == i) {
                for (int k = 0; k < j; ++k) {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = sqrt(A[j][j] - sum);
            } else {
                for (int k = 0; k < j; ++k) {
                    sum += L[i][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / L[j][j];
            }
        }
    }

    return L;
}


vector<double> solveLowerTriangular(const vector<vector<double>>& L, const vector<double>& b) {
    int n = L.size();
    vector<double> y(n, 0.0);

    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}


vector<double> solveUpperTriangular(const vector<vector<double>>& L, const vector<double>& y) {
    int n = L.size();
    vector<double> x(n, 0.0);

    for (int i = n - 1; i >= 0; --i) {
        double sum = 0.0;
        for (int j = i + 1; j < n; ++j) {
            sum += L[j][i] * x[j];
        }
        x[i] = (y[i] - sum) / L[i][i];
    }

    return x;
}

int main() {
    int n;
    cout << "Podaj rozmiar macierzy: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<double> b(n);

    cout << "Wpisz elementy macirzy A:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Wpisz elementy wierszu " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    cout << "Wpisz elementy wectoru b: ";
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<vector<double>> L = choleskyDecomposition(A);

    cout << "\nDolna macierz trojkatna L:" << endl;
    printMatrix(L);

    vector<double> y = solveLowerTriangular(L, b);

    cout << "\nWector y:" << endl;
    for (double val : y) {
        cout << val << endl;
    }

    vector<double> x = solveUpperTriangular(L, y);

    cout << "\nRozwiązanie wektora x:" << endl;
    for (double val : x) {
        cout << val << endl;
    }

    return 0;
}
