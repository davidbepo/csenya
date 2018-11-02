#include <iostream>
#include <cstdlib>//atoi
#include <fstream>//para escribir en un archivo
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main(int argc,char* argv[]) {
unsigned short num;
string contrasena,continuar,archivo;

cout << "**************************************\n"
	 << "* generador aleatorio de contraseñas *\n"
	 << "**************************************\n\n";

if(argc <= 1) {
	cout << "¿de cuantos caracteres quieres la contraseña?: "; cin >> num;
} else
	num = atoi(argv[1]);

if(num<7) {
	cout << "la contraseña es muy corta ¿quieres continuar?: "; cin >> continuar;
	transform(continuar.begin(), continuar.end(), continuar.begin(), ::tolower); 
	if(continuar == "s" or continuar == "si")
		cout << "\ncontinuando \n";
	else
		return 1;
}

random_device rd;
default_random_engine rng(rd());
uniform_int_distribution<char> uni(32,126);

for(int a=0;a<num;a++) {
	char caracter = uni(rng);
	contrasena += caracter;
}

cout << '\n' << contrasena << "\n\n";

if(argc <= 2) {
	cout << "¿guardar la contraseña en un archivo? s/n: "; cin >> continuar;
}else
	continuar = "s";

transform(continuar.begin(), continuar.end(), continuar.begin(), ::tolower); 
if(continuar == "s" or continuar == "si") {
	if(argc > 2)
		archivo = argv[2];
	else {
		cout << "pon el nombre del archivo: "; cin >> archivo;
	}
	ofstream ac;
	ac.open(archivo);
	ac << contrasena << '\n';
	ac.close();
	cout << "\ncontraseña guardada \n\n";
}
}
