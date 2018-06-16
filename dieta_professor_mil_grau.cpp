#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

using namespace std;

/*
*   |  25  |  45  |  65  |
*   |--------------------|
* 50| 2500 | 2350 | 1900 |
* 60| 2850 | 2700 | 2250 |
* 70| 3200 | 3000 | 2750 |
* 80| 3550 | 3350 | 2850 |
*/

int idade;
int peso;
double M[80][65];

void imprimir_M() {
    for(int i = 50; i <= 80; i++) {
        for(int j = 25; j <= 65; j++) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

void start() {
    for(int i = 50; i <= 80; i++) {
        for(int j = 25; j <= 65; j++) {
            M[i][j] = 0;
        }
    }
    M[50][25] = 2500.00000;
    M[50][45] = 2350.00000;
    M[50][65] = 1900.00000;
    M[60][25] = 2850.00000;
    M[60][45] = 2700.00000;
    M[60][65] = 2250.00000;
    M[70][25] = 3200.00000;
    M[70][45] = 3000.00000;
    M[70][65] = 2750.00000;
    M[80][25] = 3550.00000;
    M[80][45] = 3350.00000;
    M[80][65] = 2850.00000;
}

double f_i(double f_x0, double f_x1, double f_x2, int x) {
    //cout << f_x0 << " " << f_x1 << " " << f_x2 << endl;
    //cout << f_x0 << " ";
    //cout << (x - 25) * f_x1 << " ";
    //cout << (x - 25) * (x - 45) * f_x2 << endl;
    return f_x0 + (x - 25) * f_x1 + (x - 25) * (x - 45) * f_x2;
}

void interpolacao_idade(int peso, int idade) {
    double aux[3][3];
    aux[0][0] = M[peso][25];
    aux[1][0] = M[peso][45];
    aux[2][0] = M[peso][65];
    for(int i = 1; i <= 2; i++) {
        for(int j = i; j <= 2; j++) {
            aux[j][i] = (aux[j][i - 1] - aux[j - 1][i - 1]) / (20 * i);
        }
    }

    //for(int i = 0; i <= 2; i++) {
    //    for(int j = 0; j <= 2; j++) {
    //        cout << aux[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    M[peso][idade] = f_i(aux[0][0], aux[1][1], aux[2][2], idade);
}

double f_p(double f_x0, double f_x1, double f_x2, double x) {
    //cout << f_x0 << " " << f_x1 << " " << f_x2 << endl;
    //cout << f_x0 << " ";
    //cout << (x - 50) * f_x1 << " ";
    //cout << (x - 50) * (x - 60) * f_x2 << endl;    
    return f_x0 + ((x - 50) * f_x1) + (x - 50) * (x - 60) * f_x2;
}

void interpolacao_peso(int peso, int idade) {
    double aux[3][3];
    aux[0][0] = M[50][idade];
    aux[1][0] = M[60][idade];
    aux[2][0] = M[70][idade];
    
    for(int i = 1; i <= 2; i++) {
        for(int j = i; j <= 2; j++) {
            aux[j][i] = (aux[j][i - 1] - aux[j - 1][i - 1])  / (10 * i);
        }
    }

    //for(int i = 0; i <= 2; i++) {
    //    for(int j = 0; j <= 2; j++) cout << aux[i][j] << " ";
    //    cout << endl;
    //}
    
    M[peso][idade] = f_p(aux[0][0], aux[1][1], aux[2][2], peso);
}

int main() {
    start();

    cin >> idade;
    cin >> peso;

    if(idade >= 25 && idade <= 65) {
        if(peso >= 50 && peso <= 80) {
            if(M[peso][idade] == 0) {
                if(idade != 25 && idade != 45 && idade != 65){
                    interpolacao_idade(50, idade);
                    interpolacao_idade(60, idade);
                    interpolacao_idade(70, idade);
                    interpolacao_idade(80, idade);
                }
                //interpolacao_peso(peso, 25);
                //interpolacao_peso(peso, 45);
                //interpolacao_peso(peso, 65);
                //imprimir_M();
                //cout << "uhu" << endl;
                interpolacao_peso(peso, idade);
                //cout << endl;
                //imprimir_M();
            }
            cout.precision(5);
            cout.setf(ios::fixed, ios::floatfield);
            cout << M[peso][idade] << endl;
        }
    }

    return 0;
}