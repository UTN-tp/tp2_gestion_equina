#include "CaballosManager.h"
#include "InputManager.h"
#include "./Archivos.h"
#include <iostream>
#include <cstring>
using namespace std;

void CaballosManager::cargarCaballo() {
    Caballo c;
    Cliente cliente;



    int nuevoID = archivos.obtenerUltimoIDCaballo() + 1;
    c.setID(nuevoID);


    int idCliente;
    int idClienteCaballo;
    do {
        idCliente = InputManager::leerInt("ID Cliente: ");
        idClienteCaballo = cliente.buscarPorID(idCliente);

        if (idClienteCaballo != 0) {
            c.setIDCliente(idClienteCaballo);
        } else {
            cout << "No se encontró un cliente con el ID " << idCliente << ". Intente de nuevo.\n";
        }
    } while (idClienteCaballo == 0);




    string nombre = InputManager::leerString("Nombre: ");
    c.setNombre(nombre.c_str());

    int edad = InputManager::leerInt("Edad: ");
    c.setEdad(edad);

    string raza = InputManager::leerString("Raza: ");
    c.setRaza(raza.c_str());

    string tipo = InputManager::leerString("Tipo trabajo: ");
    c.setTipoTrabajo(tipo.c_str());

    // --- 3. Fechas ---
    Fecha fUltima;
    cout << "\nFecha de ultima atencion:" << endl;
    fUltima.cargar();
    c.setUltimaAtencion(fUltima.toString().c_str());


    Fecha fProxima;
    cout << "\nFecha de proxima atencion:" << endl;
    fProxima.cargar();
    c.setProximaAtencion(fProxima.toString().c_str());

    c.setEstado(true);


    cout << "\n--- CONFIRMAR DATOS DEL CABALLO ---\n";
    c.mostrar();
    cout << "-----------------------------------\n";

    if (!InputManager::confirmar("Desea guardar este caballo? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }

    archivos.guardarArchivoCaballo(c);
    cout << "Caballo cargado correctamente.\n";
}


void CaballosManager::modificarCaballo() {
    // Uso seguro de leerInt para el ID
    int id = InputManager::leerInt("Ingrese ID del caballo: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);

    c.mostrar();


    if (!InputManager::confirmar("Desea modificar este caballo? S/N: "))
        return;


    string nuevoNombre = InputManager::leerString("Nuevo nombre: ");
    c.setNombre(nuevoNombre.c_str());

    archivos.modificarRegistroCaballo(c, pos);
    cout << "Caballo modificado correctamente.\n";
}


void CaballosManager::consultarPorID() {
    // Uso seguro de leerInt para el ID
    int id = InputManager::leerInt("Ingrese ID: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);
    c.mostrar();
}


void CaballosManager::listarPorCliente() {

    int idC = InputManager::leerInt("ID Cliente: ");

    archivos.listarCaballosPorCliente(idC);
}


void CaballosManager::cambiarEstado() {

    int id = InputManager::leerInt("ID del caballo: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);
    c.mostrar();


    if(!InputManager::confirmar("Desea cambiar el estado de este caballo? (S/N): "))
        return;


    const char* estadosCaballo[] = {"Activo", "Inactivo", "Vendido"};
    int numEstados = 3;
    int nuevoEstado = InputManager::seleccionarOpcion("Seleccione la nueva opcion de estado (1-3): ", estadosCaballo, numEstados);


    bool estadoLogico = (nuevoEstado == 1); // 1 = Activo (true), 2 y 3 = Inactivo/Vendido (false)
    c.setEstado(estadoLogico);



    if (archivos.modificarRegistroCaballo(c, pos)) {
        cout << "El estado del caballo ID " << id << " fue modificado correctamente.\n";

        cout << "Nuevo estado: " << estadosCaballo[nuevoEstado - 1] << endl;
    } else {
        cout << "ERROR: No se pudo modificar el registro.\n";
    }

}

void CaballosManager::listarTodos() {
    archivos.listarTodosLosCaballos();

}
