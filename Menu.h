#ifndef MENU_H
#define MENU_H


// Constantes del sistema


const int FILAS=3;          // N�mero de pisos del hotel
const int COLUMNAS=4;       // N�mero de habitaciones por piso
const int MAX_CLIENTES=50;  // N�mero m�ximo de clientes que se pueden registrar



// Estructura de datos Cliente


struct Cliente{
	char nombre[30];
	char apellido[30];
	int edad;
	int piso;
	int habitacion;
};

// Variables globales compartidas por m�dulos

extern Cliente clientes[MAX_CLIENTES];      // Arreglo de clientes registrados
extern bool habitaciones[FILAS][COLUMNAS];  // Matriz que representa las habitaciones (ocupadas o libres)
extern int totalClientes;                   // Contador del total de clientes actuales


// Declaraci�n de funciones del men�


void MostrarHabitacionesDisponibles();   
void RegistrarHuesped();                 
void MostrarBienvenida();                
void Menuinicial();                      
void ListarClientes();                   
void BuscarHabitacion();                 
void ActualizarReserva();                
void CalcularMonto();                    
void ListarHuespedesOrdenados();         
void AnalisisDeDatos();                  
void VerHabitacion();

#endif

