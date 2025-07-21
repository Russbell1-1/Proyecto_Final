#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
using namespace std;

// === CONSTANTES ===
const int ME_FILAS = 4;
const int ME_COLUMNAS = 4;
const int TAM = 10;
const int MAX_PEDIDOS = 50;

// === ESTRUCTURAS ===
struct Comida {
    char id;
    string nombre;
    float precio;
    int stock;
};
struct Pedido {
    string cliente;
    string habitacion;
    string descripcion;
    double monto;
};
struct HabitacionCuenta {
    string habitacion;
    double monto;
};

// === VARIABLES GLOBALES ===
extern Comida lista_entradas[TAM];
extern Comida lista_platos[TAM];
extern Comida lista_bebidas[TAM];
extern Comida lista_postres[TAM];

extern int cant_entradas;
extern int cant_platos;
extern int cant_bebidas;
extern int cant_postres;

extern char mesa[ME_FILAS][ME_COLUMNAS];
extern int MESASDISPONIBLES;

extern Pedido historial[MAX_PEDIDOS];
extern int cantPedidos;

extern HabitacionCuenta cuentas[100];
extern int totalHabitaciones;

// === FUNCIONES GENERALES ===
void sistemaRestaurante();
void inicializadorDatos();
int buscarHabitacion(const string& habitacion);
void mostrarItem(const Comida& item);

// === CLIENTE ===
void menu_cliente();
void ver_carta();
void ver_entradas();
void ver_platos();
void ver_bebidas();
void ver_postres();

// === TRABAJADOR ===
void menu_trabajador();
void mostrarMapaMesas();
void agregarReservaTrabajador();
void eliminarReservaTrabajador();
void pedirACuarto();
void verHistorialPedidos();
void verCuentasHabitaciones();

// === ADMINISTRADOR ===
void menu_administrador();
char seleccionar_tipo_comida();
void agregar_comida();
void modificar_comida();
void eliminar_comida();
void agregar_stock();

#endif