#include "CaballosManager.h"
#include "InputManager.h"
#include "rlutil.h"
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

     // **USO DEL NUEVO METODO DE BUSQUEDA POR ID**
    int posCliente = archivos.buscarClientePorID(idC);
                                                                      // nuevo
     
    if (posCliente == -1) {
        cout << "ERROR: Cliente con ID " << idC << " no encontrado. Carga de caballo cancelada." << endl;
        return;
    }


    Cliente cliente = archivos.leerRegistroCliente(posCliente);

    
    if (cliente.getID() != idC) {
        cout << "ERROR interno al leer el registro del cliente." << endl;
        return;
    }

    c.setIDCliente(idC); 


    string nombre = InputManager::leerString("Nombre: ");
    c.setNombre(nombre.c_str());

    int edad = InputManager::leerInt("Edad: ");
    c.setEdad(edad);

    string raza = InputManager::leerString("Raza: ");
    c.setRaza(raza.c_str());


    Fecha fUltima;
    cout << "Fecha de ultima atencion: " << endl;
    fUltima.cargar();
    c.setUltimaAtencion(fUltima.toString().c_str());

    Fecha fProxima;
    cout << "Fecha de proxima atencion: " << endl;
    fProxima.cargar();
    c.setProximaAtencion(fProxima.toString().c_str());

    c.setEstado(true);
    rlutil::cls();
    rlutil::setColor(rlutil::BLACK);
    cout << "\n--- CONFIRMAR DATOS DEL CABALLO ---\n";
    rlutil::setColor(rlutil::WHITE);
    c.mostrar();
    cout << "-----------------------------------\n";

    if (!InputManager::confirmar("Desea guardar este caballo? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }

    archivos.guardarArchivoCaballo(c);
    
    
    int nuevaCantidad = cliente.getCantidadCaballos() + 1;
    cliente.setCantidadCaballos(nuevaCantidad); 

    
    if (archivos.modificarRegistroCliente(cliente, posCliente)) {
        cout << "Caballo cargado correctamente y la cantidad del cliente fue actualizada." << endl;
    } else {
        cout << "Caballo cargado correctamente, pero hubo un ERROR al actualizar la cantidad de caballos del cliente." << endl;
    }

}

void CaballosManager::modificarCaballo() {
    int id = InputManager::leerInt("Ingrese ID del caballo: ");

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        rlutil::setColor(rlutil::RED);
        cout << "Caballo no encontrado." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);

    c.mostrar();

    if (!InputManager::confirmar("Desea modificar este caballo? S/N: "))
        return;

    string nuevoNombre = InputManager::leerString("Nuevo nombre: ");
    c.setNombre(nuevoNombre.c_str());

    archivos.modificarRegistroCaballo(c, pos);
    rlutil::setColor(rlutil::GREEN);
    cout << "Caballo modificado correctamente." << endl;
    rlutil::setColor(rlutil::WHITE);
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

    rlutil::cls();
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
