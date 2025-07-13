#include<iostream>
#include<windows.h>
#include "Menu.h"

using namespace std;

void MostrarBienvenida(){
	
	// Usar la funcion para cambiar de color la fuente
	HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,14); 
	system("cls");
	cout<<"+----------------------------------------------+\n";
	cout<<"¦                                              ¦\n";
	cout<<"¦         BIENVENIDO AL SISTEMA DEL HOTEL      ¦\n";
	cout<<"¦                                              ¦\n";
	cout<<"¦----------------------------------------------¦\n";
	cout<<"¦    Gestion de habitaciones y servicios       ¦\n";
	cout<<"¦    Atencion 24/7 - ¡Su comodidad primero!    ¦\n";
	cout<<"+----------------------------------------------+\n";
	
	SetConsoleTextAttribute(hConsole,15); // Restaurar color
	cout<<"\nPresione una tecla para continuar...";
	system("pause>nul");
}
