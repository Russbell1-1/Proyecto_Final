#include<iostream>
#include<windows.h>
#include "Menu.h"
using namespace std;

void Menuinicial(){
    int op;
    do{
        system("cls");
        cout<<"===== SISTEMA DE GESTION HOTELERA =====\n";
        cout<<"1. Registrar huesped\n";
        cout<<"2. Reservar habitacion\n";
        cout<<"3. Listar habitaciones\n";
        cout<<"4. Buscar habitacion\n";
        cout<<"5. Actualizar datos de reserva\n";
        cout<<"6. Calcular monto total\n";
        cout<<"7. Listar huespedes ordenados\n";
        cout<<"8. Salir\n";
        cout<<"Seleccione una opcion: ";
        cin>>op;

        switch(op){
            case 1: RegistrarHuesped(); break;
            case 2: /*ReservarHabitacion();*/ break;
            case 3: /*ListarHabitaciones();*/ break;
            case 4: /*BuscarHabitacion();*/ break;
            case 5: /*ActualizarReserva();*/ break;
            case 6: /*CalcularMonto();*/ break;
            case 7: /*OrdenarHuespedes();*/ break;
        }
    }while(op!=8);
}
