#include <iostream>
#include "Restaurante.h"
using namespace std;
// Se dividio en dos interfaces trabajador y huesped - ME TOCO TRABAJADOR A SI CAMBIARE DE PERSPECTIVA EN EL CPP

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
                break;
            case 2:  
                break;
            case 3: 
                break;
            case 4:
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
    menuTrabajador();
	return 0;
}