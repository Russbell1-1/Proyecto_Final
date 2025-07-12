#ifndef RESTAURANTE_H
#define RESTAURANTE_H

// Declaraciones de constantes
const int FILAS = 4;
const int COLUMNAS = 4;
const int pedidosmaximos = 50;

// Variables externas (definidas en Restaurante.cpp)
extern char mapaMesas[FILAS][COLUMNAS];
extern int cantPedidos;
extern string historialCliente[pedidosmaximos];
extern string historialHabitacion[pedidosmaximos];
extern string historialPedido[pedidosmaximos];
extern double historialMonto[pedidosmaximos];

// Declaración de funciones
void inicializarMesas();
void mostrarMapaMesas();
void agregarReserva();
void eliminarReserva();
void pedirACuarto(string& habitacion, string& cliente, string& pedido, double& montopedido);
void menuTrabajador();

#endif


