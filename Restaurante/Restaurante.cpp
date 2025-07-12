#include <iostream>
#include <string>
#include "Restaurante.h"
using namespace std;
// Se dividio en dos interfaces trabajador y huesped - ME TOCO TRABAJADOR A SI CAMBIARE DE PERSPECTIVA EN EL CPP

const int FILAS = 4; //Como un restaurante de 16 mesas ( 4 x 4 = 16 )
const int COLUMNAS = 4;
char mapaMesas[FILAS][COLUMNAS];

void inicializarMesas() { 
    for (int i = 0; i < FILAS; i++)
        for (int j = 0; j < COLUMNAS; j++)
            mapaMesas[i][j] = 'D'; // Todas las mesas disponibles al inicio
}

void mostrarMapaMesas() {
    cout << "  === MAPA DE MESAS ===  " << endl;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << mapaMesas[i][j] << " "; // 'D' = Disponible | 'R' = Reservada | 'O' = Ocupada
        }
        cout << endl;
    }
}

void agregarReserva() { // Se agregara reservas atraves de saber la columna y fila
    int fila, columna; // una manera de guiarse seria sumar a la fila 1 y columna 1 cada vez osea son 16 mesas es decir fila 1 columna
    //1 
    cout << "Ingrese la fila (0-3): ";
    cin >> fila;
    cout << "Ingrese la columna (0-3): ";
    cin >> columna;

    if (mapaMesas[fila][columna] == 'D') {
        mapaMesas[fila][columna] = 'R';
        cout << "Reserva agregada correctamente.\n";
    } else {
        cout << "La mesa ya está ocupada o reservada.\n";
    }
}

void eliminarReserva() {
    int fila, columna;
    cout << "Ingrese la fila (0-3): ";
    cin >> fila;
    cout << "Ingrese la columna (0-3): ";
    cin >> columna;

    if (mapaMesas[fila][columna] == 'R') {
        mapaMesas[fila][columna] = 'D';
        cout << "Reserva eliminada correctamente.\n";
    } else {
        cout << "No hay reserva en esa mesa.\n";
    }
}
int cantPedidos = 0;
const int pedidosmaximos = 50;
string historialCliente[pedidosmaximos];
string historialHabitacion[pedidosmaximos];
string historialPedido[pedidosmaximos];
double historialMonto[pedidosmaximos];


void pedirACuarto(string &habitacion, string &cliente, string &pedido, double & montopedido) {
    if (cantPedidos >= pedidosmaximos) {
        cout << "No se pueden registrar mas pedidos.\n";
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

    historialCliente[cantPedidos] = cliente;
    historialHabitacion[cantPedidos] = habitacion;
    historialPedido[cantPedidos] = pedido;
    historialMonto[cantPedidos] = montopedido;
    cantPedidos++;

    cout << "\nPedido '" << pedido << "' enviado a la habitacion " << habitacion << ".\n";
    cout << "\n==== BOLETA DEL PEDIDO ================================\n";
    cout << "Cliente: " << cliente << endl;
    cout << "Habitacion: " << habitacion << endl;
    cout << "Pedido: " << pedido << endl;
    cout << "Total: S/ " << montopedido << endl;
    cout << "=========================================================\n";

    cout << "---------------------------------------------------------" << endl; 
    /* No puedo agregar el monto a una habitacion ya que no se cuantas habitaciones habra por parte del hotel
    FALTA CORREGIR*/
    cout << "S/ " << montopedido << " cargado a la habitacion " << habitacion << endl;
    cout << endl;
}

void menuTrabajador(){
    int opcion;
    do {
        cout << "  === MENU TRABAJADOR ===  " << endl;
        cout << "1. Mostrar mapa de mesas" << endl;
        cout << "2. Agregar reserva "<< endl;
        cout << "3. Eliminar reserva " << endl;
        cout << "4. Recibir pedido a cuarto "<< endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        string habitacion, pedido, cliente;
        double montopedido;
        switch (opcion) {
            case 1: 
                mostrarMapaMesas(); 
                break;
            case 2: 
                agregarReserva(); 
                break;
            case 3: 
                eliminarReserva(); 
                break;
            case 4: 
                pedirACuarto(habitacion, pedido, cliente, montopedido);
                break;
            case 5: 
                cout << "Saliendo del sistema del trabajador." << endl;
                break;
            default: 
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 5);
}

int main(){
    inicializarMesas();
    menuTrabajador();
	return 0;
}