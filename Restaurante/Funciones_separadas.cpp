#include <iostream>
using namespace std;

const int TAM = 10;
int mesasdisponibles=16;

char mesa[4][4]={
	{'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'}
};



//ADMINISTRADOR

void administrador(){
	char menu_admin;
	do{
	cout<<"Seleccione la opcion"<<endl;
	cout<<"a. Agregar comida"<<endl;
	cout<<"b. Modificar comida"<<endl;
	cout<<"c. Eliminar comida"<<endl;
	cout<<"d. Agregar stock"<<endl;
	cout<<"e. Salir"<<endl;
	cin>>menu_admin;
	}while(menu_admin!='e');
	switch (menu_admin){
			case 'a':
				//Agregar comida
				agregar_comida();
				break;
			case 'b':
				//Modificar comida
				modificar_comida();
				break;
			case 'c':
				//Eliminar comida
				eliminar_comida();
				break;
			case 'd':
				//Agregar stock
				agregar_stock();
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




//RESERVAR MESA

void reservarmesa(){
	if(mesasdisponibles>0){
		cout<<"Ingrese la cantidad de personas"<<endl;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if (mesa[i][j]=='D'){
					mesa[i][j]='R';
					mesasdisponibles--;
					cout<<"Mesa "<<i<<","<<j<<"reservada"<<endl;
					return;
				}
			}
		}
	}else{
		cout<<"No hay mesas disponible para reservar"<<endl;
	}
}




//CARTA DE COMIDAS

struct entradas{
	char id;
	string nombre;
	float precio;
	int stock;
};

entradas lista_entradas[TAM]={

        {'A', "Ensalada", 10.00, 20},
        {'B', "Sopa", 10.00, 20},
        {'C', "Causa", 12.00, 20},
        {'D', "Ceviche", 15.00, 20},
        {'E', "Tamal", 5.00, 20}
    };
	int cant_entradas=5;
void ver_entradas(){
	cout<<"Listado de entradas disponibles:"<<endl;
    for(int i=0;i<cant_entradas;++i){
        cout<<"ID: "<<lista_entradas[i].id;
        cout<<", Nombre: "<<lista_entradas[i].nombre;
        cout<<", Precio: "<<lista_entradas[i].precio;
        cout<<", Stock: "<<lista_entradas[i].stock<<endl;
    }
}

struct platos{
	char id;
	string nombre;
	float precio;
	int stock;
};

platos lista_platos[TAM]={

        {'A', "Parillada", 20.00, 40},
        {'B', "Chaufa", 16.00, 40},
        {'C', "Lomo saltado", 18.00, 40},
        {'D', "Aji de gallina", 16.00, 40},
        {'E', "Spaggeti", 18.00, 40}
    };
	int cant_platos=5;
	
void ver_platos(){
	cout<<"Listado de platos disponibles:"<<endl;
    for(int i=0;i<cant_platos;++i){
        cout<<"ID: "<<lista_platos[i].id;
        cout<<", Nombre: "<<lista_platos[i].nombre;
        cout<<", Precio: "<<lista_platos[i].precio;
        cout<<", Stock: "<<lista_platos[i].stock<<endl;
    }	
}

struct bebidas{
	char id;
	string nombre;
	float precio;
	int stock;
};

bebidas lista_bebidas[TAM]={

        {'A', "Gaseosa 2L", 10.00, 40},
        {'B', "Jarra de jugo 1L", 12.00, 40},
        {'C', "Tasa de infusión", 6.00, 40},
        {'D', "Botella de vino", 16.00, 40},
        {'E', "Tasa de cafe", 8.00, 40}
    };
	int cant_bebidas=5;
	
void ver_bebidas(){
	cout<<"Listado de bebidas disponibles:"<<endl;
    for(int i=0;i<cant_bebidas;++i){
        cout<<"ID: "<<lista_bebidas[i].id;
        cout<<", Nombre: "<<lista_bebidas[i].nombre;
        cout<<", Precio: "<<lista_bebidas[i].precio;
        cout<<", Stock: "<<lista_bebidas[i].stock<<endl;
    }	
}

struct postres{
	char id;
	string nombre;
	float precio;
	int stock;
};

postres lista_postres[TAM]={

        {'A', "Tajada de torta", 7.00, 40},
        {'B', "Arroz con leche", 5.00, 40},
        {'C', "Mazamorra morada", 5.00, 40},
        {'D', "Brownie", 4.00, 40},
        {'E', "Helado", 8.00, 40}
    };
	int cant_postres=5;

void ver_postres(){
	cout<<"Listado de postres disponibles:"<<endl;
    for(int i=0;i<cant_postres;++i){
        cout<<"ID: "<<lista_postres[i].id;
        cout<<", Nombre: "<<lista_postres[i].nombre;
        cout<<", Precio: "<<lista_postres[i].precio;
        cout<<", Stock: "<<lista_postres[i].stock<<endl;
    }	
}


void ver_carta(){
	int ver_carta;
	do{
		cout<<"1. Entradas"<<endl;
		cout<<"2. Platos"<<endl;
		cout<<"3. Bedidas"<<endl;
		cout<<"4. Postres"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>ver_carta;
		switch(ver_carta){
		case 1:
			//Entradas
			ver_entradas();
			break;
		case 2:
			//Platos
			ver_platos();
			break;
		case 3:
			//Bebidas
			ver_bebidas();
			break;
		case 4:
			//Postres
			ver_postres();
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
		cout<<"a) Ver carta"<<endl;
		cout<<"b) Reservar mesa"<<endl;
		cout<<"c) "<<endl;
		cout<<"d) "<<endl;
		cout<<"e) Salir del programa"<<endl<<endl;
		cin>>menu_opcion;
	
		switch (menu_opcion){
			case 'a':
				//Agregar un contacto
				ver_carta();
				break;
			case 'b':
				//Eliminar un contacto
				reservarmesa();
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