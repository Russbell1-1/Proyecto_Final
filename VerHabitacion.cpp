#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void VerHabitacion(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}

	// Matriz temporal de ocupación
	bool ocupadas[3][4]={false};

	// Llenar matriz desde el arreglo de clientes
	for(int i=0;i<totalClientes;i++){
		int p=clientes[i].piso-1;
		int h=clientes[i].habitacion-1;
		if(p>=0 && p<3 && h>=0 && h<4){
			ocupadas[p][h]=true;
		}
	}

	// Mostrar matriz
	cout<<"--- Estado de habitaciones (X=ocupada, espacio=libre) ---\n";
	for(int piso=0;piso<3;piso++){
		cout<<"Piso "<<piso+1<<": ";
		for(int cuarto=0;cuarto<4;cuarto++){
			if(ocupadas[piso][cuarto]){
				cout<<"  1  ";
			}else{
				cout<<"  0  ";
			}
		}
		cout<<endl;
	}

	// Pedir ubicación
	int piso, cuarto;
	cout<<"\nIngrese el piso (1-3): ";
	while(!(cin>>piso) || piso<1 || piso>3){
		cout<<"Entrada invalida. Ingrese un piso entre 1 y 3: ";
		cin.clear();
		cin.ignore(1000,'\n');
	}

	cout<<"Ingrese el numero de cuarto (1-4): ";
	while(!(cin>>cuarto) || cuarto<1 || cuarto>4){
		cout<<"Entrada invalida. Ingrese un número de cuarto entre 1 y 4: ";
		cin.clear();
		cin.ignore(1000,'\n');
	}

	// Buscar cliente
	bool encontrado=false;
	for(int i=0;i<totalClientes;i++){
		if(clientes[i].piso==piso && clientes[i].habitacion==cuarto){
			cout<<"\n--- Cliente en Piso "<<piso<<", Cuarto "<<cuarto<<" ---\n";
			cout<<"Nombre: "<<clientes[i].nombre<<endl;
			cout<<"Apellido: "<<clientes[i].apellido<<endl;
			cout<<"Edad: "<<clientes[i].edad<<endl;
			encontrado=true;
			break;
		}
	}
	if(!encontrado){
		cout<<"\nEsa habitación está libre o no ha sido registrada.\n";
	}
	system("pause");
}
