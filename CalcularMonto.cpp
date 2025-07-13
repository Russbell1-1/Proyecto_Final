#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void CalcularMonto(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}
	
	char nombre[30], apellido[30];
	cin.ignore(); // Limpiar buffer
	cout<<"Ingrese nombre del cliente: ";
	cin.getline(nombre,30);
	cout<<"Ingrese apellido del cliente: ";
	cin.getline(apellido,30);

	int encontrado=-1;
	for(int i=0;i<totalClientes;i++){
		bool mismoNombre=true;
		for(int j=0;nombre[j]!='\0'||clientes[i].nombre[j]!='\0';j++){
			if(nombre[j]!=clientes[i].nombre[j]){
				mismoNombre=false;
				break;
			}
		}
		if(!mismoNombre)continue;

		bool mismoApellido=true;
		for(int j=0;apellido[j]!='\0'||clientes[i].apellido[j]!='\0';j++){
			if(apellido[j]!=clientes[i].apellido[j]){
				mismoApellido=false;
				break;
			}
		}
		if(mismoApellido){
			encontrado=i;
			break;
		}
	}
	
	if(encontrado==-1){
		cout<<"Cliente no encontrado.\n";
	}else{
		int noches;
		cout<<"Ingrese cantidad de noches: ";
		cin>>noches;
		if(noches<=0){
			cout<<"Número de noches inválido.\n";
			return;
		}
		int precioPorNoche=150;
		int total=precioPorNoche*noches;
		cout<<"Monto total a pagar: S/."<<total<<endl;
	}
	system("pause");
}
