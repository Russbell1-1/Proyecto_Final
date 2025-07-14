#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include "Menu.h"
using namespace std;

// Accedemos a los datos globales de clientes
extern Cliente clientes[MAX_CLIENTES];
extern int totalClientes;

// Función que muestra estadísticas generales de los clientes
void MostrarEstadisticas(Cliente arr[], int cantidad){
	if(cantidad==0){
		cout<<"No hay datos para analizar.\n";
		return;
	}
	
	// Variables para calcular estadísticas
	int sumaEdad=0, mayorEdad=arr[0].edad, menorEdad=arr[0].edad;
	// Recorrido para encontrar sumatoria, menor y mayor edad
	for(int i=0;i<cantidad;i++){
		int e=arr[i].edad;
		sumaEdad+=e;
		if(e>mayorEdad)mayorEdad=e;
		if(e<menorEdad)menorEdad=e;
	}
	
	// Cálculo de estadísticas
	float promedio=(float)sumaEdad/cantidad;
	int precioPorHabitacion=150;
	int ingresosTotales=precioPorHabitacion*cantidad;
	float ocupacion=(float)cantidad/(FILAS*COLUMNAS)*100;

	// Mostramos estadísticas en formato decorativo
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

// Analiza datos generados aleatoriamente
void AnalisisDatosSimulados(){
	int cantidad=rand()%8+3; // Entre 3 y 10
	Cliente simulados[cantidad];

	// Se generan edades, pisos y habitaciones aleatorios
	for(int i=0;i<cantidad;i++){
		simulados[i].edad=rand()%50+18;
		simulados[i].piso=rand()%FILAS+1;
		simulados[i].habitacion=rand()%COLUMNAS+1;
	}
	cout<<"\nDatos simulados de "<<cantidad<<" clientes.\n";
	// Llama a la función para mostrar las estadísticas
	MostrarEstadisticas(simulados,cantidad);
	system("pause");
}

// Analiza los datos reales que se han ingresado al sistema
void AnalisisDatosIngresados(){
	if(totalClientes==0){
		cout<<"No hay clientes registrados.\n";
		system("pause");
		return;
	}
	MostrarEstadisticas(clientes,totalClientes);
	system("pause");
}

// Menú principal para acceder a las opciones de análisis de datos
void AnalisisDeDatos(){
	int opcion;
	do{
		system("cls");
		cout<<"+====================================================+\n";
		cout<<"¦                  ANALISIS DE DATOS                 ¦\n";
		cout<<"+====================================================+\n";
		cout<<"¦ 1. Analizar datos ingresados                       ¦\n";  // Usa los datos reales
		cout<<"¦ 2. Analizar datos simulados                        ¦\n";  // Usa datos aleatorios
		cout<<"¦ 3. Porcentaje de ocupacion del hotel               ¦\n";  // Muestra ocupación actual
		cout<<"¦ 4. Habitaciones disponibles                        ¦\n";  // Muestra cuántas están libres
		cout<<"¦ 5. Ingresos proyectados (clientes simulados)       ¦\n";  // Estima ingresos aleatorios
		cout<<"¦ 6. Volver al menu principal                        ¦\n";
		cout<<"+====================================================+\n";
		cout<<"Seleccione una opcion: ";
		cin>>opcion;

		// Llama a la opción correspondiente
		switch(opcion){
			case 1: AnalisisDatosIngresados();break;
			case 2: AnalisisDatosSimulados();break;
			case 3:{
				// Calcula ocupación actual
				float ocup=(float)totalClientes/(FILAS*COLUMNAS)*100;
				cout<<"Ocupacion actual: "<<ocup<<" %\n";
				system("pause");
				break;
			}
			case 4:{
				// Calcula habitaciones libres
				int libres=(FILAS*COLUMNAS)-totalClientes;
				cout<<"Total de habitaciones disponibles: "<<libres<<"\n";
				system("pause");
				break;
			}
			case 5:{
				// Estima ingresos aleatorios
				int randomClientes=rand()%10+5;
				int ingreso=randomClientes*150;
				cout<<"Proyeccion de ingresos para "<<randomClientes<<" clientes: S/."<<ingreso<<"\n";
				system("pause");
				break;
			}
		}
	}while(opcion!=6); // Repite hasta que el usuario elija volver
}
