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

struct Comida {
    char id;
    string nombre;
    float precio;
    int stock;
};















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





//ADMINISTRADOR

int seleccionar_tipo_comida(){
	int tipo_opcion;

	cout<<"Seleccione tipo de comida para "<<endl;
    cout<<"1. Entradas"<<endl;
    cout<<"2. Platos"<<endl;
    cout<<"3. Bebidas"<<endl;
    cout<<"4. Postres"<<endl;
    cout<<"5. Salir"<<endl;
    cin >> tipo_opcion;
    if(tipo_opcion>=1 && tipo_opcion<=4){
    	return tipo_opcion;
	}else{
		cout << "Opción inválida."<<endl;
		return 0;
	}

}


void agregar_comida(){
	int tipo_comida=seleccionar_tipo_comida();
	if(tipo_comida==0){
		return;
	}
	

	
    char id;
    string nombre;
    float precio;
    int stock;
    
	cout<<"ID (una letra): ";
    cin>>id;
    cin.ignore();
    cout<<"Nombre: ";
    getline(cin, nombre);
    cout<<"Precio: ";
    cin>>precio;
    cout<<"Stock: ";
    cin>>stock;
    
    switch(tipo_comida){
        case 1:
            if(cant_entradas>=TAM){
                cout<<"Límite de entradas alcanzado"<<endl;
                return;
            }
            lista_entradas[cant_entradas++]={id, nombre, precio, stock};
            break;
        case 2:
            if(cant_platos>=TAM){
                cout<<"Límite de platos alcanzado"<<endl;
                return;
            }
            lista_platos[cant_platos++]={id, nombre, precio, stock};
            break;
        case 3:
            if(cant_bebidas>=TAM){
                cout<<"Límite de bebidas alcanzado"<<endl;
                return;
            }
            lista_bebidas[cant_bebidas++]={id, nombre, precio, stock};
            break;
        case 4:
            if(cant_postres>=TAM){
                cout<<"Límite de postres alcanzado"<<endl;
                return;
            }
            lista_postres[cant_postres++]={id, nombre, precio, stock};
            break;
    }
    
    cout<<"Comida agregada exitosamente"<<endl;
}

void modificar_comida(){
    int tipo_comida = seleccionar_tipo_comida();
    if (tipo_comida == 0) return;
    
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
    cout<<"ID no encontrado"<<endl;
}

void eliminar_comida(){
	int tipo_comida = seleccionar_tipo_comida();
    if (tipo_comida == 0) return;
    
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
    if (tipo_comida == 0) return;
    char id;
    int cantidad;
    cout << "Ingrese ID de la comida: ";
    cin >> id;

    switch(tipo_comida){
        case 1:
            for (int i = 0; i < cant_entradas; i++) {
                if (lista_entradas[i].id == id) {
                    cout << "¿Cuánto stock desea agregar?: ";
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
                    cout << "¿Cuánto stock desea agregar?: ";
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
                    cout << "¿Cuánto stock desea agregar?: ";
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
                    cout << "¿Cuánto stock desea agregar?: ";
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

// Se dividio en dos interfaces trabajador y huesped - ME TOCO TRABAJADOR A SI CAMBIARE DE PERSPECTIVA EN EL CPP

const int pedidosMaximos = 50;

//Estructura para el pago por habitacion
struct HabitacionCuenta {
    string habitacion;
    double monto;
};
// Cantidad max de habitaciones
HabitacionCuenta cuentas[100];
int totalHabitaciones = 0;

/*me recomendaron usar struct en ves de arreglo paralelo*/
struct Pedido {
    string cliente;
    string habitacion;
    string descripcion; // pedido pues
    double monto;
};
Pedido historial[pedidosMaximos]; 
int cantPedidos = 0;
/*---------------*/

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
    if (cantPedidos >= pedidosMaximos) {
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
        cout << "Sin registros.\n"; return;
        cout << endl;
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
                cout << "Opcion invalida. Intente de nuevo.\n";
                cout << endl;
                break;
        }
    } while (opcion_trabajador != 7);
}

void menu_administrador(){
	char menu_admin;
	do{
		cout<<"Seleccione la opcion"<<endl;
		cout<<"a. Agregar comida"<<endl;
		cout<<"b. Modificar comida"<<endl;
		cout<<"c. Eliminar comida"<<endl;
		cout<<"d. Agregar stock"<<endl;
		cout<<"e. Salir"<<endl;
		cin>>menu_admin;
	
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
	}while(menu_admin!='e');
}

void menu_cliente(){
	char menu_opcion;
	//Declaración de variable de menú
	char menu;
	
	//Bucle de menú del restaurante
	do{
		cout<<"INGRESE UNA OPCION"<<endl;
		cout<<"a) Ver carta"<<endl;
		cout<<"b) Reservar mesa"<<endl;
		cout<<"c) Administrador"<<endl;
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
				menu_administrador();
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

int main(){
	char menu_usuario_rest;
	cout<<"Ingrese el usuario: "<<endl;
	cout<<"a. Cliente"<<endl;
	cout<<"b. Trabajador"<<endl;
	cout<<"c. Administrador"<<endl;
	cin>>menu_usuario_rest;
	switch(menu_usuario_rest){
		case 'a':
			menu_cliente();
			break;
		case 'b':
			menu_trabajador();
			break;
		case 'c':
			menu_administrador();
			break;
		default:
			cout<<"ERROR: Ingrese una opcion valida"<<endl;
	}

	
	return 0;
}

