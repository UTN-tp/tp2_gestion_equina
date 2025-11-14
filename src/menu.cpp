#include <iostream>
#include <limits>
#include "CaballosManager.h"
#include "Agenda.h"
#include "Fecha.h"
#include "InputManager.h"
#include "rlutil.h"
#include "Cliente.h"

using namespace std;

void menuPrincipal();
void menuGestionClientes();
void menuGestionCaballos();
void menuGestionAgenda();
void menuGestionMateriales();

void menuPrincipal() {
    int opcion;
    rlutil::setBackgroundColor(rlutil::BROWN);
    do {
        rlutil::cls();
        cout << "\n=== MENU PRINCIPAL GESTIONEQUINA ===" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Caballos" << endl;
        cout << "3. Agenda y Trabajos" << endl;
        cout << "4. Gestion de Materiales" << endl;
        cout << "5. algo que falte" << endl;
        cout << "0. Salir del Programa" << endl;
        cout << "=====================================" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                menuGestionClientes();
                break;
            case 2:
                menuGestionCaballos();
                break;
            case 3:
                menuGestionAgenda();
                break;
            case 4:
                menuGestionMateriales();
                break;
            case 5:
                // para alguna opcion o algun otro menu
                break;
            case 0:
                if(!InputManager::confirmar("Desea salir del programa? (S/N): "))
                   opcion = -1;
                   cout << "gracias por utilizar el programa" << endl;
                break;

        }
    } while (opcion != 0);
}


void menuGestionClientes() {
    Cliente obj;
    int opcion;
    do {
        rlutil::cls();
        cout << "\n--- MENU GESTION DE CLIENTES ---" << endl;
        cout << "1. Cargar Nuevo Cliente" << endl;
        cout << "2. Modificar Datos de Cliente" << endl;
        cout << "3. Consultar Cliente por ID" << endl;
        cout << "4. Listar Todos los Clientes" << endl;
        cout << "5. Cambiar Estado del Cliente (Activo/Inactivo)" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "--------------------------------" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");
        switch (opcion) {
            case 1:

                 if (InputManager::confirmar("Cargar un nuevo cliente? (s/n): ")) {
                    rlutil::cls();
                    obj.agregarNuevoCliente ();
                }
                 cout << "Haga clic en cualquier tecla para volver al menu" << endl;
                 rlutil::anykey();

            break;
            case 2:
                 // Logica: ModificarCliente()
              break;
            case 3:
                 // Logica: ConsultarCliente()
              break;
            case 4:
                 // Logica: ListarClientes()
              break;
            case 5:
                // Logica: CambiarEstadoCliente()
              break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;

        }
    } while (opcion != 9);
}



void menuGestionCaballos() {
    CaballosManager manager;

    int opcion;
    do {
        rlutil::cls();
        cout << "\n--- MENU GESTION DE CABALLOS ---" << endl;
        cout << "1. Cargar Nuevo Caballo (Asociado a Cliente)" << endl;
        cout << "2. Modificar Datos de Caballo" << endl;
        cout << "3. Consultar Caballo por ID" << endl;
        cout << "4. Listar Caballos de un Cliente" << endl;
        cout << "5. Listar todos los caballos" << endl;
        cout << "6. Cambiar Estado del Caballo (Activo/Inactivo/Vendido)" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "--------------------------------" << endl;
        //cout << "Seleccione una opcion: ";
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
               if (InputManager::confirmar("Cargar un nuevo caballo? (s/n): ")) {
                    rlutil::cls();
                    manager.cargarCaballo();
                }
                rlutil::anykey();
            break;
            case 2:
                rlutil::cls();
                manager.modificarCaballo();
            break;
            case 3:
                 manager.consultarPorID();
                 rlutil::anykey();
            break;
            case 4:
                 manager.listarPorCliente();
                 rlutil::anykey();
            break;
            case 5:
                  manager.listarTodos();
                  rlutil::anykey();
            break;
            case 6:
                 manager.cambiarEstado();
                 rlutil::anykey();
                break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;

        }
    } while (opcion != 9);
}


void menuGestionAgenda() {
    int opcion;
    Agenda obj;
    do {
        rlutil::cls();
        cout << "\n--- MENU AGENDA Y TRABAJOS ---" << endl;
        cout << "1. Registrar Nuevo Trabajo (Asociar a Caballo)" << endl;
        cout << "2. Ver Agenda de Proximos Trabajos" << endl;
        cout << "3. Consultar Historial de Trabajos Realizados" << endl;
        cout << "4. Buscar Trabajo por Fecha/Caballo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "------------------------------" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                obj.registrarNuevoTrabajo();
            break;
            case 2:
                obj.proximosTrabajos();
            break;
            case 3:
                obj.historialTrabajosRealizados();
            break;
            case 4:
                obj.buscarTrabajo();
            break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;

        }
    } while (opcion != 9);
}

void menuGestionMateriales() {
    int opcion;
    do {
        rlutil::cls();
        cout << "\n--- MENU GESTION DE MATERIALES ---" << endl;
        cout << "1. Cargar Nuevo Material al Inventario" << endl;
        cout << "2. Modificar Stock de Material" << endl;
        cout << "3. Registrar Materiales Usados en un Trabajo" << endl;
        cout << "4. Consultar Stock Actual" << endl;
        cout << "5. Consultar Consumo por Periodo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "----------------------------------" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion) {
            case 1:
                // Logica: CargarMaterial()
            break;
            case 2:
                // Logica: ModificarStock()
            break;
            case 3:
                // Logica: RegistrarMaterialesTrabajo()
            break;
            case 4:
                // Logica: ConsultarStock()
            break;
            case 5:
                // Logica: ConsultarConsumoPeriodo()
            break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;

        }
    } while (opcion != 9);
}


