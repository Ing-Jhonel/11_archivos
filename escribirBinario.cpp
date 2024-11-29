#include <iostream>
#include <fstream>
#include "registro.h"
using namespace std;

int main(){
	tRegistro registro;
	fstream archivo;
	archivo.open("bd.dat", ios::out | ios::binary);
	bool seguir = true;
	while(seguir){
		cout << "Codigo: ";
		cin.sync();
		cin >> registro.codigo;
		cout << "Nombre: ";
		cin.sync();
		cin.getline(registro.item, MAX);
		cout << "Precio: ";
		cin.sync();
		cin >> registro.valor;
		archivo.write((char *)&registro, SIZE);
		cout << "Otro [S/N]? ";
		char c;
		cin >> c;
		if(c=='n' || c=='N'){
			seguir = false;
		}
	}
	archivo.close();
	return 0;
}