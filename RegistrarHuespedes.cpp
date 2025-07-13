#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;



Cliente clientes[MAX_CLIENTES];
bool habitaciones[FILAS][COLUMNAS]={false}; // Todas libres al inicio
int totalClientes=0;

void MostrarHabitacionesDisponibles(){
	cout<<"Habitaciones disponibles (0=libre, 1=ocupada):\n";
	for(int i=0;i<FILAS;i++){
		cout<<"Piso "<<i+1<<": ";
		for(int j=0;j<COLUMNAS;j++){
			cout<<(habitaciones[i][j]?1:0)<<" ";
		}
		cout<<endl;
	}
}

void RegistrarHuesped(){
	if(totalClientes>=MAX_CLIENTES){
		cout<<"No se pueden registrar más clientes.\n";
		return;
	}
	
	Cliente nuevo;
	cout<<"Nombre: ";
	cin>>nuevo.nombre;
	cout<<"Apellido: ";
	cin>>nuevo.apellido;
	cout<<"Edad: ";
	cin>>nuevo.edad;
	
	MostrarHabitacionesDisponibles();
	
	int piso,habi;
	do{
		cout<<"Seleccione piso (1-"<<FILAS<<"): ";
		cin>>piso;
		cout<<"Seleccione habitacion (1-"<<COLUMNAS<<"): ";
		cin>>habi;
		
		if(piso<1||piso>FILAS||habi<1||habi>COLUMNAS){
			cout<<"Piso o habitacion fuera de rango.\n";
		}else if(habitaciones[piso-1][habi-1]){
			cout<<"Esa habitacion ya esta ocupada.\n";
		}else{
			break;
		}
	}while(true);
	
	nuevo.piso=piso;
	nuevo.habitacion=habi;
	habitaciones[piso-1][habi-1]=true;
	clientes[totalClientes]=nuevo;
	totalClientes++;
	
	cout<<"Cliente registrado correctamente.\n";
}
