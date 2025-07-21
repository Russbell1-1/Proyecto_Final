#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include "Menu.h"
using namespace std;

extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

// Función que muestra estadísticas generales de los clientes
void MostrarEstadisticas(Cliente arr[], int cantidad){
	if(cantidad==0){
		cout<<"No hay datos para analizar.\n";
		return;
	}

	int sumaEdad=0, mayorEdad=arr[0].edad, menorEdad=arr[0].edad;
	for(int i=0;i<cantidad;i++){
		int e=arr[i].edad;
		sumaEdad+=e;
		if(e>mayorEdad)mayorEdad=e;
		if(e<menorEdad)menorEdad=e;
	}

	float promedio=(float)sumaEdad/cantidad;
	int precioPorHabitacion=150;
	int ingresosTotales=precioPorHabitacion*cantidad;
	float ocupacion=(float)cantidad/(FILAS*COLUMNAS)*100;

	cout<<"+-------------------------------------------------+\n";
	cout<<"¦           ESTADISTICAS DEL SISTEMA              ¦\n";
	cout<<"+-------------------------------------------------+\n";
	cout<<"¦ Total de clientes: "<<cantidad<<"\n";
	cout<<"¦ Edad minima: "<<menorEdad<<"\n";
	cout<<"¦ Edad maxima: "<<mayorEdad<<"\n";
	cout<<"¦ Edad promedio: "<<promedio<<"\n";
	cout<<"¦ Ingresos estimados: S/."<<ingresosTotales<<"\n";
	cout<<"¦ Porcentaje de ocupacion: "<<ocupacion<<" %\n";
	cout<<"¦ Habitaciones libres: "<<(FILAS*COLUMNAS - cantidad)<<"\n";
	cout<<"+-------------------------------------------------+\n";
}

// Genera datos aleatorios y analiza
void AnalisisDatosSimulados(){
	int cantidad=rand()%8+3;
	Cliente simulados[cantidad];

	for(int i=0;i<cantidad;i++){
		simulados[i].edad=rand()%50+18;
		simulados[i].piso=rand()%FILAS+1;
		simulados[i].habitacion=rand()%COLUMNAS+1;
	}
	cout<<"\nDatos simulados de "<<cantidad<<" clientes.\n";
	MostrarEstadisticas(simulados,cantidad);
	system("pause");
}

// Analiza los datos reales registrados
void AnalisisDatosIngresados(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}
	MostrarEstadisticas(clientes,totalClientes);
	system("pause");
}

// Menú principal con validación
void AnalisisDeDatos(){
	int opcion;

	do{
		system("cls");
		cout<<"+====================================================+\n";
		cout<<"¦                  ANALISIS DE DATOS                 ¦\n";
		cout<<"+====================================================+\n";
		cout<<"¦ 1. Analizar datos ingresados                       ¦\n";
		cout<<"¦ 2. Analizar datos simulados                        ¦\n";
		cout<<"¦ 3. Porcentaje de ocupacion del hotel               ¦\n";
		cout<<"¦ 4. Habitaciones disponibles                        ¦\n";
		cout<<"¦ 5. Ingresos proyectados (clientes simulados)       ¦\n";
		cout<<"¦ 6. Volver al menu principal                        ¦\n";
		cout<<"+====================================================+\n";

		cout<<"Seleccione una opcion: ";
		cin>>opcion;

		if(cin.fail()){
			cin.clear(); // limpia error
			cin.ignore(1000, '\n'); // descarta entrada inválida
			cout<<"Entrada invalida. Ingrese un numero entre 1 y 6.\n";
			system("pause");
			continue;
		}

		if(opcion<1 || opcion>6){
			cout<<"Opcion fuera de rango. Ingrese un numero entre 1 y 6.\n";
			system("pause");
			continue;
		}

		switch(opcion){
			case 1: AnalisisDatosIngresados(); break;
			case 2: AnalisisDatosSimulados(); break;
			case 3:{
				float ocup=(float)totalClientes/(FILAS*COLUMNAS)*100;
				cout<<"Ocupacion actual: "<<ocup<<" %\n";
				system("pause");
				break;
			}
			case 4:{
				int libres=(FILAS*COLUMNAS)-totalClientes;
				cout<<"Total de habitaciones disponibles: "<<libres<<"\n";
				system("pause");
				break;
			}
			case 5:{
				int randomClientes=rand()%10+5;
				int ingreso=randomClientes*150;
				cout<<"Proyeccion de ingresos para "<<randomClientes<<" clientes: S/."<<ingreso<<"\n";
				system("pause");
				break;
			}
		}

	}while(opcion!=6);
}

