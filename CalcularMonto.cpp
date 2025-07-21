#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void CalcularMonto(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}
	
	char nombre[30], apellido[30];
	cin.ignore(); // Limpiar buffer de entrada
	cout<<"Ingrese nombre del cliente: ";
	cin.getline(nombre, 30);
	cout<<"Ingrese apellido del cliente: ";
	cin.getline(apellido, 30);

	int encontrado = -1;
	for(int i=0; i<totalClientes; i++){
		bool mismoNombre = true;
		for(int j=0; nombre[j]!='\0' || clientes[i].nombre[j]!='\0'; j++){
			if(nombre[j] != clientes[i].nombre[j]){
				mismoNombre = false;
				break;
			}
		}
		if(!mismoNombre) continue;

		bool mismoApellido = true;
		for(int j=0; apellido[j]!='\0' || clientes[i].apellido[j]!='\0'; j++){
			if(apellido[j] != clientes[i].apellido[j]){
				mismoApellido = false;
				break;
			}
		}
		if(mismoApellido){
			encontrado = i;
			break;
		}
	}

	if(encontrado == -1){
		cout<<"Cliente no encontrado.\n";
	} else {
		int noches;
		cout<<"Ingrese cantidad de noches: ";
		while(!(cin>>noches) || noches <= 0){
			cout<<"Entrada inválida. Ingrese un número entero positivo: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}

		int piso = clientes[encontrado].piso;
		int precioPorNoche;

		if(piso == 1) precioPorNoche = 100;
		else if(piso == 2) precioPorNoche = 120;
		else precioPorNoche = 140;

		int total = precioPorNoche * noches;

		cout<<"Monto total a pagar: S/."<<total<<endl;
	}
	system("pause");
}
