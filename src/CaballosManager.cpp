#include "CaballosManager.h"
#include "InputManager.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void CaballosManager::cargarCaballo() {


    Caballo c;

     int nuevoID = archivos.obtenerUltimoIDCaballo() + 1;
    c.setID(nuevoID);

    int idC = InputManager::leerInt("ID Cliente: ");
    c.setIDCliente(idC);

    string nombre = InputManager::leerString("Nombre: ");
    c.setNombre(nombre.c_str());

    int edad = InputManager::leerInt("Edad: ");
    c.setEdad(edad);

    string raza = InputManager::leerString("Raza: ");
    c.setRaza(raza.c_str());

    string tipo = InputManager::leerString("Tipo trabajo: ");
    c.setTipoTrabajo(tipo.c_str());

    Fecha fUltima;
    cout << "Fecha de ultima atencion: " << endl;
    fUltima.cargar();
    c.setUltimaAtencion(fUltima.toString().c_str());

    Fecha fProxima;
    cout << "Fecha de proxima atencion: " << endl;
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
    cout << "Caballo cargado correctamente." << endl;
}


void CaballosManager::modificarCaballo() {
    int id = InputManager::leerInt("Ingrese ID del caballo: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado." << endl;
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);

    c.mostrar();

    if (!InputManager::confirmar("Desea modificar este caballo? S/N: "))
        return;

    string nuevoNombre = InputManager::leerString("Nuevo nombre: ");
    c.setNombre(nuevoNombre.c_str());

    archivos.modificarRegistroCaballo(c, pos);
    cout << "Caballo modificado correctamente." << endl;
}


void CaballosManager::consultarPorID() {
    int id = InputManager::leerInt("Ingrese ID: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado." << endl;
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
        cout << "Caballo no encontrado." << endl;
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);
    c.mostrar();

    if(!InputManager::confirmar("Desea cambiar el estado de este caballo? (S/N): "))
        return;

    const char* estadosCaballo[] = {"Activo", "Inactivo", "Vendido"};
    int numEstados = 3;
    int nuevoEstado = InputManager::seleccionarOpcion("Seleccione la nueva opcion de estado (1-3): ", estadosCaballo, numEstados);


    c.setEstado(nuevoEstado);


    if (archivos.modificarRegistroCaballo(c, pos)) {
        cout << "El estado del caballo ID " << id << " fue modificado correctamente." << endl;
        // Mostrar el nombre del estado seleccionado para confirmación
        cout << "Nuevo estado: " << estadosCaballo[nuevoEstado - 1] << endl;
    } else {
        cout << "ERROR: No se pudo modificar el registro." << endl;
    }

}
 // agrego 2
void CaballosManager::listarTodos() {
    archivos.listarTodosLosCaballos();

}