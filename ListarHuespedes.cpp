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
	}
	cout<<"\nLista de clientes registrados:\n";
	for(int i=0;i<totalClientes;i++){
		cout<<i+1<<". ";
		cout<<"Nombre: "<<clientes[i].nombre<<" ";
		cout<<clientes[i].apellido<<", Edad: "<<clientes[i].edad;
		cout<<", Piso: "<<clientes[i].piso<<", Habitación: "<<clientes[i].habitacion<<endl;
	}
}

