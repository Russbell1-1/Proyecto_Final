#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
using namespace std;

struct Hotel {
    string nombre;
    string direccion;
    int estrellas;
    float precio;
};

void registrarHotel(Hotel hoteles[], int &n);
void mostrarHoteles(const Hotel hoteles[], int n);

#endif