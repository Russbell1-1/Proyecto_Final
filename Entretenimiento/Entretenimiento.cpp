#include<iostream>
#include "CabeceraEntretenimiento.h"
using namespace std;

void OpcionBillar() {
    cout << "--- ÁREA DE BILLAR ---\n";
    cout << "Puede alquilar mesas de billar por hora.\n";
    cout << "Costo por hora: S/15.00\n";
    cout << "Horarios disponibles: 10:00 - 22:00\n";
}

void OpcionKaraoke() {
    cout << "--- ÁREA DE KARAOKE ---\n";
    cout << "Salas privadas disponibles para cantar con amigos.\n";
    cout << "Costo por hora: S/25.00\n";
    cout << "Incluye micrófonos, luces y bebidas sin alcohol.\n";
}

void OpcionCasino() {
    cout << "--- ÁREA DE CASINO ---\n";
    cout << "Juegos disponibles: Ruleta, Blackjack, Tragamonedas.\n";
    cout << "Recuerde jugar con responsabilidad.\n";
}

void OpcionCine() {
    cout << "--- SALA DE CINE ---\n";
    cout << "Películas del día: \n";
    cout << "Entrada general: S/12.00\n";
}

void MenuEntretinimiento() {
    int opcion;
    do {
        cout << "===== MENU DE ENTRETENIMIENTO =====" << endl;
        cout << "1. Billar" << endl;
        cout << "2. Karaoke" << endl;
        cout << "3. Casino" << endl;
        cout << "4. Cine" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1: OpcionBillar(); break;
            case 2: OpcionKaraoke(); break;
            case 3: OpcionCasino(); break;
            case 4: OpcionCine(); break;
            case 5: cout << "Saliendo del entretenimiento...\n"; break;
            default: cout << "Opción inválida. Intente nuevamente.\n";
        }

        cout << endl;
    } while(opcion != 5);
}
