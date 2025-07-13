#ifndef MENU_H
#define MENU_H

// Constantes
const int FILAS=3;
const int COLUMNAS=4;
const int MAX_CLIENTES=50;

// Estructura que se reutilizara
struct Cliente{
	char nombre[30];
	char apellido[30];
	int edad;
	int piso;
	int habitacion;
};

// Variables globales (declaradas externamente)
extern Cliente clientes[MAX_CLIENTES];
extern bool habitaciones[FILAS][COLUMNAS];
extern int totalClientes;

// Declaración de funciones
void MostrarHabitacionesDisponibles();
void RegistrarHuesped();
void MostrarBienvenida();
void Menuinicial();

#endif

