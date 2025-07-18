#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Variables externas que vienen de otro archivo del sistema
extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

// Funci�n que calcula el monto a pagar seg�n el n�mero de noches que se hospedar� el cliente
void CalcularMonto(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}
	
	char nombre[30], apellido[30];
	cin.ignore(); // Limpiar buffer
	// Se pide el nombre y apellido del cliente para buscarlo
	cout<<"Ingrese nombre del cliente: ";
	cin.getline(nombre,30);
	cout<<"Ingrese apellido del cliente: ";
	cin.getline(apellido,30);

	int encontrado=-1;
	// B�squeda por nombre y apellido
	for(int i=0;i<totalClientes;i++){
		bool mismoNombre=true;
		// Compara car�cter por car�cter el nombre
		for(int j=0;nombre[j]!='\0'||clientes[i].nombre[j]!='\0';j++){
			if(nombre[j]!=clientes[i].nombre[j]){
				mismoNombre=false;
				break;
			}
		}
		if(!mismoNombre)continue;

		bool mismoApellido=true;
		// Compara car�cter por car�cter el apellido
		for(int j=0;apellido[j]!='\0'||clientes[i].apellido[j]!='\0';j++){
			if(apellido[j]!=clientes[i].apellido[j]){
				mismoApellido=false;
				break;
			}
		}
		// Si nombre y apellido coinciden, guarda el �ndice del cliente
		if(mismoApellido){
			encontrado=i;
			break;
		}
	}
	
	// Si no se encontr� ning�n cliente con los datos ingresados
	if(encontrado==-1){
		cout<<"Cliente no encontrado.\n";
	}else{
		int noches;
		cout<<"Ingrese cantidad de noches: ";
		cin>>noches;
		if(noches<=0){
			cout<<"N�mero de noches inv�lido.\n";
			return;
		}
		// Se calcula el total a pagar
		int precioPorNoche=150;
		int total=precioPorNoche*noches;
		cout<<"Monto total a pagar: S/."<<total<<endl;
	}
	system("pause"); // Espera para que el usuario lea el resultado
}
