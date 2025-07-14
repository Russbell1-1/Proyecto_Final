#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Variables externas que se usan para acceder a los datos del cliente y habitaciones
extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;
extern bool habitaciones[FILAS][COLUMNAS];

// Función que permite actualizar los datos de una reserva ya registrada
void ActualizarReserva(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		return;
	}

	// Se solicitan los datos del cliente a buscar
	char nombreBuscado[30], apellidoBuscado[30];
	cin.ignore();
	cout<<"Ingrese el nombre del cliente a actualizar: ";
	cin.getline(nombreBuscado,30);
	cout<<"Ingrese el apellido: ";
	cin.getline(apellidoBuscado,30);

	// Se busca al cliente en el arreglo
	int indice=-1;
	for(int i=0;i<totalClientes;i++){
		bool coincideNombre=true;
		bool coincideApellido=true;
		// Comparación de nombre
		for(int j=0;nombreBuscado[j]!='\0'||clientes[i].nombre[j]!='\0';j++){
			if(nombreBuscado[j]!=clientes[i].nombre[j]){
				coincideNombre=false;
				break;
			}
		}
		// Comparación de apellido
		for(int j=0;apellidoBuscado[j]!='\0'||clientes[i].apellido[j]!='\0';j++){
			if(apellidoBuscado[j]!=clientes[i].apellido[j]){
				coincideApellido=false;
				break;
			}
		}
		// Si el nombre y apellido coinciden, guardamos el índice del cliente
		if(coincideNombre&&coincideApellido){
			indice=i;
			break;
		}
	}

	if(indice==-1){
		cout<<"Cliente no encontrado.\n";
		return;
	}

	// Mostrar datos actuales del cliente
	cout<<"Cliente actual:\n";
	cout<<"Nombre: "<<clientes[indice].nombre<<"\n";
	cout<<"Apellido: "<<clientes[indice].apellido<<"\n";
	cout<<"Edad: "<<clientes[indice].edad<<"\n";
	cout<<"Habitación: Piso "<<clientes[indice].piso<<", Nro "<<clientes[indice].habitacion<<"\n";

	// Liberar habitación anterior
	habitaciones[clientes[indice].piso-1][clientes[indice].habitacion-1]=false;

	// Nuevos datos
	cout<<"\n--- Ingrese nuevos datos ---\n";
	cout<<"Nuevo nombre: ";
	cin.getline(clientes[indice].nombre,30);
	cout<<"Nuevo apellido: ";
	cin.getline(clientes[indice].apellido,30);
	cout<<"Nueva edad: ";
	cin>>clientes[indice].edad;

	MostrarHabitacionesDisponibles();
	int piso,habi;
	do{
		// Selección de nueva habitación
		cout<<"Seleccione nuevo piso (1-"<<FILAS<<"): ";
		cin>>piso;
		cout<<"Seleccione nueva habitacion (1-"<<COLUMNAS<<"): ";
		cin>>habi;

		// Validación de habitación
		if(piso<1||piso>FILAS||habi<1||habi>COLUMNAS){
			cout<<"Piso o habitación fuera de rango.\n";
		}else if(habitaciones[piso-1][habi-1]){
			cout<<"Esa habitación ya está ocupada.\n";
		}else{
			break;
		}
	}while(true);

	// Se actualizan los datos del cliente
	clientes[indice].piso=piso;
	clientes[indice].habitacion=habi;
	habitaciones[piso-1][habi-1]=true;

	cout<<"Datos del cliente actualizados correctamente.\n";
	system("pause");
}
