#include <iostream>
#include <limits> 
#include "CaballosManager.h"

using namespace std;
void menuPrincipal();
void menuGestionClientes();
void menuGestionCaballos();
void menuGestionAgenda();
void menuGestionMateriales();

void menuPrincipal() {
    int opcion;
    do {
        cout << "\n=== MENU PRINCIPAL GESTIONEQUINA ===" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Caballos" << endl;
        cout << "3. Agenda y Trabajos" << endl;
        cout << "4. Gestion de Materiales" << endl;
        cout << "5. algo que falte" << endl;
        cout << "0. Salir del Programa" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);
}


void menuGestionClientes() {
    int opcion;
    do {
        cout << "\n--- MENU GESTION DE CLIENTES ---" << endl;
        cout << "1. Cargar Nuevo Cliente" << endl;
        cout << "2. Modificar Datos de Cliente" << endl;
        cout << "3. Consultar Cliente por ID" << endl;
        cout << "4. Listar Todos los Clientes" << endl;
        cout << "5. Cambiar Estado del Cliente (Activo/Inactivo)" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "--------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: 
                 // Logica: CargarCliente()
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
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 9);
}



void menuGestionCaballos() {
    CaballosManager obj;
    int opcion;
    do {
        cout << "\n--- MENU GESTION DE CABALLOS ---" << endl;
        cout << "1. Cargar Nuevo Caballo (Asociado a Cliente)" << endl;
        cout << "2. Modificar Datos de Caballo" << endl;
        cout << "3. Consultar Caballo por ID" << endl;
        cout << "4. Listar Caballos de un Cliente" << endl;
        cout << "5. Cambiar Estado del Caballo (Activo/Inactivo/Vendido)" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "--------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                
                obj.cargarCaballo();
            break;
            case 2: 
                
                obj.modificarCaballo();
            break;
            case 3: 
                
                 obj.consultarPorID();
            break;
            case 4:
                
                 obj.listarPorCliente();
            break;
            case 5: 
                
                 obj.cambiarEstado();
            break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 9);
}


void menuGestionAgenda() {
    int opcion;
    do {
        cout << "\n--- MENU AGENDA Y TRABAJOS ---" << endl;
        cout << "1. Registrar Nuevo Trabajo (Asociar a Caballo)" << endl;
        cout << "2. Ver Agenda de Proximos Trabajos" << endl;
        cout << "3. Consultar Historial de Trabajos Realizados" << endl;
        cout << "4. Buscar Trabajo por Fecha/Caballo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
               // Logica: RegistrarTrabajo()
            break;
            case 2:
                // Logica: VerAgenda()
            break;
            case 3: 
                // Logica: ConsultarHistorialTrabajos()
            break;
            case 4: 
                // Logica: BuscarTrabajo()
            break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 9);
}

void menuGestionMateriales() {
    int opcion;
    do {
        cout << "\n--- MENU GESTION DE MATERIALES ---" << endl;
        cout << "1. Cargar Nuevo Material al Inventario" << endl;
        cout << "2. Modificar Stock de Material" << endl;
        cout << "3. Registrar Materiales Usados en un Trabajo" << endl;
        cout << "4. Consultar Stock Actual" << endl;
        cout << "5. Consultar Consumo por Periodo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "----------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 9);
}


