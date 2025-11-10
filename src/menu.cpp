#include <iostream>
#include "Agenda.h"
#include "Cliente.h"
#include "CaballosManager.h"
#include "MaterialManager.h"
#include "Configuracion.h"

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
    do
    {
        cout << "\n=== MENU PRINCIPAL GESTIONEQUINA ===" << endl;
        cout << "1. Gestion de Clientes" << endl;
        cout << "2. Gestion de Caballos" << endl;
        cout << "3. Agenda y Trabajos" << endl;
        cout << "4. Gestion de Materiales" << endl;
        cout << "5. Configuracion" << endl;
        cout << "9. Salir del Programa" << endl;
        cout << "=====================================" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
        case 9:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 9);
}


void menuGestionClientes()
{
    int opcion;
    Cliente accionesCliente;
    do
    {
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

        switch (opcion)
        {
        case 1:
            accionesCliente.cargar();
            break;
        case 2:
            accionesCliente.editarPorID();
            break;
        case 3:
           accionesCliente.buscarPorID();
            break;
        case 4:
            accionesCliente.mostrarListado();
            break;
        case 5:
            accionesCliente.cambiarEstadoPorID();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 9);
}


void menuGestionCaballos()
{
    CaballosManager accionesCaballo;
    int opcion;
    do
    {
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

        switch (opcion)
        {
        case 1:

            accionesCaballo.cargarCaballo();
            break;
        case 2:

            accionesCaballo.modificarCaballo();
            break;
        case 3:

            accionesCaballo.consultarPorID();
            break;
        case 4:

            accionesCaballo.listarPorCliente();
            break;
        case 5:

            accionesCaballo.cambiarEstado();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
    while (opcion != 9);
}


void menuGestionAgenda()
{
    int opcion;
    Agenda accionesAgenda;
    do
    {
        cout << "\n--- MENU AGENDA Y TRABAJOS ---" << endl;
        cout << "1. Registrar Nuevo Trabajo (Asociar a Caballo)" << endl;
        cout << "2. Ver Agenda de Proximos Trabajos" << endl;
        cout << "3. Consultar Historial de Trabajos Realizados" << endl;
        cout << "4. Buscar Trabajo por Fecha/Caballo" << endl;
        cout << "9. Volver al Menu Principal" << endl;
        cout << "------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            accionesAgenda.registrarNuevoTrabajo();
            break;
        case 2:
            accionesAgenda.proximosTrabajos();
            break;
        case 3:
            accionesAgenda.historialTrabajosRealizados();
            break;
        case 4:
            accionesAgenda.buscarTrabajo();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
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

        switch (opcion)
        {
        case 1:
            accionesMateriales.cargarNuevoMaterial();
            break;
        case 2:
            accionesMateriales.modificarStock();
            break;
        case 3:
            accionesMateriales.registrarMaterialesUsados();
            break;
        case 4:
            accionesMateriales.consultarStockActual();
            break;
        case 5:
            accionesMateriales.consultarConsumoPorPeriodo();
            break;
        case 9:
            cout << "-> Volviendo al Menu Principal..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
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
        cout << "\n=== MENU CONFIGURACION ===\n";
        cout << "1. Exportar datos (respaldo)\n";
        cout << "2. Importar datos\n";
        cout << "3. Generar CSV\n";
        cout << "9. Volver\n";
        cout << "Opcion: ";
        cin >> opcion;

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
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 9);
}
