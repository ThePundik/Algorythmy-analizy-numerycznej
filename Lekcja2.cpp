#include <iostream>
#include <string>

using namespace std;

void newton(int n, double tabx[], double taby[], double p);

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
		if (i>0 && tabx[i] < tabx[i - 1])
		{
			sprawdz = 1;
		}
	}
	if (sprawdz == 0)
	{
		cout << "Ile punktow?" << endl;
		int j;
		cin >> j;
		for (int i = 0; i < j; i++)
		{
			cout << "Podaj punkt p" << i + 1 << endl;
			double p;
			cin >> p;
			if (p > tabx[0] && p < tabx[n - 1])
			{
				newton(n, tabx, taby, p);
			}
			else
			{
				cout << "Punkt nie spelnia warunki interpolacji" << endl;
			}
		}
	}
	else
	{
		cout << "warunki nie sa spelnione" << endl;
	}



}

void newton(int n, double tabx[], double taby[], double p)
{
	double* IR = new double[n];
	double* W = new double[n];
	int i = 0;
	for(int i = 0; i<n; i++)
	{
		IR[i] = taby[i];
	}
	int k = 1;
	for(int k = 1; k < n; k++)
	{
		
		for(i = n - 1;i >= k; i--)
		{
			IR[i] = (IR[i] - IR[i - 1]) / (tabx[i] - tabx[i - k]);
		}

	}

	int odp = 0;
	W[0] = IR[0];
	odp += W[0];
	for(int i = 1; i < n; i++)
	{
		W[i] = IR[i];
		for (int j = 0; j <= i-1; j++)
			{
				W[i] *= (p - tabx[j]);
			}
		odp += W[i];
	}
	cout << "\n----------------- Rozwiazanie -------------------\n\n" << endl;
	cout << "Policzone ilorazy rozniczkowe: "<<endl;
	for (i = 0; i < n;i++)
	{
		cout << "IR[" << i << "] = " << IR[i] << " " << endl;
	}
	cout << "\nPoliczone elementy sumy wzoru koncowego: "<<endl;
	for (i = 0; i < n;i++)
	{
		cout << "Dla i=" << i << " = " << W[i] << " " << endl;
	}
	cout << "\nOdpowiedz koncowa:  "<<endl;
	cout << "W(" << p << ") = ";
	for (i = 0; i < n;i++)
	{
		if (i != n - 1)
		{
			cout << W[i] << " + ";
		}
		else
		{
			cout << W[i];
		}	
	}
	cout << " = " << odp;
}