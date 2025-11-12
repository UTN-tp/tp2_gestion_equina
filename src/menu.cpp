#include <iostream>
#include <limits>
#include "Agenda.h"
#include "Cliente.h"
#include "CaballosManager.h"
#include "MaterialManager.h"
#include "Configuracion.h"
#include "InputManager.h"
#include "rlutil.h"

using namespace std;
void menuPrincipal();
void menuGestionClientes();
void menuGestionCaballos();
void menuGestionAgenda();
void menuGestionMateriales();
void menuGestionConfiguracion();

void menuPrincipal()
{

    int opcion;
    rlutil::setBackgroundColor(rlutil::DARKGREY);
    do
    {
        rlutil::cls();
        cout << "\n=== MENU PRINCIPAL GESTIONEQUINA ===" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Caballos" << endl;
        cout << "3. Agenda y Trabajos" << endl;
        cout << "4. Gestion de Materiales" << endl;
        cout << "5. Configuracion" << endl;
        cout << "0. Salir del Programa" << endl;
        cout << "=====================================" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion)
        {
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
            menuGestionConfiguracion();
            break;
        case 0:
            if(!InputManager::confirmar("Desea salir del programa? (S/N): "))
                   opcion = -1;
                   cout << "gracias por utilizar el programa" << endl;
            break;

        }
    }
    while (opcion != 0);
}


void menuGestionClientes()
{
    int opcion;
    Cliente accionesCliente;
    do
    {
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


        switch (opcion)
        {
        case 1:
            accionesCliente.cargar();
            rlutil::anykey();
            break;
        case 2:
            accionesCliente.editarPorID();
            rlutil::anykey();
            break;
        case 3:
           accionesCliente.buscarPorID();
           rlutil::anykey();
            break;
        case 4:
            accionesCliente.mostrarListado();
            rlutil::anykey();
            break;
        case 5:
            accionesCliente.cambiarEstadoPorID();
            rlutil::anykey();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;

        }
    }
    while (opcion != 9);
}


void menuGestionCaballos() {
    CaballosManager accionesCaballo;

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
                    accionesCaballo.cargarCaballo();
                }
                rlutil::anykey();
            break;
            case 2:
                rlutil::cls();
                accionesCaballo.modificarCaballo();
            break;
            case 3:
                 accionesCaballo.consultarPorID();
                 rlutil::anykey();
            break;
            case 4:
                 accionesCaballo.listarPorCliente();
                 rlutil::anykey();
            break;
            case 5:
                  accionesCaballo.listarTodos();
                  rlutil::anykey();
            break;
            case 6:
                 accionesCaballo.cambiarEstado();
                 rlutil::anykey();
                break;
            case 9:
                cout << "-> Volviendo al Menu Principal..." << endl;
                break;

        }
    } while (opcion != 9);
}



void menuGestionAgenda()
{
    int opcion;
    Agenda accionesAgenda;
    do
    {
        rlutil::cls();
        cout << "\n--- MENU AGENDA Y TRABAJOS ---" << endl;
        cout << "1. Registrar Nuevo Trabajo (Asociar a Caballo)" << endl;
        cout << "2. Ver Agenda de Proximos Trabajos" << endl;
        cout << "3. Consultar Historial de Trabajos Realizados" << endl;
        cout << "4. Buscar Trabajo por Fecha/Caballo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "------------------------------" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");


        switch (opcion)
        {
        case 1:
            accionesAgenda.registrarNuevoTrabajo();
            rlutil::anykey();
            break;
        case 2:
            accionesAgenda.proximosTrabajos();
            rlutil::anykey();
            break;
        case 3:
            accionesAgenda.historialTrabajosRealizados();
            rlutil::anykey();
            break;
        case 4:
            accionesAgenda.buscarTrabajo();
            rlutil::anykey();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;

        }
    }
    while (opcion != 9);
}

void menuGestionMateriales()
{
    int opcion;
    MaterialManager accionesMateriales;
    do
    {
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

        switch (opcion)
        {
        case 1:
            accionesMateriales.cargarNuevoMaterial();
            rlutil::anykey();
            break;
        case 2:
            accionesMateriales.modificarStock();
            rlutil::anykey();
            break;
        case 3:
            accionesMateriales.registrarMaterialesUsados();
            rlutil::anykey();
            break;
        case 4:
            accionesMateriales.consultarStockActual();
            rlutil::anykey();
            break;
        case 5:
            accionesMateriales.consultarConsumoPorPeriodo();
            rlutil::anykey();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;

        }
    }
    while (opcion != 9);
}

void menuGestionConfiguracion()
{
    Configuracion cfg;
    int opcion;
    do {
        rlutil::cls();
        cout << "\n=== MENU CONFIGURACION ===\n";
        cout << "1. Exportar datos (respaldo)\n";
        cout << "2. Importar datos\n";
        cout << "3. Generar CSV\n";
        cout << "9. Volver\n";
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion) {
        case 1: cfg.exportarDatos(); break;
        case 2: cfg.importarDatos(); break;
        case 3: {
                string nombreBin, nombreCSV;
                cout << "Archivo binario (ej: materiales.dat): ";
                cin >> nombreBin;
                cout << "Nombre CSV de salida (ej: materiales.csv): ";
                cin >> nombreCSV;
                cfg.generarCSV(nombreBin, nombreCSV);
                break;
        }
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;

        }

    } while (opcion != 9);
}
