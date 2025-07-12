#include <iostream>
#include "Restaurante.h"
using namespace std;

void gestionarMesa(){
    int opcion;
    do {
        cout << "==== GESTION DE MESAS ====";
        cout << "1. Crear mesas " << endl;
        cout << "2. Modificar mesas" << endl;    
        cout << "3. Asignar cliente a mesas" << endl;
        cout << "4. Unir o dividir mesas " << endl;
        cout << "5. Eliminar mesas" << endl;
        cout << "6. Ver mapa de mesas" << endl;
        cout << "7. Salir" << endl;
        
        cout << "Ingrese la opcion" << endl;
        cin >> opcion;

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
                break;
            case 6: 
                break;
            case 7: 
                cout << "Volviendo al menú principal...\n"; break;
            default: 
                cout << "Opción inválida.\n";
        }
    } while (opcion != 7);
}

int main(){
    gestionarMesa();
	return 0;
}