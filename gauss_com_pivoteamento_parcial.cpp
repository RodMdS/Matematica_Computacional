//Eliminacao de Gauss
/*for (int i = 0; i < n; i++) {
    if (fabs(M[i][i]) < EPS) {
        cout << "Pivo nulo" << endl;
        return 0;
    }
    for (int j = i + 1; j < n; j++) {
        LD r = M[j][i] / M[i][i];
        for (int k = i; k < n + 1; k++) {
            M[j][k] = M[j][k] - r * M[i][k];
        }
    }
}*/

#include <bits/stdc++.h>
#include <math.h>
#include <queue>

using namespace std;

typedef double LD;
const LD EPS = 1e-8;
vector<vector<LD> > M; // Matriz
vector<LD> x;         // Solucao
queue<LD> aux;

//iteração it = 1 M[1..N][1..N]
// pecorro  M[i][it] e pego maior
// crio vetor aux
// pego a linha M[1][] e coloco no vetor
// pego o maior e coloco na linha M[1][]
// pego aux e coloca na linha do maior

int main() {
    int n;n + 1, 0.0
    cin >> n;

    //Inicializacao matriz
    M.resize(n);
    for (int i = 0; i < n; i++)
        M[i].resize(n + 1, 0.0);

    //Leitura da matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            cin >> M[i][j];

    //Eliminacao de Gauss com pivoteamento parcial
    for (int i = 0; i < n; i++) {
        int ind_maior = i;
        for (int r = i + 1; r < n; r++) {
            if(fabs(M[r][i]) > fabs(M[ind_maior][i])) {
                ind_maior = r;
            }
        }
        //cout << "Linha " << ind_maior << ": ";
        for (int s = i; s <= n; s++){
            aux.push(M[ind_maior][s]);
            //cout << aux.back() << " ";
        }
        //cout << endl;

        //for(int r = 0; r <= n; r++)
            //cout << aux[r] << " ";
        //cout << endl;
        
        // [3 2 -1 1]
        // [7 -1 -1 -2]
        // [1 0 1 1]
        // aux = [2 -1 1]
        for (int t = i; t <= n; t++){
            M[ind_maior][t] = M[i][t];
            M[i][t] = aux.front();
            aux.pop();
            //cout << M[ind_maior][t] << " " << M[i][t] << endl;
        }
        
        /*for (int i = 0; i < n; i++) {
            for (int j = 0; j < n + 1; j++) {
                LD elem = M[i][j];
                cout << fixed << setprecision(5) << elem << " ";
            }
            cout << endl;
        }*/

        if (fabs(M[i][i]) < EPS) {
            cout << "Pivo nulo" << endl;
            return 0;
        }
        for (int j = i + 1; j < n; j++) {
            LD r = M[j][i] / M[i][i];
            for (int k = i; k < n + 1; k++) {
                M[j][k] = M[j][k] - r * M[i][k];
            }
        }
    }

    //Mostrando matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            LD elem = M[i][j];
            cout << fixed << setprecision(5) << elem << " ";
        }
        cout << endl;
    }

    x.resize(n);
    //Substituição retroativa
    for (int i = n - 1; i >= 0; i--) {
        x[i] = M[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= M[i][j] * x[j];
        }
        x[i] = x[i] / M[i][i];
    }

    //Solucao
    for (int i = 0; i < n; i++) {
        cout << "x[" << i << "] = " << fixed << setprecision(5) << x[i] << " " << endl;
    }

    return 0;
}