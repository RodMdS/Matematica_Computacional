#include <bits/stdc++.h>

using namespace std;

typedef double LD;
vector< vector<LD> > M; // Matriz

LD dif(vector<LD> atual, vector<LD> prox){
	int n = atual.size();
	LD max_dif = 0.0;
	LD max_x = 0.0;
	for(int i = 0; i < n; i++){
        max_dif = max(max_dif, fabs(atual[i] - prox[i])); 
        max_x = max(max_x, fabs(prox[i]));
	}
	//printf("max_dif %lf max_x %lf ratio %lf\n", max_dif, max_x, max_dif/max_x);
	return max_dif / max_x;
}

vector <LD> GaussJacobi(vector <LD> inicial, LD EPS, int MAX_ITER){
	vector <LD> atual = inicial;
	vector <LD> prox = inicial;
	int n = M.size(); 
	for(int k = 1; k <= MAX_ITER; k++){
		printf("ITERACAO %d\n", k);
		for(int i = 0; i < n; i++){
			prox[i] = M[i][n];
			for(int j = 0; j < n; j++){
				if( j != i ) prox[i] -= M[i][j] * atual[j];
			}
			prox[i] /= M[i][i];
			printf("x[%d] = %lf\n", i, prox[i]);
		}
		if( dif(atual, prox) <= EPS ) { 
			atual = prox;
			break;
		}
		atual = prox;
	}
	return atual;
}

vector<LD> GaussSeidel(vector <LD> inicial, LD EPS, int MAX_ITER){
	vector<LD> ant = inicial;
    vector<LD> atual = inicial;
	vector<LD> prox = inicial;
	int n = M.size(); 
	for(int k = 1; k <= MAX_ITER; k++){
		printf("ITERACAO %d\n", k);
		for(int i = 0; i < n; i++){
			prox[i] = M[i][n];
			for(int j = 0; j < n; j++){
				if( j != i ) prox[i] -= M[i][j] * atual[j];
			}
			prox[i] /= M[i][i];
			printf("x[%d] = %lf\n", i, prox[i]);
            for(int i = 0; i < n; i++)
                atual[i] = prox[i];
		}
		if(dif(ant, atual) <= EPS) {
            //cout << "Deu ruim" << endl;
            ant = atual;
			break;
		}
        ant = atual;
	}
	return atual;
}

int main(){
    int n;
    cin >> n;
		
    //Inicializacao matriz
    M.resize(n);
    for(int i = 0; i < n; i++)
        M[i].resize(n + 1, 0.0);
    
    //Leitura da matriz
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> M[i][j];

    vector <LD> inicial; // chute inicial
    inicial.resize(n);
    for(int i = 0; i < n; i++)
        cin >> inicial[i];
        
    LD EPS; // precisão tolerada
    cin >> EPS;

    int max_iter; // número máximo de iterações
    cin >> max_iter;
    
    inicial = GaussSeidel(inicial, EPS, max_iter);	
    
    //Solucao
    //for(int i = 0; i < n; i++){
		//	cout << "x[" << i << "] = " << fixed << setprecision(5) << inicial[i] << " " << endl;
    //}
    
    return 0;
}