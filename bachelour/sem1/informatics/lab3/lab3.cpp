#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, ".65001");
    double a = 0.0, b = 1.0;
    int k = 10;
    double h = (b - a) / k;
    int n = 10;           // число членов ряда для пункта а)
    double eps = 1e-4;
    cout << fixed << setprecision(6);
    cout << setw(8)  << "x"
         << setw(16) << "S(n=10)"
         << setw(16) << "S(eps)"
         << setw(16) << "Точное" << endl;
    for (int i = 0; i <= k; i++) {
        double x = a + i * h;
        // Точное значение
        double exact = exp(cos(x)) * cos(sin(x));
        // а) Сумма для заданного n членов ряда (n = 0..n-1)
        double sN = 0;
        for (int j = 0; j < n; j++) {
            double fact = 1;
            for (int m = 2; m <= j; m++) fact *= m;
            sN += cos(j * x) / fact;
        }
        // б) Сумма с точностью eps
        double sE = 0;
        int j = 0;
        double term;
        do {
            double fact = 1;
            for (int m = 2; m <= j; m++) fact *= m;
            term = cos(j * x) / fact;
            sE += term;
            j++;
        } while (fabs(term) >= eps);

        cout << setw(8)  << x
             << setw(16) << sN
             << setw(16) << sE
             << setw(16) << exact << endl;
    }
    return 0;
}