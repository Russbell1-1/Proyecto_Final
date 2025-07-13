#include <iostream>
using namespace std;
// Se dividio en dos interfaces trabajador y huesped - ME TOCO TRABAJADOR A SI CAMBIARE DE PERSPECTIVA EN EL CPP

const int pedidosMaximos = 50;
int mesasDisponibles = 16; // Usando para igualar a funciones_separadas.cpp
char mapaMesas[4][4] = {
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'},
    {'D','D','D','D'}
}; 
//Como un restaurante de 16 mesas ( 4 x 4 = 16 )
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
            cout << mapaMesas[i][j] << "   "; // 'D' = Disponible | 'R' = Reservada 
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
    if (fila >= 0 && fila < 4 && columna >= 0 && columna < 4 && mapaMesas[fila][columna] == 'D'){
        mapaMesas[fila][columna] = 'R';
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

    if (mapaMesas[fila][columna] == 'R') {
        mapaMesas[fila][columna] = 'D';
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
void menuTrabajador(){
    int opcion;
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
    } while (opcion != 7);
}

int main(){
    menuTrabajador(); // Para testear 
	return 0;
}

