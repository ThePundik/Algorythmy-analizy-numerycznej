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

    cout << "! W przypadku liczby ulamkowej podac ja w postaci 0.123 !" << endl;
    for (int i = 0; i < lw; i++) {
        cout << "X[" << i << "] = ";
        cin >> tabX[i];
    }

    cout << "! W przypadku liczby e^x podac tylko x !" << endl;
    for (int i = 0; i < lw; i++) {
        cout << "Y[" << i << "] = ";
        cin >> tabY[i];
    }
    cout << "Wybierz jedna z funkcji aproksymujacych:\n\n1. g(x) = ax + b;\n2. g(x) = (a/x) + b\n3. g(x) = b * a^x\n4- g(x) = a*sqrt(x) + b\n0..Wyjscie z programu" << endl;
    int wybor = 4;

    while (wybor != 0) {
        cin >> wybor;
        if (wybor == 1)
        {
            cout << "\nUklad rownan wyglada w taki sposob:" << endl;
            double a, b, c, d, s1, s2;
            a = lw;
            b = 0;
            s1 = 0;
            for (int i = 0; i < lw; i++)
            {
                b += tabX[i];
                s1 += tabY[i];
            }
            cout << a << "a0 + " << b << "a1 = " << s1 << endl;
            c = 0;
            d = 0;
            s2 = 0;
            for (int i = 0; i < lw; i++)
            {
                c += tabX[i];
                d += pow(tabX[i], 2);
                s2 += (tabX[i] * tabY[i]);
            }
            cout << c << "a0 + " << d << "a1 = " << s2 << endl;

            double W, Wa1, Wa0, a0, a1;

            W = a * d - b * c;
            Wa0 = s1 * d - s2 * c;
            Wa1 = a * s2 - b * s1;

            a0 = Wa0 / W;
            a1 = Wa1 / W;

            cout << "Wartosci wyznacznikow:\nW = " << W << "\nWa0 = " << Wa0 << "\nWa1 = " << Wa1 << "\n\nWartosci a0 i a1:\na0 = " << a0 << "\na1 = " << a1 << "\n\nOdpowiedz koncowa:\ng(x) = " << a0 << " + " << a1 << "x" << endl;

        }
        if (wybor == 2) {
            double* tabXPodzielny = new double[lw];
            for (int i = 0; i < lw; i++)
            {
                tabXPodzielny[i] = 1 / (tabX[i]);

            }

            cout << "Po wykonaniu zamiany tabela wyglada nastepujaco:\n" << endl;
            for (int i = 0; i < lw; i++)
            {
                cout << "X[" << i << "] = " << int(tabXPodzielny[i] * 100) / 100 << "   F[" << i << "] = " << tabY[i] << endl;
            }
            cout << "\nUklad rownan wydlada w taki sposob:" << endl;
            double a, b, c, d, s1, s2;
            a = lw;
            b = 0;
            s1 = 0;
            for (int i = 0; i < lw; i++)
            {
                b += tabXPodzielny[i];
                s1 += tabY[i];
            }
            cout << a << "a0 + " << b << "a1 = " << s1 << endl;
            c = 0;
            d = 0;
            s2 = 0;
            for (int i = 0; i < lw; i++)
            {
                c += tabXPodzielny[i];
                d += pow(tabXPodzielny[i], 2);
                s2 += (tabXPodzielny[i] * tabY[i]);
            }
            cout << c << "a0 + " << d << "a1 = " << s2 << endl;

            double W, Wa1, Wa0, a0, a1;

            W = a * d - b * c;
            Wa0 = s1 * d - s2 * c;
            Wa1 = a * s2 - b * s1;

            a0 = Wa0 / W;
            a1 = Wa1 / W;

            cout << "Wartosci wyznacznikow:\nW = " << W << "\nWa0 = " << Wa0<< "\nWa1 = " << Wa1 << "\n" << endl;
            cout << "Odpowiedz koncowa: " << a1 << "*(1/x) + " << a0 << endl;


        }
        if (wybor == 3) {
            int ile;

            double* tabYStopien = new double[lw];
            cout << "Ile Y-ow sa stopniem od 'e' ?" << endl;
            cin >> ile;
            double *ktore = new double[ile];

            cout << "Podej numery ich pozycji" << endl;
            for (int i = 0; i < ile; i++)
            {
                cout << "Y[ ? ] -> ";
                cin >> ktore[i];

                
            }
            int sprawdz;
            for (int i = 0; i < lw; i++)
            {
                sprawdz = 0;
                for (int j = 0; j < ile; j++)
                {
                    if (i == ktore[j])
                    {
                        sprawdz++;
                    }
                }

                if (sprawdz != 0)
                {
                    tabYStopien[i] = tabY[i];
                }
                else
                {
                    tabYStopien[i] = log(tabY[i]);
                }
               
            }
            cout << "Po wykonaniu zamiany pierwiastka z f na !f,\ntabela wyglada nastepujaco:" << endl;
            for (int i = 0; i < lw; i++)
            {
                cout << "X[" << i << "] = " << tabX[i] << "   F[" << i << "] = " << tabYStopien[i] << endl;
            }

            double a, b, c, d, s1, s2;
            a = lw;
            b = 0;
            s1 = 0;
            for (int i = 0; i < lw; i++)
            {
                b += tabX[i];
                s1 += tabYStopien[i];
            }
            cout << a << "a0 + " << b << "a1 = " << s1 << endl;
            c = 0;
            d = 0;
            s2 = 0;
            for (int i = 0; i < lw; i++)
            {
                c += tabX[i];
                d += pow(tabX[i], 2);
                s2 += (tabX[i] * tabYStopien[i]);
            }
            cout << c << "a0 + " << d << "a1 = " << s2 << endl;

            double W, Wa1, Wa0, a0, a1;

            W = a * d - b * c;
            Wa0 = s1 * d - s2 * c;
            Wa1 = a * s2 - b * s1;

            a0 = Wa0 / W;
            a1 = Wa1 / W;

            cout << "Odpowiedz: \ne^("<<a0<<") + e^("<<a1 <<"*x) " << endl;

        }
        if (wybor == 4)
        {
            double* tabXPierwiastek = new double[lw];
            cout << "Po wykonaniu zamiany pierwiastka z X na !X,\ntabela wyglada nastepujaco:" << endl;
            for (int i = 0; i < lw; i++)
            {
                tabXPierwiastek[i] = sqrt(tabX[i]);
            }

            for (int i = 0; i < lw; i++)
            {
                cout << "X[" << i << "] = " << tabXPierwiastek[i] << "   F[" << i << "] = " << tabY[i] << endl;
            }

            cout << "\nUklad rownan wyglada w taki sposob:" << endl;
            double a, b, c, d, s1, s2;
            a = lw;
            b = 0;
            s1 = 0;
            for (int i = 0; i < lw; i++)
            {
                b += tabXPierwiastek[i];
                s1 += tabY[i];
            }
            cout << a << "a0 + " << b << "a1 = " << s1 << endl;
            c = 0;
            d = 0;
            s2 = 0;
            for (int i = 0; i < lw; i++)
            {
                c += tabXPierwiastek[i];
                d += pow(tabXPierwiastek[i], 2);
                s2 += (tabXPierwiastek[i] * tabY[i]);
            }
            cout << c << "a0 + " << d << "a1 = " << s2 << endl;

            double W, Wa1, Wa0, a0, a1;

            W = a * d - b * c;
            Wa0 = s1 * d - s2 * c;
            Wa1 = a * s2 - b * s1;

            a0 = Wa0 / W;
            a1 = Wa1 / W;

            cout << "Wartosci wyznacznikow:\nW = " << W << "\nWa0 = " << Wa0 << "\nWa1 = " << Wa1 << "\n" << endl;
            cout << "Odpowiedz koncowa: " << a1 << "*sqrt(x) + " << a0 << endl;


        }
        if (wybor == 0) {
            cout << " End... " << endl;
        }
        if (wybor == 12) {
            cout << " Program nie istneje! " << endl;
            int a = 11;
            int b = 12;
            int result;
            result = a + b;
            cout << result << endl;
        }
    }
}

