#include <iostream>  // Librería para entrada y salida estándar
#include "Menu.h"    // Cabecera con funciones y estructuras del sistema

using namespace std;

// Punto de entrada principal del programa
int main(){
	MostrarBienvenida();   // Muestra mensaje de bienvenida al usuario
	Menuinicial();         // Llama al menú principal del sistema hotelero
	return 0;              // Finaliza el programa
}
