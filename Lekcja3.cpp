#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

double Nevill (int n, double* x, double* y, double c){
    double * p = new double[n+1];
    for(int k=0; k<=n; k++){
        p[k] = y[k];
        for (int j=k-1; j>=0; j--){
            p[j] = p[j+1]+(p[j+1]-p[j]) * (c-x[k]) / (x[k] - x[j]);
        }
        double wynik = p[0];
        delete [] p;
        return wynik;
    }
}

int main()
{
	int n;
	cout << "Podaj Liczbe wezlow" << endl;
	cin >> n;
	cout << "Podaj wartosci wezlow" << endl;
	double* tabx = new double[n];
	double* taby = new double[n];
	int sprawdz = 0;
	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i << "] - ";
		cin >> tabx[i];
	}
	cout << "Podaj wartosci funkcji w tych wezlach" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Y[" << i << "] - ";
		cin >> taby[i];
		if (i>=0 && tabx[i] < tabx[i - 1])
		{
			sprawdz = 1;
		}
    }
}