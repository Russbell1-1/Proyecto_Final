#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

void Menuinicial(){
	int rpta;
	do{
		cout<<" --- Bienvenido al Hotel ---\n";
		cout<<"1. Trabajor\n";
		cout<<"2. Cliente\n";
		cout<<"3. Salir\n";
		cout<<"Seleccione como desea ingresar al sistema:";
		cin>>rpta;
	} while(rpta!=3);
}
