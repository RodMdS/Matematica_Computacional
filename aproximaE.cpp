#include <bits/stdc++.h>

using namespace std;

double fatorial(int n){
	double fact = 1;
	
	for(int i = 1; i <= n; i++)
		fact = fact * i;

	return fact;
}

double euler(double epsilon){
	double x0 = 1.0; //aproximacao anterior
	int iter = 0; // iteracao
	double termo = 1.0;
	double x; // nova aproximacao
	double error; // erro relativo
	do{
		iter++;
		termo = 1.0 / fatorial(iter); // calcula termo
		x = x0 + termo; //calcule x
		error = fabs( (x-x0)/x ); // calcula erro relativo
		x0 = x;
	}while(error > epsilon); // criterio de parada
	return x;
}

int main(){
	double epsilon;
	cin >> epsilon;
	cout << fixed << setprecision(15) << euler(epsilon) << endl;
	
	return 0;
}