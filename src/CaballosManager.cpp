#include "CaballosManager.h"
#include "InputManager.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void CaballosManager::cargarCaballo() {


    Caballo caballo;
    Cliente cliente;

    int nuevoID = archivos.obtenerUltimoIDCaballo();
    caballo.setID(++nuevoID);
    cout << caballo.getID() << endl;
    int idCliente, posCliente;

    string email = "";



    if(idCliente == -1){
        cout << "Cliente inexistente." << endl;
        return;
    }

     while (true) {

        email = InputManager::leerLinea("Ingrese E-mail",60);

        idCliente = cliente.buscarClientePorEmail(email);

        if (idCliente == -1) {
            cout << "ERROR: No existe un cliente con ese ID." << endl;

            if (!InputManager::confirmar("Desea intentar con otro ID? (s/n): ")) {
                cout << "Carga cancelada." << endl;
                return;
            }
            continue;
        }
        else
            break;

    }


    cliente = archivos.leerRegistroCliente(idCliente);

    caballo.setIDCliente(cliente.getID());

    rlutil::setColor(rlutil::BLACK);


    // AGREGO ESTO
    rlutil::setColor(rlutil::BLACK);
    cout << "\n--- CARGA DE DATOS DEL CABALLO ---\n";
    rlutil::setColor(rlutil::WHITE);
    // HASTA ACA

    string nombre = InputManager::leerString("Nombre: ");
    caballo.setNombre(nombre.c_str());

    int edad = InputManager::leerInt("Edad: ");
    caballo.setEdad(edad);

    string raza = InputManager::leerString("Raza: ");
    caballo.setRaza(raza.c_str());


    caballo.setEstado(true);
    rlutil::cls();
    rlutil::setColor(rlutil::BLACK);
    cout << "\n--- CONFIRMAR DATOS DEL CABALLO ---\n";
    rlutil::setColor(rlutil::WHITE);
    caballo.mostrar();
    cout << "-----------------------------------\n";

    if (!InputManager::confirmar("Desea guardar este caballo? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }

    archivos.guardarArchivoCaballo(caballo);


    int nuevaCantidad = cliente.getCantidadCaballos() + 1;
    cliente.setCantidadCaballos(nuevaCantidad);


    if (archivos.modificarRegistroCliente(cliente, posCliente)) {
        cout << "Caballo cargado correctamente y la cantidad del cliente fue actualizada." << endl;
    } else {
        cout << "Caballo cargado correctamente, pero hubo un ERROR al actualizar la cantidad de caballos del cliente." << endl;
    }



}

void CaballosManager::modificarCaballo() {
  Cliente cliente;
    int idCliente = cliente.buscarClientePorEmail();

     if(idCliente == -1)
        return;

    cliente = archivos.leerRegistroCliente(idCliente);



    int cant = archivos.contarCaballosPorCliente(cliente.getID());
    if (cant == 0) {
        cout << "No hay caballos para este cliente.\n";
        return;
    }

    Caballo* caballos = new Caballo[cant];

    archivos.cargarCaballosPorCliente(cliente.getID(), caballos, cant);


    for (int i = 0; i < cant; i++) {
        cout << i + 1 << ") ";
        caballos[i].mostrar();
        cout << "--------------------\n";
    }

    int opcion;
    cout << "Seleccione el caballo a modificar (1-" << cant << "): ";
    cin >> opcion;

    if (opcion < 1 || opcion > cant) {
        cout << "Opcion invalida.\n";
        delete[] caballos;
        return;
    }

    Caballo& c = caballos[opcion - 1];

    if (!InputManager::confirmar("Desea modificar este caballo? (S/N): ")) {
        delete[] caballos;
        return;
    }

    cout << "\n--- MODIFICACION DE DATOS ---\n";


    if (InputManager::confirmar("Desea modificar el nombre? (S/N): ")) {
        string nombre = InputManager::leerString("Nombre: ");
        caballos[opcion - 1].setNombre(nombre.c_str());
    }

    if (InputManager::confirmar("Desea modificar la raza? (S/N): ")) {
        string raza = InputManager::leerString("Raza: ");
        caballos[opcion - 1].setRaza(raza.c_str());
    }

    if (InputManager::confirmar("Desea modificar la edad? (S/N): ")) {
        int edad = InputManager::leerInt("Edad: ");
        caballos[opcion - 1].setEdad(edad);
    }

    cout << "\n--- CABALLO MODIFICADO ---\n";
    caballos[opcion - 1].mostrar();

    int pos = archivos.buscarCaballoPorID(c.getID());

    if (archivos.modificarRegistroCaballo(caballos[opcion - 1], pos)) {
        cout << "modificado correctamente.\n";
    } else {
        cout << "ERROR al modificar el caballo.\n";
    }

    cout << "\nPresione ENTER para volver al menu...";
    cin.ignore();
    cin.get();


    delete[] caballos;
}



void CaballosManager::listarPorCliente() {

    Cliente cliente;

    int idCliente = cliente.buscarClientePorEmail();

   if(idCliente == -1)
        return;

    cliente = archivos.leerRegistroCliente(idCliente);

    archivos.listarCaballosPorCliente(cliente.getID());
}


void CaballosManager::cambiarEstado() {

    Cliente cliente;
    int idCliente = cliente.buscarClientePorEmail();

     if(idCliente == -1)
        return;

    cliente = archivos.leerRegistroCliente(idCliente);



    int cant = archivos.contarCaballosPorCliente(cliente.getID());
    if (cant == 0) {
        cout << "No hay caballos para este cliente.\n";
        return;
    }

    Caballo* caballos = new Caballo[cant];

    archivos.cargarCaballosPorCliente(cliente.getID(), caballos, cant);


    for (int i = 0; i < cant; i++) {
        cout << i + 1 << ") ";
        caballos[i].mostrar();
        cout << "--------------------\n";
    }

    int opcion;
    cout << "Seleccione el caballo a modificar (1-" << cant << "): ";
    cin >> opcion;

    if (opcion < 1 || opcion > cant) {
        cout << "Opcion invalida.\n";
        delete[] caballos;
        return;
    }



    if (!InputManager::confirmar("Desea cambiar el estado de este caballo? (S/N): ")) {
        delete[] caballos;
        return;
    }

    const char* estadosCaballo[] = {"Activo", "Inactivo", "Vendido"};
    int nuevoEstado = InputManager::seleccionarOpcion(
        "Seleccione la nueva opcion de estado (1-3): ",
        estadosCaballo, 3
    );

    caballos[opcion-1].setEstado(nuevoEstado);

    int pos = archivos.buscarCaballoPorID(caballos[opcion-1].getID());

    if (archivos.modificarRegistroCaballo(caballos[opcion - 1], pos)) {
        cout << "Estado modificado correctamente.\n";
    } else {
        cout << "ERROR al modificar el estado.\n";
    }

    delete[] caballos;
}
 // agrego 2
void CaballosManager::listarTodos() {
    archivos.listarTodosLosCaballos();

}
