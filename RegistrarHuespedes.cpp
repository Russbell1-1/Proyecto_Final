#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

Cliente clientes[MAX_CLIENTES];
bool habitaciones[FILAS][COLUMNAS]={false};
int totalClientes=0;

void MostrarCuadroDePrecios(){
	cout << "\n+-------------------------------+\n";
	cout << "|     PRECIOS POR HABITACIÓN    |\n";
	cout << "+-------------------------------+\n";
	for(int i=0;i<FILAS;i++){
		cout << "| Piso " << i+1 << ": S/. " << (100 + i*20) << " por noche     |\n";
	}
	cout << "+-------------------------------+\n\n";
}

void MostrarHabitacionesDisponibles(){
	MostrarCuadroDePrecios(); // Agregado
	cout<<"\nEstado de habitaciones (0=Libre, 1=Ocupada):\n";
	for(int i=0;i<FILAS;i++){
		cout<<"Piso "<<i+1<<": ";
		for(int j=0;j<COLUMNAS;j++){
			cout<<(habitaciones[i][j]?1:0)<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void RegistrarHuesped(){
	if(totalClientes >= MAX_CLIENTES){
		cout<<"No se pueden registrar más clientes.\n";
		system("pause");
		return;
	}
	
	Cliente nuevo;
	cin.ignore();

	cout<<"Nombre: ";
	cin.getline(nuevo.nombre,30);
	cout<<"Apellido: ";
	cin.getline(nuevo.apellido,30);

	cout<<"Edad: ";
	while(!(cin >> nuevo.edad) || nuevo.edad <= 0){
		cout<<"Edad invalida. Intente nuevamente: ";
		cin.clear(); cin.ignore(1000,'\n');
	}
	
	MostrarHabitacionesDisponibles();
	int piso, habi;

	while(true){
		cout<<"Seleccione piso (1-" << FILAS << "): ";
		if(!(cin>>piso)){
			cout<<"Entrada invalida. Ingrese un numero.\n";
			cin.clear(); cin.ignore(1000,'\n');
			continue;
		}
		cout<<"Seleccione habitacion (1-" << COLUMNAS << "): ";
		if(!(cin>>habi)){
			cout<<"Entrada invalida. Ingrese un numero.\n";
			cin.clear(); cin.ignore(1000,'\n');
			continue;
		}
		
		if(piso<1 || piso>FILAS || habi<1 || habi>COLUMNAS){
			cout<<"Piso o habitacion fuera de rango.\n";
		}
		else if(habitaciones[piso-1][habi-1]){
			cout<<"Esa habitacion ya esta ocupada.\n";
		}
		else{
			break;
		}
	}

	nuevo.piso = piso;
	nuevo.habitacion = habi;
	habitaciones[piso-1][habi-1] = true;
	clientes[totalClientes++] = nuevo;

	cout<<"Cliente registrado correctamente.\n";
	system("pause");
}
