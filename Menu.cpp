#include<iostream>
#include<windows.h>
#include "Menu.h"
#include "Restaurante.h"
using namespace std;

void Menuinicial(){
    int op;
    do{
        system("cls");

        cout<<"===== SISTEMA DE GESTION HOTELERA =====\n";
        cout<<"1. Reservar habitacion         \n";  
        cout<<"2. Listar habitaciones         \n";  
        cout<<"3. Buscar habitacion           \n";  
        cout<<"4. Actualizar datos de reserva \n";  
        cout<<"5. Calcular monto total        \n";  
        cout<<"6. Listar huespedes ordenados  \n";  
        cout<<"7. Analisis de datos           \n";  
        cout<<"8. Acceder al Restaurante      \n";  
        cout<<"9. Salir                       \n";
        cout<<"Seleccione una opcion: ";

        cin>>op;

        if(cin.fail()) {
            cin.clear(); // Limpia el error
            cin.ignore(1000, '\n'); // Descarta el resto de la línea
            cout<<"Error: Debe ingresar un numero\n";
            system("pause");
            continue; // Reinicia el bucle
        }

        if(op < 1 || op > 9){
            cout<<"Error: Opcion invalida\n";
            system("pause");
            continue;
        }

        switch(op){
            case 1: RegistrarHuesped(); break;
            case 2: ListarClientes(); break;
            case 3: BuscarHabitacion(); break;
            case 4: ActualizarReserva(); break;
            case 5: CalcularMonto(); break;
            case 6: ListarHuespedesOrdenados(); break;
            case 7: AnalisisDeDatos(); break;
            case 8: sistemaRestaurante(); break;
        }

    }while(op!=9);
}
