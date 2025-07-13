#include <iostream>
#include <string>
#include <map>
#include "Restaurante.h"
using namespace std;
// Se dividio en dos interfaces trabajador y huesped - ME TOCO TRABAJADOR A SI CAMBIARE DE PERSPECTIVA EN EL CPP

int mesasDisponibles = 16; // Usando para igualar a funciones_separadas.cpp
char mapaMesas[4][4] = {
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'}
}; 
//Como un restaurante de 16 mesas ( 4 x 4 = 16 )
map<string, double> cuentasHabitacion;  

int cantPedidos = 0;
string historialCliente[pedidosMaximos];
string historialHabitacion[pedidosMaximos];
string historialPedido[pedidosMaximos];
double historialMonto[pedidosMaximos];

void mostrarMapaMesas() {
    cout << "  === MAPA DE MESAS ===  " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << mapaMesas[i][j] << " "; // 'D' = Disponible | 'R' = Reservada 
        }
        cout << endl;
    }
}

void agregarReservaTrabajador() { // Se agregara reservas atraves de saber la columna y fila
    int fila, columna; // una manera de guiarse seria sumar a la fila 1 y columna 1 cada vez osea son 16 mesas es decir fila 1 columna
    //1 
    cout << "Ingrese la fila (0-3): ";
    cin >> fila;
    cout << "Ingrese la columna (0-3): ";
    cin >> columna;
    if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4 && mapaMesas[fila][columna] == 'D'){
        mapaMesas[fila][columna] = 'R';
        cout << "Reserva agregada correctamente.\n";
    } else {
        cout << "La mesa ya está ocupada o reservada.\n";
    }
}

void eliminarReservaTrabajador() {
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

void pedirACuarto() {
    string habitacion, pedido, cliente;
    double montopedido;
    if (cantPedidos >= pedidosMaximos) {
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

    cuentasHabitacion[habitacion] += montopedido;

    historialCliente[cantPedidos] = cliente;
    historialHabitacion[cantPedidos] = habitacion;
    historialPedido[cantPedidos] = pedido;
    historialMonto[cantPedidos] = montopedido;
    cantPedidos++;

    cout << "\n==== BOLETA DEL PEDIDO ================================\n";
    cout << "Cliente: " << cliente << endl;
    cout << "Habitacion: " << habitacion << endl;
    cout << "Pedido: " << pedido << endl;
    cout << "Total: S/ " << montopedido << endl;
    cout << "=========================================================\n";
    cout << "S/ " << montopedido << " cargado a la habitacion " << habitacion << endl;
    cout << endl;
}

void verHistorialPedidos() {
    cout << "\n=== HISTORIAL DE PEDIDOS ===\n";
    if (cantPedidos == 0) {
        cout << "Sin registros.\n"; return;
    }

    for (int i = 0; i < cantPedidos; i++) {
        cout << i + 1 << ") Habitacion: " << historialHabitacion[i]
             << " | Pedido: " << historialPedido[i]
             << " | Monto: S/ " << historialMonto[i] << endl;
    }
}
void menuTrabajador(){
    int opcion;
    do {
        cout << "  === MENU TRABAJADOR ===  " << endl;
        cout << "1. Mostrar mapa de mesas" << endl;
        cout << "2. Agregar reserva "<< endl;
        cout << "3. Eliminar reserva " << endl;
        cout << "4. Recibir pedido a cuarto "<< endl;
        cout << "5. Ver historial de pedidos "<< endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion) {
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
                cout << "Saliendo del sistema del trabajador." << endl;
                break;
            default: 
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 6);
}

int main(){
    menuTrabajador(); // Para testear 
	return 0;
}

