#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;
int main() {
    setlocale(LC_ALL, ".65001");
    double eps = 1e-4, S = 0, a = 0.5;
    int n = 1;
    while (fabs(a) >= eps) {
        S += a;
        n++;
        double fact1 = 1;
        double fact2 = 1;
        for (int i = 2; i <= n; i++) fact1 *= i;
        for (int i = 2; i <= 2*n; i++) fact2 *= i;
        a = fact1 / fact2;
    }
    cout << "Сумма ряда S = " << S << endl;
    return 0;
}