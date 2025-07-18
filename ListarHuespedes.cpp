#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Accedemos a las variables globales del sistema
extern Cliente clientes[MAX_CLIENTES];         // Arreglo que guarda los datos de los clientes
extern int totalClientes;                      // Cantidad actual de clientes registrados
extern bool habitaciones[FILAS][COLUMNAS];     // Estado de ocupaci�n de habitaciones

// ===============================================
// Funci�n que muestra la lista de clientes activos
// ===============================================

void ListarClientes(){
	
	// Verifica si hay clientes registrados
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		return;
		system("pause"); // Esta l�nea no se ejecutar� por el return anterior
	}
	
	// T�tulo del listado
	cout << "=============================\n";
	cout << " Lista de Clientes Registrados\n";
	cout << "=============================\n";
	
	// Recorremos y mostramos la informaci�n de cada cliente
	for(int i=0;i<totalClientes;i++){
		cout<<"Cliente "<<i+1<<":\n";
		cout<<"Nombre: "<<clientes[i].nombre<<"\n";
		cout<<"Apellido: "<<clientes[i].apellido<<"\n";
		cout<<"Edad: "<<clientes[i].edad<<"\n";
		cout<<"Habitacion: Piso "<<clientes[i].piso<<", Nro "<<clientes[i].habitacion<<"\n";
		cout<<"--------------------------\n";
	}
			// Pausa para que el usuario lea la informaci�n mostrada
			system("pause");

}
