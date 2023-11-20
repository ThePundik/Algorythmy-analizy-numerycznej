#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int lw;
    cout << "Podaj Liczbe wezlow (w>=1)" << endl;
    cin >> lw;
    double* tabX = new double[lw];
    double* tabY = new double[lw];
    cout << "Podaj wezly" << endl;
    for(int i = 0; i <lw; i++){
        cout << "X[" << i << "] = " << endl;
        cin >> tabX[i];
    }

    for (int i = 0; i<lw; i++){
        cout << "Y[" << i << "] = " << endl;
        cin >> tabY[i];
    }

}