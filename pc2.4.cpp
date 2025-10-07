#include <iostream>
using namespace std;

bool simbolosPermitidos(char c) {
    char simbolos[] = "!@#$%^&*()_-+=.";
    for(int i = 0; simbolos[i] != '\0'; i++){ //\0
        if(c == simbolos[i]){
        	return true;
		}
    }
    return false;
}

int longitud(char *p){
    int cont = 0;
    while(*(p + cont) != '\0'){
        cont++;	
	}
    return cont;
}

int EsContrasenaSegura(char *p){
    int len = longitud(p);
    if(len < 12){
        cout << "Posicion:  1  Muy corta (menos de 12 caracteres) ";
        return 1;
    }

    bool mayus = false, minus = false, num = false, simb = false;

    for(int i = 0; *(p + i) != '\0'; i++){
        char c = *(p + i);
        if(c == '\0'){
            cout << "Posicion: " << i + 1 << " Tiene espacio en blanco";
            return i + 1;
        }

        if(!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || simbolosPermitidos(c))){
            cout << "Posicion: " << i + 1 << " Caracter no permitido: " << c << " ";
            return i + 1;
        }

        if(i > 0 && c == *(p + i - 1)){
            cout << "Posicion: " << i + 1 << " Dos simbolos " << c << c << " consecutivos";
            return i + 1;
        }

        if(c >= 'A' && c <= 'Z'){
        	mayus = true;
		}else if(c >= 'a' && c <= 'z'){
			minus = true;
		}else if(c >= '0' && c <= '9'){
			num = true;
		}else if(simbolosPermitidos(c)){
			simb = true;
		}
    }

    if(!(mayus && minus && num && simb)){
        cout << "Posicion:  1  No cumple todas las reglas";
        return 1;
    }

    cout << "Posicion:  0  Cumple todas las reglas";
    return 0;
}

int main() {
    char contrasena[100];

    cout << "Ingrese contraseña: ";
    cin >> contrasena;

    EsContrasenaSegura(contrasena);

    return 0;
}



