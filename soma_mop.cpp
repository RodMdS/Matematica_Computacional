#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int sequence(int k, vector<int> &coef) {
    int x = 1;
    int result = 0;

    for (int i = 0; i < coef.size(); i++) {
        result += coef[i] * x;
        x *= k;
    }

    return result;
}

int lagrange(vector<int> &coef) {
    int result = 0;
    int next = coef.size() + 1;

    for (int i = 1; i < next; i++) {
        int n = 1;
        int d = 1;

        for (int j = 1; j < next; j++) {
            if (i == j) continue;

            n *= next - j;
            d *= i - j;
        }
        result += coef[i - 1] * (n / d);
    }

    return result;
}

int main() {
    int degree;

    cin >> degree;

    vector<int> coef(degree + 1);

    for (int i = 0; i <= degree; i++) cin >> coef[i];

    int sum = 0;
    vector<int> data;

    for (int i = 1; i < coef.size(); i++) {
        data.push_back(sequence(i, coef));
        int next = lagrange(data);
        sum += next;
    }

    cout << sum << endl;

    return 0;
}