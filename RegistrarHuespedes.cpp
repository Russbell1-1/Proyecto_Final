#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;



Cliente clientes[MAX_CLIENTES];
bool habitaciones[FILAS][COLUMNAS]={false}; // Todas libres al inicio
int totalClientes=0;

// Función que muestra el estado de todas las habitaciones (libres u ocupadas)
void MostrarHabitacionesDisponibles(){
	cout<<"Habitaciones disponibles (0=libre, 1=ocupada):\n";
	for(int i=0;i<FILAS;i++){
		cout<<"Piso "<<i+1<<": ";
		for(int j=0;j<COLUMNAS;j++){
			// Si la habitación está ocupada muestra 1, si está libre muestra 0
			cout<<(habitaciones[i][j]?1:0)<<" ";
		}
		cout<<endl;
	}
}

// Función que registra un nuevo huésped en el sistema
void RegistrarHuesped(){
	if(totalClientes>=MAX_CLIENTES){
		cout<<"No se pueden registrar más clientes.\n";
		return;
	}
	
	Cliente nuevo;
	cin.ignore(); // limpiar buffer para getline
	// Ingreso de datos del nuevo cliente
	cout<<"Nombre: ";
	cin.getline(nuevo.nombre,30);
	cout<<"Apellido: ";
	cin.getline(nuevo.apellido,30);
	cout<<"Edad: ";
	cin>>nuevo.edad;
	
	// Muestra las habitaciones antes de elegir una
	MostrarHabitacionesDisponibles();
	
	int piso,habi;
	do{
		cout<<"Seleccione piso (1-"<<FILAS<<"): ";
		cin>>piso;
		cout<<"Seleccione habitacion (1-"<<COLUMNAS<<"): ";
		cin>>habi;
		
		// Verifica que la habitación sea válida y esté libre
		if(piso<1||piso>FILAS||habi<1||habi>COLUMNAS){
			cout<<"Piso o habitacion fuera de rango.\n";
		}else if(habitaciones[piso-1][habi-1]){
			cout<<"Esa habitacion ya esta ocupada.\n";
		}else{
			break;
		}
	}while(true);
	
	// Guarda los datos del cliente y marca la habitación como ocupada
	nuevo.piso=piso;
	nuevo.habitacion=habi;
	habitaciones[piso-1][habi-1]=true;
	clientes[totalClientes]=nuevo;
	totalClientes++;
	
	cout<<"Cliente registrado correctamente.\n";
}
