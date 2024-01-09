#include <iostream>
#include <vector>
#include <cmath>


void printMatrix(const std::vector<std::vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (double val : row) {
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}


std::vector<std::vector<double>> choleskyDecomposition(const std::vector<std::vector<double>>& A) {
    int n = A.size();
    std::vector<std::vector<double>> L(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0.0;
            if (j == i) {
                for (int k = 0; k < j; ++k) {
                    sum += L[j][k] * L[j][k];
                }
                L[j][j] = std::sqrt(A[j][j] - sum);
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


std::vector<double> solveLowerTriangular(const std::vector<std::vector<double>>& L, const std::vector<double>& b) {
    int n = L.size();
    std::vector<double> y(n, 0.0);

    for (int i = 0; i < n; ++i) {
        double sum = 0.0;
        for (int j = 0; j < i; ++j) {
            sum += L[i][j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i][i];
    }

    return y;
}


std::vector<double> solveUpperTriangular(const std::vector<std::vector<double>>& L, const std::vector<double>& y) {
    int n = L.size();
    std::vector<double> x(n, 0.0);

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
    std::cout << "Podaj rozmiar macierzy: ";
    std::cin >> n;

    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<double> b(n);

    std::cout << "Wpisz elementy macirzy A:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Wpisz elementy wierszu " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Wpisz elementy wectoru b: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    std::vector<std::vector<double>> L = choleskyDecomposition(A);

    std::cout << "\nDolna macierz trojkatna L:" << std::endl;
    printMatrix(L);

    std::vector<double> y = solveLowerTriangular(L, b);

    std::cout << "\nWector y:" << std::endl;
    for (double val : y) {
        std::cout << val << std::endl;
    }

    std::vector<double> x = solveUpperTriangular(L, y);

    std::cout << "\nRozwiązanie wektora x:" << std::endl;
    for (double val : x) {
        std::cout << val << std::endl;
    }

    return 0;
}
