#include <iostream>
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
		char opcion;
	do{
        cout << "\n=== CARTA DEL RESTAURANTE ===\n";
		cout<<"A. Entradas"<<endl;
		cout<<"B. Platos"<<endl;
		cout<<"C. Bedidas"<<endl;
		cout<<"D. Postres"<<endl;
		cout<<"E. Salir"<<endl;
		cout<<"Seleccione una opcion : " ;
		cin>>opcion;
		switch(opcion){
		case 'A':
			//  Entradas
			ver_entradas();
			break;
		case 'B':
			//  Platos
			ver_platos();
			break;
		case 'C':
			//  Bebidas
			ver_bebidas();
			break;
		case 'D':
			//  Postres
			ver_postres();
			break;
		case 'E':
			//  Salir
			cout<<"Saliendo de la carta..."<<endl;
			break;	
		default:
			//  Repetir hasta elegir una opcion
			cout<<"ERROR: Eliga una categoria de la carta (A, B, C, D, E)"<<endl<<endl;
			break;
	}
	}while(opcion!='E');
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
        cout << "La mesa ya esta ocupada o reservada.\n";
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
        cout << endl;
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
        cout << endl;
        return;
    }

    for (int i = 0; i < totalHabitaciones; i++) {
        cout << "- Habitacion " << cuentas[i].habitacion;
        cout << ": S/ " << cuentas[i].monto << endl;
        cout << endl;
    }
}
void limpiacd(){
	system("pause");
    system("cls");  
}

void menu_trabajador(){
    char opcion_trabajador;
    do {
        cout << "====== MENU PRINCIPAL - TRABAJADOR ======\n" ;
        cout << "A. Mostrar mapa de mesas\n" ;
        cout << "B. Agregar reserva\n" ;
        cout << "C. Eliminar reserva\n" ;
        cout << "D. Recibir pedido a cuarto\n" ;
        cout << "E. Ver historial de pedidos\n" ;
        cout << "F. Ver montos por habitacion\n" ;
        cout << "G. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion_trabajador;
        switch (opcion_trabajador) {
            case 'A': 
                mostrarMapaMesas();
                limpiacd();               
                break;
            case 'B': 
                agregarReservaTrabajador();
                limpiacd();  
                break;
            case 'C': 
                eliminarReservaTrabajador(); 
                limpiacd(); 
                break;
            case 'D': 
                pedirACuarto();
                limpiacd(); 
                break;
            case 'E': 
                verHistorialPedidos();
                limpiacd(); 
                break;
            case 'F': 
                verCuentasHabitaciones();
                limpiacd(); 
                break;
            case 'G': 
                cout << endl;
                cout << "Saliendo del sistema del trabajador...\n";
                limpiacd(); 
                break;
            default: 
                cout << endl;
                cout<< "ERROR: OPCION INVALIDA (A, B, C, D, E, F, G)" <<endl<<endl;
                cout << endl;
                limpiacd(); 
                break;
        }
    } while (opcion_trabajador != 'G');
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
    cout << "Seleccione una opcion :";
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
                	cout<<"Nombre actual: "<<lista_entradas[i].nombre<<endl;
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_entradas[i].nombre);
                    cout<<"Precio actual: "<<lista_entradas[i].precio<<endl;
                    cout << "Nuevo precio: ";
                    cin >> lista_entradas[i].precio;
                    cout<<"Stock actual: "<<lista_entradas[i].stock<<endl;
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
                	cout<<"Nombre actual: "<<lista_platos[i].nombre<<endl;
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_platos[i].nombre);
                    cout<<"Precio actual: "<<lista_platos[i].precio<<endl;
                    cout << "Nuevo precio: ";
                    cin >> lista_platos[i].precio;
                    cout<<"Precio actual: "<<lista_platos[i].stock<<endl;
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
                	cout<<"Precio actual: "<<lista_bebidas[i].stock<<endl;
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_bebidas[i].nombre);
                    cout<<"Precio actual: "<<lista_bebidas[i].precio<<endl;
                    cout << "Nuevo precio: ";
                    cin >> lista_bebidas[i].precio;
                    cout<<"Precio actual: "<<lista_bebidas[i].stock<<endl;
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
                	cout<<"Precio actual: "<<lista_postres[i].stock<<endl;
                    cin.ignore();
                    cout << "Nuevo nombre: ";
                    getline(cin, lista_postres[i].nombre);
                    cout<<"Precio actual: "<<lista_postres[i].precio<<endl;
                    cout << "Nuevo precio: ";
                    cin >> lista_postres[i].precio;
                    cout<<"Precio actual: "<<lista_postres[i].stock<<endl;
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

void menu_administrador(){
	char menu_admin;
	do{
        cout << "=== MENU ADMINISTRADOR ===\n";
		cout<<"A. Ver carta"<<endl;
		cout<<"B. Agregar comida"<<endl;
		cout<<"C. Modificar comida"<<endl;
		cout<<"D. Eliminar comida"<<endl;
		cout<<"E. Agregar stock"<<endl;
		cout<<"F. Volver"<<endl;
		cout<<"Seleccione una opcion : ";
		cin>>menu_admin;
	
	switch (menu_admin){
			case 'A':
				//Ver carta
				ver_carta();
				limpiacd(); 
				break;
			case 'B':
				//Agregar comida
				agregar_comida();
				limpiacd(); 
				break;
			case 'C':
				//Modificar comida
				modificar_comida();
				limpiacd(); 
				break;
			case 'D':	
				//Eliminar comida
				eliminar_comida();
				limpiacd(); 
				break;
			case 'E':
				//Agregar stock
				agregar_stock();
				limpiacd(); 
				break;
			case 'F':
				//Salir del programa
				cout << endl;
                cout << "Saliendo del sistema del administrador...\n";
                limpiacd(); 
				break;	
			default:
				//Repetir menu hasta elegir una opcion
				cout<<"ERROR: Eliga una opcion del menu (A, B, C, D, E, F)"<<endl<<endl;
				limpiacd(); 
				break;
	}
	}while(menu_admin!='F');
}

void menu_cliente(){
	char menu_opcion;
	do{
		cout << "=== MENU CLIENTE ===\n";
        cout << "A. Ver carta\n";
        cout << "B. Reservar mesa\n";
        cout << "C. Volver\n";
        cout << "Seleccione una opcion: ";
        cin >> menu_opcion;
	
		switch (menu_opcion){
			case 'A':
				//Agregar un contacto
				ver_carta();
				limpiacd(); 
				break;
			case 'B':
				//Eliminar un contacto
				agregarReservaTrabajador();
				limpiacd(); 
				break;
			case 'C':
				//Salir del programa
				cout << endl;
				cout<<"Saliendo del sistema de cliente...." << endl;
				limpiacd(); 
				break;
			default:
				//Repetir menu hasta elegir una opcion
				cout << " ERROR: Eliga una opcion del menu (A, B, C)" <<endl <<endl;
				limpiacd(); 
				break;
	}
	}while(menu_opcion!= 'C');
}

void sistemaRestaurante(){
    inicializadorDatos();
	char menu_usuario_rest;
    do { 
	    cout<<"=== INGRESE EL USUARIO ==="<<endl;
	    cout<<"A. Cliente"<<endl;
	    cout<<"B. Trabajador"<<endl;
	    cout<<"C. Administrador"<<endl;
        cout<<"D. Salir " << endl;
        cout <<"Seleccione una opcion : " ;
	    cin>>menu_usuario_rest;
	    cout << endl;
	switch(menu_usuario_rest){
		case 'A':
			system("cls");
			menu_cliente();
			system("cls");
			break;
		case 'B':
			system("cls");
			menu_trabajador();
			system("cls");
			break;
		case 'C':
			system("cls");
			menu_administrador();
			system("cls");
			break;
        case 'D':
            cout << "Finalizando el programa" << endl;
            
            break;
		default:
			cout<<"ERROR: Ingrese una opcion valida"<<endl;
            break;
	}
    } while (menu_usuario_rest !='D');
}

int main(){
	sistemaRestaurante();
	return 0;
	}