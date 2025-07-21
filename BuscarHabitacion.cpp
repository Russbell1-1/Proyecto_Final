#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void BuscarHabitacion(){
	
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}

	char nombreBuscado[30], apellidoBuscado[30];

	cin.ignore(); 
	cout<<"Ingrese el nombre del cliente: ";
	cin.getline(nombreBuscado,30);
	cout<<"Ingrese el apellido del cliente: ";
	cin.getline(apellidoBuscado,30);

	bool encontrado=false;

	// Búsqueda lineal en el arreglo de clientes
	for(int i=0;i<totalClientes;i++){
		bool coincideNombre=true;
		bool coincideApellido=true;

		// Comparar carácter por carácter el nombre
		for(int j=0;nombreBuscado[j]!='\0'||clientes[i].nombre[j]!='\0';j++){
			if(nombreBuscado[j]!=clientes[i].nombre[j]){
				coincideNombre=false;
				break;
			}
		}

		// Comparar carácter por carácter el apellido
		for(int j=0;apellidoBuscado[j]!='\0'||clientes[i].apellido[j]!='\0';j++){
			if(apellidoBuscado[j]!=clientes[i].apellido[j]){
				coincideApellido=false;
				break;
			}
		}

		// Si nombre y apellido coinciden, mostramos los datos del cliente
		if(coincideNombre&&coincideApellido){
			cout<<"Cliente encontrado:\n";
			cout<<"Nombre: "<<clientes[i].nombre<<"\n";
			cout<<"Apellido: "<<clientes[i].apellido<<"\n";
			cout<<"Edad: "<<clientes[i].edad<<"\n";
			cout<<"Habitacion: Piso "<<clientes[i].piso<<", Nro "<<clientes[i].habitacion<<"\n";
			encontrado=true;
			break;
		}
	}

	// Si no se encontró ningún cliente
	if(!encontrado){
		cout<<"No se encontro ningun cliente con ese nombre y apellido.\n";
	}
	system("pause");
}
