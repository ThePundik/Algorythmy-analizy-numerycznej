#include <iostream>
using namespace std;


double pochodna1(double x, double y) {
    return y * y / (x + 1);
}


double eulerMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    
    for (int i = 0; i < n; i++) {
        double pochodna = pochodna1(x, y); 
        y = y + h * pochodna; 
        x += h; 
    }

    return y;
}


double pochodna2(double x, double y) {
    return y / (x * x);
}


double heunsMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    
    for (int i = 0; i < n; i++) {
        double k1 = pochodna2(x, y); 
        double k2 = pochodna2(x + h, y + h * k1); 
        
        y = y + (h / 2.0) * (k1 + k2); 
        x += h; 
    }

    return y;
}

double pochodna3(double x, double y) {
    return 2 * x * y;
}


double modifiedEulerMethod(double x0, double y0, double h, int n) {
    double x = x0;
    double y = y0;

    
    for (int i = 0; i < n; i++) {
        double k1 = pochodna3(x, y); 
        double k2 = pochodna3(x + h, y + h * k1);
        y = y + (h / 2.0) * (k1 + k2);
        x += h; 
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
    case 1:
        result = eulerMethod(0, 3, 0.2, 5);
        cout << "Przyblizona wartosc y(1) = " << result << endl;
        return 0;
        break;
    case 2:
        result = heunsMethod(1, 2, 0.25, 2);
        cout << "Przyblizona wartosc f(1.5) = " << result << endl;
        return 0;
        break;
    
    case 3:
        result = modifiedEulerMethod(0, 1, 0.25, 2);
        cout << "Przyblizona wartosc y(0.5) = " << result << endl;
        return 0;
        break;
    default:
        break;
    }
}
