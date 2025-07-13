#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;
extern bool habitaciones[FILAS][COLUMNAS];

void ListarClientes(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		return;
		system("pause");
	}
	cout<<"Lista de Clientes Registrados:\n";
	for(int i=0;i<totalClientes;i++){
		cout<<"Cliente "<<i+1<<":\n";
		cout<<"Nombre: "<<clientes[i].nombre<<"\n";
		cout<<"Apellido: "<<clientes[i].apellido<<"\n";
		cout<<"Edad: "<<clientes[i].edad<<"\n";
		cout<<"Habitacion: Piso "<<clientes[i].piso<<", Nro "<<clientes[i].habitacion<<"\n";
		cout<<"--------------------------\n";
	}
			system("pause");

}
