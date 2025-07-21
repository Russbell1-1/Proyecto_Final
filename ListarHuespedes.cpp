#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Accedemos a las variables globales del sistema
extern Cliente clientes[MAX_CLIENTES];         
extern int totalClientes;                      
extern bool habitaciones[FILAS][COLUMNAS];     


void ListarClientes(){
	if(totalClientes == 0){
		cout << "No hay clientes registrados.\n";
		system("pause");
		return;
	}

	cout << "=============================\n";
	cout << " Lista de Clientes Registrados\n";
	cout << "=============================\n";

	for(int i = 0; i < totalClientes; i++){
		// Validaciones por si algún dato fue mal ingresado (opcional pero útil en pruebas)
		if(clientes[i].edad < 0){
			cout << "[Advertencia] Cliente " << i+1 << " tiene una edad inválida.\n";
		}
		if(clientes[i].piso < 1 || clientes[i].piso > FILAS || clientes[i].habitacion < 1 || clientes[i].habitacion > COLUMNAS){
			cout << "[Advertencia] Cliente " << i+1 << " tiene una habitación fuera de rango.\n";
		}

		cout << "Cliente " << i+1 << ":\n";
		cout << "Nombre: " << clientes[i].nombre << "\n";
		cout << "Apellido: " << clientes[i].apellido << "\n";
		cout << "Edad: " << clientes[i].edad << "\n";
		cout << "Habitacion: Piso " << clientes[i].piso << ", Nro " << clientes[i].habitacion << "\n";
		cout << "--------------------------\n";
	}

	system("pause");
}
