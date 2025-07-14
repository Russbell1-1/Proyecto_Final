#ifndef MENU_H
#define MENU_H

// ======================
// Constantes del sistema
// ======================

const int FILAS=3;          // Número de pisos del hotel
const int COLUMNAS=4;       // Número de habitaciones por piso
const int MAX_CLIENTES=50;  // Número máximo de clientes que se pueden registrar


// ===========================
// Estructura de datos Cliente
// ===========================

struct Cliente{
	char nombre[30];
	char apellido[30];
	int edad;
	int piso;
	int habitacion;
};


// ==========================================
// Variables globales compartidas por módulos
// ==========================================

extern Cliente clientes[MAX_CLIENTES];      // Arreglo de clientes registrados
extern bool habitaciones[FILAS][COLUMNAS];  // Matriz que representa las habitaciones (ocupadas o libres)
extern int totalClientes;                   // Contador del total de clientes actuales

// ==================================
// Declaración de funciones del menú
// ==================================

void MostrarHabitacionesDisponibles();   // Muestra el estado actual de las habitaciones (libres/ocupadas)
void RegistrarHuesped();                 // Registra un nuevo huésped en el sistema
void MostrarBienvenida();                // Muestra mensaje de bienvenida (opcional)
void Menuinicial();                      // Muestra el menú principal y ejecuta las opciones
void ListarClientes();                   // Lista todos los clientes registrados
void BuscarHabitacion();                 // Permite buscar una habitación usando nombre y apellido
void ActualizarReserva();                // Permite modificar los datos de un cliente
void CalcularMonto();                    // Calcula el monto total a pagar por un cliente
void ListarHuespedesOrdenados();         // Lista los huéspedes en orden alfabético por apellido
void AnalisisDeDatos();                  // Muestra estadísticas y análisis de datos del sistema

#endif

