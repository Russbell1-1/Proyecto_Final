#include<iostream>
#include<windows.h>
#include "Menu.h"
#include "Restaurante.h"
using namespace std;

// Esta función muestra el menú principal del sistema de gestión hotelera
void Menuinicial(){
    int op;
    do{
        system("cls"); // Limpia la pantalla en cada iteración del menú
        
        // Se muestran las opciones del sistema
        cout<<"===== SISTEMA DE GESTION HOTELERA =====\n";
        cout<<"1. Reservar habitacion\n";  // Registrar un nuevo huésped
        cout<<"2. Listar habitaciones\n";  // Ver huéspedes registrados
        cout<<"3. Buscar habitacion\n";    // Buscar habitación por nombre y apellido
        cout<<"4. Actualizar datos de reserva\n";  // Cambiar datos de un cliente
        cout<<"5. Calcular monto total\n";      // Calcular costo de la estadía
        cout<<"6. Listar huespedes ordenados\n";   // Mostrar huéspedes ordenados alfabéticamente
        cout<<"7. Analisis de datos\n";     // Mostrar estadísticas del sistema
        cout<<"8. Acceder al Restaurante\n";  // Ir al módulo de restaurante
        cout<<"9.Salir";    // Finalizar el programa
        cout<<"\nSeleccione una opcion: ";
        cin>>op;

        // Según la opción ingresada, se ejecuta una función específica
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
    }while(op!=9); // El menu se repite hasta que el usuario elija salir
}
