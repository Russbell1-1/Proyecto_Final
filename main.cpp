#include <iostream>  // Librer�a para entrada y salida est�ndar
#include "Menu.h"    // Cabecera con funciones y estructuras del sistema

using namespace std;

// Punto de entrada principal del programa
int main(){
	MostrarBienvenida();   // Muestra mensaje de bienvenida al usuario
	Menuinicial();         // Llama al men� principal del sistema hotelero
	return 0;              // Finaliza el programa
}
