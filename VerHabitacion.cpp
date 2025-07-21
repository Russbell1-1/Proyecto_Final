#include<iostream>
#include<cstdlib>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

void VerHabitacion(){
	if(totalClientes == 0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}

	// Mostrar ocupación por piso
	cout<<"Pisos ocupados:\n";
	bool hayOcupados=false;
	for(int piso=1;piso<=3;piso++){
		bool pisoOcupado=false;
		cout<<"Piso "<<piso<<": ";
		for(int i=0;i<totalClientes;i++){
			if(clientes[i].piso == piso){
				cout<<clientes[i].cuarto<<" ";
				pisoOcupado=true;
				hayOcupados=true;
			}
		}
		if(!pisoOcupado) cout<<"(sin ocupación)";
		cout<<endl;
	}
	if(!hayOcupados){
		cout<<"No hay habitaciones ocupadas.\n";
		system("pause");
		return;
	}

	// Solicitar piso y cuarto a buscar
	int piso, cuarto;
	cout<<"\nIngrese el piso (1-3): ";
	while(!(cin>>piso) || piso<1 || piso>3){
		cout<<"Entrada inválida. Ingrese un piso entre 1 y 3: ";
		cin.clear();
		cin.ignore(1000,'\n');
	}

	cout<<"Ingrese el número de cuarto (1-4): ";
	while(!(cin>>cuarto) || cuarto<1 || cuarto>4){
		cout<<"Entrada inválida. Ingrese un número de cuarto entre 1 y 4: ";
		cin.clear();
		cin.ignore(1000,'\n');
	}

	// Buscar cliente que esté en esa habitación
	bool encontrado=false;
	for(int i=0;i<totalClientes;i++){
		if(clientes[i].piso==piso && clientes[i].cuarto==cuarto){
			cout<<"\n--- Datos del cliente en Piso "<<piso<<", Cuarto "<<cuarto<<" ---\n";
			cout<<"Nombre: "<<clientes[i].nombre<<endl;
			cout<<"Apellido: "<<clientes[i].apellido<<endl;
			cout<<"DNI: "<<clientes[i].dni<<endl;
			cout<<"Edad: "<<clientes[i].edad<<endl;
			cout<<"Teléfono: "<<clientes[i].telefono<<endl;
			encontrado=true;
			break;
		}
	}

	if(!encontrado){
		cout<<"Esa habitación está libre o no ha sido registrada.\n";
	}
	system("pause");
}
