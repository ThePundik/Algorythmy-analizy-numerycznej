#include <iostream>
using namespace std;


double pochodna1(double x, double y) {
    return y * y / (x + 1);
}


double eulerMethod(double x0, double y0, int n, double punkt) {
    double x = x0;
    double y = y0;
    double h = (punkt - x0) / n;

    
    while (x < punkt) {
        double k1 = pochodna1(x, y); 
        y = y + h * k1;
        x += h;
    }

    return y;
}


double pochodna2(double x, double y) {
    return y / (x * x);
}


double heunMethod(double x0, double y0, int n, double punkt) {
    double x = x0;
    double y = y0;
    double h = (punkt - x0) / n;

    
    for (int i = 0; i < n; ++i) {
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


double modifiedEulerMethod(double x0, double y0, int n, double punkt) {
    double x = x0;
    double y = y0;
    double h = (punkt - x0) / n;

    
    while (x < punkt) {
        double k1 = pochodna3(x, y);
        double k2 = pochodna3(x + h, y + h * k1);

        
        y = y + (h / 2.0) * (k1 + k2);
        x += h;
    }

    return y;
}

int main() {
    int wybor, n;
    double x0, y0, h, punkt;
    double result;
    cout << "Prosze wybrac zadanie :)\n" << endl;
    cout << "\t1 - Zadanie 14.1\n" << endl;
    cout << "\t2 - Zadanie 14.2\n" << endl;
    cout << "\t3 - Zadanie 14.3\n" << endl;
    cin >> wybor;

    switch (wybor)
    {
    case 1:
        cout << "Podaj liczbe iteracji n: ";
        cin >> n;
        cout << "Podaj punkt, w ktorym chcesz obliczyc y: ";
        cin >> punkt;
        result = eulerMethod(0, 3, n, punkt);
        cout << "Przyblizona wartosc y(" << punkt << ") = " << result << endl;
        return 0;
        break;
    case 2:
        cout << "Podaj liczbe iteracji n: ";
        cin >> n;
        cout << "Podaj punkt, w ktorym chcesz obliczyc y: ";
        cin >> punkt;
        result = heunMethod(1, 2, n, punkt);
        cout << "Przyblizona wartosc f(1.5) = " << result << endl;
        return 0;
        break;
    
    case 3:
        cout << "Podaj liczbe iteracji n: ";
        cin >> n;
        cout << "Podaj punkt, w ktorym chcesz obliczyc y: ";
        cin >> punkt;
        result = modifiedEulerMethod(0, 1, n, punkt);
        cout << "Przyblizona wartosc y(" << punkt << ") = " << result << endl;
        return 0;
        break;
    default:
        break;
    }
}
