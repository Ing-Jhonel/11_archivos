#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <iomanip> // Formato de salida

int main(){
	
	const int IGV = 21;
	string ruc, producto;
	int unidades;
	double precio, neto, total, igv;
	char aux;
	ifstream archivo;
	int c=0;
	archivo.open("compras.txt"); //Abre el archivo ya creado
	
	if(archivo.is_open()){ //existe el archivo, osea se abrio
		archivo >> ruc; //Primer ruc
		while(ruc != "X"){
			archivo >> unidades >> precio;
			archivo.get(aux); //salta el espacio
			getline(archivo, producto);
			c++;
			neto = unidades*precio;
			igv = neto*IGV/100;
			total = neto + igv;
			cout << "Compra " << c << ".-" << endl
				<< "	" << producto << ": " << unidades
				<< " x " << fixed << setprecision(2)
				<< precio << " = " << neto << " - I.G.V.: "
				<< igv << " - Total: " << total << endl;
			archivo >> ruc; // siguiente ruc;
		}
		archivo.close();//cierra el archivo
	} else {
		cout << "ERROR: No se ha podido abrir el archivo." << endl;
	}
	return 0;	
}
