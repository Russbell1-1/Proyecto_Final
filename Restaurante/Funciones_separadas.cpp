#include <iostream>
#include "Restaurante.h"
using namespace std;

// CONSTANTES
const int ME_FILAS = 4;
const int ME_COLUMNAS = 4;
const int TAM = 10;
const int MAX_PEDIDOS = 50; 
int MESASDISPONIBLES = 16; //Cantidad de mesas


// ESTRUCTURAS 
struct Comida {
    char id;
    string nombre;
    float precio;
    int stock;
};
struct Pedido {
    string cliente;
    string habitacion;
    string descripcion; // pedido pues
    double monto;
};
struct HabitacionCuenta {
    string habitacion;
    double monto;
};
struct entradas{
	char id;
	string nombre;
	float precio;
	int stock;
};

// VARIABLES
Comida lista_entradas[TAM];
Comida lista_platos[TAM];
Comida lista_bebidas[TAM];
Comida lista_postres[TAM];

int cant_entradas = 5;
int cant_platos = 5;
int cant_bebidas = 5;
int cant_postres = 5;

char mesa[ME_FILAS][ME_COLUMNAS]={
	{'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'}
};

HabitacionCuenta cuentas[100];
int totalHabitaciones = 0;

Pedido historial[MAX_PEDIDOS]; 
int cantPedidos = 0;

// Inicializadores

void inicializadorDatos(){
        Comida entradasIniciales[] = {
        {'A', "Ensalada", 10.00, 20},
        {'B', "Sopa", 10.00, 20},
        {'C', "Causa", 12.00, 20},
        {'D', "Ceviche", 15.00, 20},
        {'E', "Tamal", 5.00, 20}
    };
    
    for (int i = 0; i < 5; i++) {
        lista_entradas[i] = entradasIniciales[i];
    }
        Comida platosIniciales[] = {
        {'A', "Parillada", 20.00, 40},
        {'B', "Chaufa", 16.00, 40},
        {'C', "Lomo saltado", 18.00, 40},
        {'D', "Aji de gallina", 16.00, 40},
        {'E', "Spaghetti", 18.00, 40}
    };
    
    for (int i = 0; i < 5; i++) {
        lista_platos[i] = platosIniciales[i];
    }
        Comida bebidasIniciales[] = {
        {'A', "Gaseosa 2L", 10.00, 40},
        {'B', "Jarra de jugo 1L", 12.00, 40},
        {'C', "Tasa de infusión", 6.00, 40},
        {'D', "Botella de vino", 16.00, 40},
        {'E', "Tasa de cafe", 8.00, 40}
    };
    
    for (int i = 0; i < 5; i++) {
        lista_bebidas[i] = bebidasIniciales[i];
    }
        Comida postresIniciales[] = {
        {'A', "Tajada de torta", 7.00, 40},
        {'B', "Arroz con leche", 5.00, 40},
        {'C', "Mazamorra morada", 5.00, 40},
        {'D', "Brownie", 4.00, 40},
        {'E', "Helado", 8.00, 40}
    };
    
    for (int i = 0; i < 5; i++) {
        lista_postres[i] = postresIniciales[i];
    }
}
void mostrarItem(const Comida& item) {
    cout << "ID: " << item.id << ", Nombre: " << item.nombre 
         << ", Precio: S/" << item.precio << ", Stock: " << item.stock << endl;
}
void ver_entradas() {
    cout << "\n=== ENTRADAS DISPONIBLES ===\n";
    for (int i = 0; i < cant_entradas; i++) {
        mostrarItem(lista_entradas[i]);
    }
}
void ver_platos() {
    cout << "\n=== PLATOS PRINCIPALES ===\n";
    for (int i = 0; i < cant_platos; i++) {
        mostrarItem(lista_platos[i]);
    }
}
void ver_bebidas() {
    cout << "\n=== BEBIDAS ===\n";
    for (int i = 0; i < cant_bebidas; i++) {
        mostrarItem(lista_bebidas[i]);
    }
}
void ver_postres() {
    cout << "\n=== POSTRES ===\n";
    for (int i = 0; i < cant_postres; i++) {
        mostrarItem(lista_postres[i]);
    }
}
void ver_carta(){
	int opcion;
	do{
        cout << "\n=== CARTA DEL RESTAURANTE ===\n";
		cout<<"1. Entradas"<<endl;
		cout<<"2. Platos"<<endl;
		cout<<"3. Bedidas"<<endl;
		cout<<"4. Postres"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>opcion;
		switch(opcion){
		case 1:
			//  Entradas
			ver_entradas();
			break;
		case 2:
			//  Platos
			ver_platos();
			break;
		case 3:
			//  Bebidas
			ver_bebidas();
			break;
		case 4:
			//  Postres
			ver_postres();
			break;
		case 5:
			//  Salir
			cout<<" Programa finalizado "<<endl;
			break;	
		default:
			//  Repetir hasta elegir una opcion
			cout<<"ERROR: Eliga una categoria de la carta (1, 2, 3, 4, 5)"<<endl<<endl;
			break;
	}
	}while(opcion!=5);
}


int buscarHabitacion(const string& habitacion) {
    for (int i = 0; i < totalHabitaciones; ++i) {
        if (cuentas[i].habitacion == habitacion)
            return i;
    }
    return -1;
}
// Funcion mostrar mapa de mesas 
void mostrarMapaMesas() {
    cout << endl;
    cout << "====== MAPA DE MESAS ======\n";
    cout << endl;
    const string espacio = "       "; 
    for (int i = 0; i < 4; i++) {
        cout << espacio;
        for (int j = 0; j < 4; j++) {
            cout << mesa[i][j] << "   "; // 'D' = Disponible | 'R' = Reservada 
        }
        cout << endl << endl;
    }
}
// Funcion para agregar una reserva 
void agregarReservaTrabajador() { // Se agregara reservas atraves de saber la columna y fila
    cout << endl;
    cout << "====== AGREGAR RESERVA ======\n";
    int fila, columna; // una manera de guiarse seria sumar a la fila 1 y columna 1 cada vez osea son 16 mesas es decir fila 1 columna
    //1 
    cout << "\nIngrese la fila (0-3): ";
    cin >> fila;
    cout << "Ingrese la columna (0-3): ";
    cin >> columna;
    if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4 && mesa[fila][columna] == 'D'){
        mesa[fila][columna] = 'R';
        MESASDISPONIBLES--;
        cout << "Reserva agregada correctamente.\n";
    } else {
        cout << "La mesa ya está ocupada o reservada.\n";
    }
    cout << endl;
}
// Funcion para eliminar una reserva 
void eliminarReservaTrabajador() {
    cout << endl;
    cout << "====== ELIMINAR RESERVA ======\n";
    cout << endl;
    int fila, columna;
    cout << "Ingrese la fila (0-3): ";
    cin >> fila;
    cout << "Ingrese la columna (0-3): ";
    cin >> columna;

    if (mesa[fila][columna] == 'R') {
        mesa[fila][columna] = 'D';
        cout << "Reserva eliminada correctamente.\n";
    } else {
        cout << "No hay reserva en esa mesa.\n";
    }
    cout << endl;
}

void pedirACuarto() {
    cout << endl;
    cout << "====== PEDIDO A CUARTO ======\n" ;
    string habitacion, pedido, cliente;
    double montopedido;
    if (cantPedidos >= MAX_PEDIDOS) {
        cout << "No se pueden registrar mas pedidos.\n";
        cout << endl;
        return;
    }
    cout << "Ingrese numero de habitacion: ";
    cin >> habitacion;
    cin.ignore();
    cout << "Ingrese nombre del cliente: ";
    getline(cin, cliente);
    cout << "Ingrese el pedido a enviar: ";
    getline(cin, pedido);
    cout << "Ingrese el monto a cobrar: S/";
    cin >> montopedido;

    int idx = buscarHabitacion(habitacion);
    if (idx == -1) {
        cuentas[totalHabitaciones++] = {habitacion, montopedido};
    } else {
        cuentas[idx].monto += montopedido;
    }

    historial[cantPedidos] = {cliente, habitacion, pedido, montopedido};
    cantPedidos++;

    cout << "\n===== BOLETA DEL PEDIDO =====\n";
    cout << "Cliente: " << cliente << endl;
    cout << "Habitacion: " << habitacion << endl;
    cout << "Pedido: " << pedido << endl;
    cout << "Total: S/ " << montopedido << endl;
    cout << "S/ " << montopedido << " cargado a la habitacion " << habitacion << endl;
    cout << endl;
}

void verHistorialPedidos() {
    cout << endl;
    cout << "====== HISTORIAL DE PEDIDOS ======\n";
    cout << endl;
    if (cantPedidos == 0) {
        cout << "Sin registros.\n"; 
        return;
    }

    for (int i = 0; i < cantPedidos; i++) {
        cout << i + 1 << ") Habitacion: " << historial[i].habitacion;
        cout << " | Pedido: " << historial[i].descripcion;
        cout << " | Monto: S/ " << historial[i].monto << endl;
        cout << endl;
    }
}
void verCuentasHabitaciones() {
    cout << endl;
    cout << "====== MONTOS POR HABITACION ======\n";
    cout << endl;
    if (totalHabitaciones == 0) {
        cout << "No hay habitaciones registradas.\n";
        return;
    }

    for (int i = 0; i < totalHabitaciones; i++) {
        cout << "- Habitacion " << cuentas[i].habitacion;
        cout << ": S/ " << cuentas[i].monto << endl;
        cout << endl;
    }
}
void menu_trabajador(){
    int opcion_trabajador;
    do {
        cout << "====== MENU PRINCIPAL - TRABAJADOR ======\n" ;
        cout << "1. Mostrar mapa de mesas\n" ;
        cout << "2. Agregar reserva\n" ;
        cout << "3. Eliminar reserva\n" ;
        cout << "4. Recibir pedido a cuarto\n" ;
        cout << "5. Ver historial de pedidos\n" ;
        cout << "6. Ver montos por habitacion\n" ;
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion_trabajador;
        switch (opcion_trabajador) {
            case 1: 
                mostrarMapaMesas();
                break;
            case 2: 
                agregarReservaTrabajador();
                break;
            case 3: 
                eliminarReservaTrabajador(); 
                break;
            case 4: 
                pedirACuarto();
                break;
            case 5: 
                verHistorialPedidos();
                break;
            case 6: 
                verCuentasHabitaciones();
                break;
            case 7: 
                cout << endl;
                cout << "Saliendo del sistema del trabajador...\n";
                break;
            default: 
                cout << endl;
                cout<< "ERROR: Eliga una categoria de la carta (1, 2, 3, 4, 5, 6, 7)" <<endl<<endl;
                cout << endl;
                break;
        }
    } while (opcion_trabajador != 7);
}
//ADMINISTRADOR
int seleccionar_tipo_comida(){
    int opcion;
    cout << "Seleccione categoria: " << endl;
    cout << "1. Entradas" << endl;
    cout << "2. Platos" << endl;
    cout << "3. Bebidas" << endl;
    cout << "4. Postres" << endl;
    cout << "5. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 4) {
        return opcion;
    } else if (opcion == 5) {
        return 5; // Salida válida
    } else {
        cout << "ERROR: Opción inválida." << endl;
        return 0;
    }
}

void agregar_comida(){
    cout << "\n=== AGREGAR ITEM AL MENU ===\n";

	int tipo_comida = seleccionar_tipo_comida();
	if (tipo_comida == 0 || tipo_comida == 5){
        return; 
    } 
	
    Comida nuevoitem; 
    
	cout << "ID (una letra): ";
    cin >> nuevoitem.id;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nuevoitem.nombre);
    cout << "Precio: ";
    cin >> nuevoitem.precio;
    cout << "Stock: ";
    cin >> nuevoitem.stock;
    
    switch(tipo_comida){
        case 1:
            if(cant_entradas>=TAM){
                cout<<"Límite de entradas alcanzado"<<endl;
                return;
            }
            lista_entradas[cant_entradas++] = nuevoitem;
            break;
        case 2:
            if(cant_platos>=TAM){
                cout<<"Límite de platos alcanzado"<<endl;
                return;
            }
            lista_platos[cant_platos++] = nuevoitem;
            break;
        case 3:
            if(cant_bebidas>=TAM){
                cout<<"Límite de bebidas alcanzado"<<endl;
                return;
            }
            lista_bebidas[cant_bebidas++] = nuevoitem;
            break;
        case 4:
            if(cant_postres>=TAM){
                cout<<"Límite de postres alcanzado"<<endl;
                return;
            }
            lista_postres[cant_postres++] = nuevoitem;
            break;
    }
    
    cout<<" Comida agregada exitosamente "<<endl;
}

void modificar_comida(){
    int tipo_comida = seleccionar_tipo_comida();
	if (tipo_comida == 0 || tipo_comida == 5){
        return; 
    } 
    
	char id;
    cout<<"Ingrese ID de la comida a modificar: ";
    cin>>id;
    
    switch(tipo_comida){
       case 1:
            for(int i=0; i<cant_entradas; i++){
                if(lista_entradas[i].id == id){
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_entradas[i].nombre);
                    cout << "Nuevo precio: ";
                    cin >> lista_entradas[i].precio;
                    cout << "Nuevo stock: ";
                    cin >> lista_entradas[i].stock;
                    cout << "Comida modificada.\n";
                    return;
                }
            }
            break;
        case 2:
            for(int i=0; i<cant_platos; i++){
                if(lista_platos[i].id == id){
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_platos[i].nombre);
                    cout << "Nuevo precio: ";
                    cin >> lista_platos[i].precio;
                    cout << "Nuevo stock: ";
                    cin >> lista_platos[i].stock;
                    cout << "Comida modificada.\n";
                    return;
                }
            }
            break;
        case 3:
            for(int i=0; i<cant_bebidas; i++){
                if(lista_bebidas[i].id == id){
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_bebidas[i].nombre);
                    cout << "Nuevo precio: ";
                    cin >> lista_bebidas[i].precio;
                    cout << "Nuevo stock: ";
                    cin >> lista_bebidas[i].stock;
                    cout << "Comida modificada.\n";
                    return;
                }
            }
            break;
        case 4:
            for(int i=0; i<cant_postres; i++){
                if(lista_postres[i].id == id){
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_postres[i].nombre);
                    cout << "Nuevo precio: ";
                    cin >> lista_postres[i].precio;
                    cout << "Nuevo stock: ";
                    cin >> lista_postres[i].stock;
                    cout << "Comida modificada.\n";
                    return;
                }
            }
            break;
    }
    cout<< "ID no encontrado"<<endl;
}

void eliminar_comida(){
	int tipo_comida = seleccionar_tipo_comida();
	if (tipo_comida == 0 || tipo_comida == 5){
        return; 
    } 
    
    char id;
    cout<<"Ingrese ID de la comida a eliminar: ";
    cin>>id;
    
    switch(tipo_comida){
        case 1:
            for (int i = 0; i < cant_entradas; i++) {
                if (lista_entradas[i].id == id) {
                    lista_entradas[i] = lista_entradas[cant_entradas - 1];
                    cant_entradas--;
                    cout << "Comida eliminada.\n";
                    return;
                }
            }
            break;
        case 2:
            for (int i = 0; i < cant_platos; i++) {
                if (lista_platos[i].id == id) {
                    lista_platos[i] = lista_platos[cant_platos - 1];
                    cant_platos--;
                    cout << "Comida eliminada.\n";
                    return;
                }
            }
            break;
        case 3:
            for (int i = 0; i < cant_bebidas; i++) {
                if (lista_bebidas[i].id == id) {
                    lista_bebidas[i] = lista_bebidas[cant_bebidas - 1];
                    cant_bebidas--;
                    cout << "Comida eliminada.\n";
                    return;
                }
            }
            break;
        case 4:
            for (int i = 0; i < cant_postres; i++) {
                if (lista_postres[i].id == id) {
                    lista_postres[i] = lista_postres[cant_postres - 1];
                    cant_postres--;
                    cout << "Comida eliminada.\n";
                    return;
                }
            }
            break;
    }
    cout<<"ID no encontrado"<<endl;
}

void agregar_stock() {
    int tipo_comida = seleccionar_tipo_comida();
	if (tipo_comida == 0 || tipo_comida == 5){
        return; 
    } 
    char id;
    int cantidad;
    cout << "Ingrese ID de la comida: ";
    cin >> id;

    switch(tipo_comida){
        case 1:
            for (int i = 0; i < cant_entradas; i++) {
                if (lista_entradas[i].id == id) {
                    cout << "¿Cuanto stock desea agregar?: ";
                    cin >> cantidad;
                    lista_entradas[i].stock += cantidad;
                    cout << "Nuevo stock: " << lista_entradas[i].stock << endl;
                    return;
                }
            }
            break;
        case 2:
            for (int i = 0; i < cant_platos; i++) {
                if (lista_platos[i].id == id) {
                    cout << "¿Cuanto stock desea agregar?: ";
                    cin >> cantidad;
                    lista_platos[i].stock += cantidad;
                    cout << "Nuevo stock: " << lista_platos[i].stock << endl;
                    return;
                }
            }
            break;
        case 3:
            for (int i = 0; i < cant_bebidas; i++) {
                if (lista_bebidas[i].id == id) {
                    cout << "¿Cuanto stock desea agregar?: ";
                    cin >> cantidad;
                    lista_bebidas[i].stock += cantidad;
                    cout << "Nuevo stock: " << lista_bebidas[i].stock << endl;
                    return;
                }
            }
            break;
        case 4:
            for (int i = 0; i < cant_postres; i++) {
                if (lista_postres[i].id == id) {
                    cout << "¿Cuanto stock desea agregar?: ";
                    cin >> cantidad;
                    lista_postres[i].stock += cantidad;
                    cout << "Nuevo stock: " << lista_postres[i].stock << endl;
                    return;
                }
            }
            break;
    }

    cout << "ID no encontrado"<<endl;
}
//TRABAJADOR

void menu_administrador(){
	int menu_admin;
	do{
        cout << "\n=== MENU ADMINISTRADOR ===\n";
		cout<<"Seleccione la opcion"<<endl;
		cout<<"1. Agregar comida"<<endl;
		cout<<"2. Modificar comida"<<endl;
		cout<<"3. Eliminar comida"<<endl;
		cout<<"4. Agregar stock"<<endl;
		cout<<"5. Volver"<<endl;
		cin>>menu_admin;
	
	switch (menu_admin){
			case 1:
				//Agregar comida
				agregar_comida();
				break;
			case 2:
				//Modificar comida
				modificar_comida();
				break;
			case 3:
				//Eliminar comida
				eliminar_comida();
				break;
			case 4:
				//Agregar stock
				agregar_stock();
				break;
			case 5:
				//Salir del programa
				cout<<"Programa finalizado"<<endl;
				break;	
			default:
				//Repetir menu hasta elegir una opcion
				cout<<"ERROR: Eliga una opcion del menu (1, 2, 3, 4, 5)"<<endl<<endl;
				break;
	}
	}while(menu_admin!=5);
}

void menu_cliente(){
	int menu_opcion;
	do{
		cout << "\n=== MENU CLIENTE ===\n";
        cout << "1. Ver carta\n";
        cout << "2. Reservar mesa\n";
        cout << "3. Volver\n";
        cout << "Seleccione una opción: ";
        cin >> menu_opcion;
	
		switch (menu_opcion){
			case 1:
				//Agregar un contacto
				ver_carta();
				break;
			case 2:
				//Eliminar un contacto
				agregarReservaTrabajador();
				break;
			case 3:
				//Salir del programa
				cout<<"Programa finalizado"<<endl;
				break;	
			default:
				//Repetir menu hasta elegir una opcion
				cout << " ERROR: Eliga una opcion del menu (1, 2, 3)" <<endl <<endl;
				break;
	}
	}while(menu_opcion!= 3);
}

void sistemaRestaurante(){
    inicializadorDatos();
	int menu_usuario_rest;
    do { 
	    cout<<"Ingrese el usuario: "<<endl;
	    cout<<"1. Cliente"<<endl;
	    cout<<"2. Trabajador"<<endl;
	    cout<<"3. Administrador"<<endl;
        cout<<"4. Salir " << endl;
	    cin>>menu_usuario_rest;
	switch(menu_usuario_rest){
		case 1:
			menu_cliente();
			break;
		case 2:
			menu_trabajador();
			break;
		case 3:
			menu_administrador();
			break;
        case 4:
            cout << "Finalizando el programa" << endl;
            break;
		default:
			cout<<"ERROR: Ingrese una opcion valida"<<endl;
            break;
	}
    } while (menu_usuario_rest !=4);
}
