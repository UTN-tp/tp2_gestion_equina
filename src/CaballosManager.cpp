#include "CaballosManager.h"
#include <iostream>
#include <cstring>
using namespace std;

void CaballosManager::cargarCaballo() {
    Caballo c;

    int nuevoID = archivos.cantidadRegistrosCaballo() + 1;
    c.setID(nuevoID);

    cout << "ID Cliente: ";
    int idC; 
    cin >> idC;
    c.setIDCliente(idC);

    char nombre[20];
    cout << "Nombre: ";
    cin >> nombre;
    c.setNombre(nombre);

    cout << "Edad: ";
    int edad;
     cin >> edad;
    c.setEdad(edad);

    char raza[40];
    cout << "Raza: ";
    cin >> raza;
    c.setRaza(raza);

    char tipo[30];
    cout << "Tipo trabajo: ";
    cin >> tipo;
    c.setTipoTrabajo(tipo);

    Fecha fUltima;
    cout << "\nFecha de ultima atencion:" << endl;
    fUltima.cargar();



    string sUltima = fUltima.toString();
    c.setUltimaAtencion(sUltima.c_str());


    Fecha fProxima;
    cout << "\nFecha de proxima atencion:" << endl;
    fProxima.cargar();

    string sProxima = fProxima.toString();
    c.setProximaAtencion(sProxima.c_str());

    c.setEstado(true);

    archivos.guardarArchivoCaballo(c);
    cout << "Caballo cargado correctamente.\n";
}


void CaballosManager::modificarCaballo() {
    int id;
    cout << "Ingrese ID del caballo: ";
    cin >> id;

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);

    char nuevoNombre[20];
    cout << "Nuevo nombre: ";
    cin >> nuevoNombre;
    c.setNombre(nuevoNombre);

    archivos.modificarRegistroCaballo(c, pos);
    cout << "Caballo modificado correctamente.\n";
}


void CaballosManager::consultarPorID() {
    int id;
    cout << "Ingrese ID: ";
    cin >> id;

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);
    c.mostrar();
}


void CaballosManager::listarPorCliente() {
    int idC;
    cout << "ID Cliente: ";
    cin >> idC;

    archivos.listarCaballosPorCliente(idC);
}


void CaballosManager::cambiarEstado() {
    int id;
    cout << "ID del caballo: ";
    cin >> id;

    int pos = archivos.buscarCaballoPorID(id);
    if (pos < 0) {
        cout << "Caballo no encontrado.\n";
        return;
    }

    Caballo c = archivos.leerRegistroCaballo(pos);

    cout << "1. Activo\n2. Inactivo\n3. Vendido\n";
    int op; 
    cin >> op;

    switch (op) {
        case 1: 
        c.setEstado(true);
         break;
        case 2: 
        c.setEstado(false);
         break;
        case 3: 
        c.setEstado(false); 
        break;
        default: cout << "Opción inválida."; return;
    }

    archivos.modificarRegistroCaballo(c, pos);
    cout << "Estado actualizado.\n";
}
