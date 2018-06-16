#include <bits/stdc++.h>

using namespace std;

typedef double LD;
const LD EPS = 1e-8;

vector<vector<LD>> M;

double fx(double fx0, double fx1, double x0, double x1) {
    return (fx1 - fx0) / (x1 - x0);
}

int lowestDegreePolynomial(int n) {
    bool istoContinue = false;
    double aux = 0;
    
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) M[j][i] = fx(M[j-1][i-1], M[j][i-1], j-i+1, j+1);
        
        aux = M[i][i];
        for (int k = i; k < n; k++) {
            if(aux != M[k][i]) istoContinue = true;
            else istoContinue = false;
        }

        if(!istoContinue) return i;
    }

    return 0;
}

int main() {
    int n;
    cin >> n;
    
    M.resize(n);
	for(int i = 0; i < n; i++) M[i].resize(n+1, 0.0);
	
	for(int i = 0; i < n; i++) cin >> M[i][0];
    
    cout << lowestDegreePolynomial(n) << endl;

    return 0;
}