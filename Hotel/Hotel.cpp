#include "Hotel.h"

// Esta función permite registrar un nuevo hotel ingresado por el usuario
void registrarHotel(Hotel hoteles[], int &n) {
    cout << "\n=== Registrar Nuevo Hotel ===\n";
    cout << "Nombre: ";
    cin >> hoteles[n].nombre;
    cout << "Direccion: ";
    cin >> hoteles[n].direccion;
    cout << "Estrellas (1 a 5): ";
    cin >> hoteles[n].estrellas;
    cout << "Precio por noche: ";
    cin >> hoteles[n].precio;
    n++;
}

// Muestra todos los hoteles registrados
void mostrarHoteles(const Hotel hoteles[], int n) {
    cout << "\n=== Lista de Hoteles ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << hoteles[i].nombre << ", "
             << hoteles[i].direccion << ", "
             << hoteles[i].estrellas << " estrellas, "
             << "S/." << hoteles[i].precio << endl;
    }
}