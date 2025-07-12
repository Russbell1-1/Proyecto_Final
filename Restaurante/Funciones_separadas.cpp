#include <iostream>
using namespace std;

int mesasdisponibles=16;

char mesa[4][4]={
	{'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'}
};

void reservarmesa(){
	if(mesasdisponibles>0){
		cout<<"Ingrese la cantidad de personas"<<endl;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if (mesa[i][j]=='D'){
					mesa[i][j]='R';
					mesasdisponibles--;
					cout<<"Mesa "<<i<<","<<j<<"reservada"<<endl;
				}return;
			}
		}
	}else{
		cout<<"No hay mesas disponible para reservar"<<endl;
	}
}



void ver_carta(){
	int ver_carta;
	do{
		cout<<"1. Entradas"<<endl;
		cout<<"2. Platos"<<endl;
		cout<<"3. Bedidas"<<endl;
		cout<<"4. Postres"<<endl;
		cin>>ver_carta;
		switch(ver_carta){
		case 1:
			//Entradas
			
			break;
		case 2:
			//Platos
			
			break;
		case 3:
			//Bebidas
			
			break;
		case 4:
			//Postres
			
			break;
		case 5:
			//Salir
			cout<<"Programa finalizado"<<endl;
			break;	
		default:
			//Repetir hasta elegir una opcion
			cout<<"ERROR: Eliga una categoría de la carta (1, 2, 3, 4, 5)"<<endl<<endl;
			break;
	}
	}while(ver_carta!=5);
}


int main(){
	char menu_opcion;
	//Declaración de variable de menú
	char menu;
	
	//Bucle de menú del restaurante
	do{
		cout<<"INGRESE UNA OPCION"<<endl;
		cout<<"a) T"<<endl;
		cout<<"b) Ver carta"<<endl;
		cout<<"c) Mostrar lista de contactos registrados"<<endl;
		cout<<"d) Mostrar contactos existentes, ordenado por correo"<<endl;
		cout<<"e) Salir del programa"<<endl<<endl;
		cin>>menu_opcion;
	
		switch (menu_opcion){
			case 'a':
				//Agregar un contacto
				reservarmesa();
				break;
			case 'b':
				//Eliminar un contacto
				ver_carta();
				break;
			case 'c':
				//Mostrar lista de contactos registrados
				
				break;
			case 'd':
				//Mostrar contactos existentes, ordenado por correo
				
				break;
			case 'e':
				//Salir del programa
				cout<<"Programa finalizado"<<endl;
				break;	
			default:
				//Repetir menu hasta elegir una opcion
				cout<<"ERROR: Eliga una opcion del menu (a, b, c, d, e)"<<endl<<endl;
				break;
	}
	}while(menu_opcion!='e');
}