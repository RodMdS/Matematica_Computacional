#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

vector<double> coef;

double f(double x) {
    double res = 0.00000;
    
    res += coef[0];
    for(int i = 1; i < coef.size(); i++) {
        double aux = pow(x, i);
        res += (coef[i] * aux);
    }

    return res;
}

double simpson(double (*f)(double), double a, double b) {
    double mid = (a + b) / 2;
    double h = (b - a) / 2;

    return ((f(a) + (4 * f(mid)) + f(b)) * (h / 3));
}

double simpson_composta(double (*f)(double), double a, double b, int n) {
    double  resultado = 0;
    vector<double> aux;
    aux.resize(2 * n);

    if(n == 1) return simpson(f, a, b);

    double h = ((b - a) / (2 * n));
    for(int i = 0; i < (2*n); i++) {
        aux[i] = simpson(f, a, (a + h));
        a += h;
    }
    
    for(int i = 0; i < (2*n); i++) {
        resultado += aux[i];
    }

    return resultado;
}

int main() {
    int grau, N;
    double A, B;

    cin >> grau;

    coef.resize(grau + 1);

    for (int i = 0; i < coef.size(); i++) cin >> coef[i];

    cin >> A;
    cin >> B;
    cin >> N;

    cout.precision(5);
    cout << std::fixed << simpson_composta(f, A, B, N) << endl;

    return 0;
}