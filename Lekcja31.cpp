#include <iostream>
#include <vector>

double neville(std::vector<double> x, std::vector<double> y, double p) {
    int n = x.size();
    std::vector<std::vector<double>> Q(n, std::vector<double>(n, 0.0));

    for (int i = 0; i < n; i++) {
        Q[i][0] = y[i];
    }

    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            Q[i][j] = ((p - x[i + j]) * Q[i][j - 1] - (p - x[i]) * Q[i + 1][j - 1]) / (x[i] - x[i + j]);
        }
    }

    return Q[0][n - 1];
}

int main() {
    try {
        int n;
        std::cout << "Podaj liczbę węzłów: ";
        std::cin >> n;
        std::vector<double> x(n);
        std::vector<double> y(n);

        for (int i = 0; i < n; i++) {
            std::cout << "Podaj wartość węzła " << i + 1 << ": ";
            std::cin >> x[i];
            std::cout << "Podaj wartość funkcji w węźle " << i + 1 << ": ";
            std::cin >> y[i];
        }

        double p;
        std::cout << "Podaj punkt p: ";
        std::cin >> p;

        if (std::unordered_set<double>(x.begin(), x.end()).size() == x.size()) {
            double result = neville(x, y, p);
            std::cout << "Przybliżona wartość funkcji w punkcie p = " << p << " wynosi: " << result << std::endl;
        } else {
            std::cout << "Wartości węzłów muszą być różne." << std::endl;
        }
    } catch (...) {
        std::cout << "Wprowadź poprawne wartości liczbowe." << std::endl;
    }

    return 0;
}
