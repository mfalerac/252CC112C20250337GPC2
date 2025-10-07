#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int NOTAS[] = {20, 8, 13, 19, 17, 16, 12, 0, 19};
	const int n = 10;
	
	double promedio;
	
	int suma1 = 0;
	for(int i = 0; i < n; i++){
		suma1 = suma1 + NOTAS[i];
	}
	promedio = suma1/n;
	
	double x[n];
	for(int i = 0; i < n; i++){
		x[i] = NOTAS[i] - promedio;
	}
	int desvEst = sqrt(((x[n])*(x[n]))/n);
	
	cout << "Desviacion Estandar: " << desvEst << endl;
	
	int valorCentral[n];
	for(int i = 0; i < n; i++){
		valorCentral = abs(NOTAS[i] - promedio);
		if(valorCentral[i] < valorCentral[i + 1]){
		valorCentral = valorCentral[i];
	}
	
	int NOTASM[10];
	for(int i = 0; i < n; i++){
		if(NOTAS[i] - valorCentral > desvEst/2){
			swap(NOTAS[i], valorCentral);
		}
	}
	
	cout << "Valor Central: " << valorCentral << endl;
	
	cout << "Notas originales: " << endl;
	cout << NOTAS;
	
	cout << "Notas modificadas: " << endl;
	cout << NOTASM;
	
	return 0;
}


