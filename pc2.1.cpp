#include <iostream>
using namespace std;

bool esPrimo(int num){
    if(num < 2){
        return false;	
	} 
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0){
            return false;	
		} 
    }
    return true;
}

int contarPrimos(int *p, int n){
    int cont = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(esPrimo(*(p + i*n + j))){
    			cont++;
			}
		}     
	} 
    return cont;
}

int contarPares(int *p, int n){
    int cont = 0;
    for(int i = 0; i < n; i++){
    	if(*(p + i*n + i) % 2 == 0){
    		cont++;
		}  
	}   
    return cont;
}

int sumarDiagSec(int *p, int n){
    int suma = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(i + j > n - 1){
    			suma += *(p + i*n + j);
			}    
		}     
	}    
    return suma;
}

int main() {
    int n;
    cout << "Ingrese el tamaño de la matriz (n<=5): ";
    cin >> n;

    int M[n][n];
    cout << "Ingrese los elementos de la matriz: " << endl;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> *(*(M + i) + j);

    int *p = &M[0][0];

    cout << "Matriz ingresada y direcciones" << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << *(p + i*n + j) << " (" << (p + i*n + j) << ") ";
        }
        cout << endl;
    }

    cout << "Seleccione operacion:" << endl;
    cout << "1. Contar primos" << endl;
    cout << "2. Contar pares en la diagonal principal" << endl;
    cout << "3. Sumar debajo de la diagonal secundaria" << endl;
    cout << "Opcion: " << endl;

    int opcion;
    cin >> opcion;

    int resultado = 0;

    int (*funcion)(int*, int) = 0;

    if(opcion == 1) {
       funcion = contarPrimos;	
	}else if(opcion == 2){
		funcion = contarPares;
	}else if(opcion == 3){
		funcion = sumarDiagSec;
	}else{
        cout << "Opción inválida";
        return 0;
    }

    resultado = funcion(p, n);

    cout << "Resultado: " << resultado << endl;
    return 0;
}

