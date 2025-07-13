#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <string>
using namespace std;

// Constantes
const int TAM = 10;
const int pedidosMaximos = 50;

// Variables globales
extern int mesasdisponibles;
extern char mesa[4][4];

extern int cant_entradas;
extern int cant_platos;
extern int cant_bebidas;
extern int cant_postres;

extern int cantPedidos;
extern int totalHabitaciones;

// Estructuras
struct Comida {
    char id;
    string nombre;
    float precio;
    int stock;
};

struct entradas {
    char id;
    string nombre;
    float precio;
    int stock;
};

struct platos {
    char id;
    string nombre;
    float precio;
    int stock;
};

struct bebidas {
    char id;
    string nombre;
    float precio;
    int stock;
};

struct postres {
    char id;
    string nombre;
    float precio;
    int stock;
};

struct HabitacionCuenta {
    string habitacion;
    double monto;
};

struct Pedido {
    string cliente;
    string habitacion;
    string descripcion;
    double monto;
};

// Funciones principales
void reservarmesa();
void ver_carta();
void ver_entradas();
void ver_platos();
void ver_bebidas();
void ver_postres();

// Funciones de administración
int seleccionar_tipo_comida();
void agregar_comida();
void modificar_comida();
void eliminar_comida();
void agregar_stock();

// Funciones trabajador
void mostrarMapaMesas();
void agregarReservaTrabajador();
void eliminarReservaTrabajador();
void pedirACuarto();
void verHistorialPedidos();
void verCuentasHabitaciones();

// Menús
void menu_administrador();
void menu_trabajador();
void menu_cliente();

#endif
