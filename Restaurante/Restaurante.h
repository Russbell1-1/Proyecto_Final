#ifndef RESTAURANTE_H
#define RESTAURANTE_H

using namespace std;

extern int mesasDisponibles;
extern char mapaMesas[4][4];
extern map<string, double> cuentasHabitacion;

const int pedidosMaximos = 50;
extern int cantPedidos;
extern string historialCliente[pedidosMaximos];
extern string historialHabitacion[pedidosMaximos];
extern string historialPedido[pedidosMaximos];
extern double historialMonto[pedidosMaximos];

// Declaracion de funciones
void mostrarMapaMesas();
void agregarReservaTrabajador();
void eliminarReservaTrabajador();
void pedirACuarto();
void verHistorialPedidos();
void menuTrabajador();

#endif
