#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Variables externas declaradas en otro archivo
extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

// Función que ordena y muestra la lista de huéspedes por apellido alfabéticamente
void ListarHuespedesOrdenados(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}

	// Copiamos el arreglo original de clientes a otro para no modificar el original
	Cliente copia[MAX_CLIENTES];
	for(int i=0;i<totalClientes;i++)copia[i]=clientes[i];

	// Algoritmo de ordenamiento burbuja personalizado para ordenar por apellido
	for(int i=0;i<totalClientes-1;i++){
		for(int j=0;j<totalClientes-1-i;j++){
			int k=0;
			// Comparar letra por letra hasta que sean distintas o se acabe el apellido
			while(copia[j].apellido[k]==copia[j+1].apellido[k]&&copia[j].apellido[k]!='\0')k++;
			// Si el apellido actual es mayor, intercambiamos
			if(copia[j].apellido[k]>copia[j+1].apellido[k]){
				Cliente temp=copia[j];
				copia[j]=copia[j+1];
				copia[j+1]=temp;
			}
		}
	}

	// Mostramos la lista ordenada de huéspedes
	cout<<"Lista de Huespedes Ordenados por Apellido:\n";
	for(int i=0;i<totalClientes;i++){
		cout<<"Cliente "<<i+1<<":\n";
		cout<<"Nombre: "<<copia[i].nombre<<"\n";
		cout<<"Apellido: "<<copia[i].apellido<<"\n";
		cout<<"Edad: "<<copia[i].edad<<"\n";
		cout<<"Habitacion: Piso "<<copia[i].piso<<", Nro "<<copia[i].habitacion<<"\n";
		cout<<"--------------------------\n";
	}
	system("pause");
}
