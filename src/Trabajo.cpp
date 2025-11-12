#include <iostream>
#include "Trabajo.h"
#include "Fecha.h"
#include "InputManager.h"
using namespace std;


int Trabajo::getID() const { return id; }
int Trabajo::getIdCliente() const { return idCliente; }
float Trabajo::getMonto() const { return monto; }
Fecha Trabajo::getFecha() const { return fechaTrabajo; }

void Trabajo::setID(int valor) { id = valor; }
void Trabajo::setIdCliente(int valor) { idCliente = valor; }
void Trabajo::setMonto(float valor) { monto = valor; }
void Trabajo::setFecha(const Fecha& f) { fechaTrabajo = f; }

void Trabajo::cargar() {
   if (!InputManager::confirmar("Desea cargar un trabajo? S/N: "))
        return;


    int id = InputManager::leerInt("ID Trabajo: ");
    int idCliente = InputManager::leerInt("ID Cliente: ");
    float monto = InputManager::leerFloat("Monto:$ ");

    cout << "Ingrese fecha del trabajo:\n";
    fechaTrabajo.cargar();
    if (!InputManager::confirmar("Desea guardar trabajo? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }
}

void Trabajo::mostrar() const {
    cout << "ID Trabajo: " << id << endl;
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Fecha: ";
    fechaTrabajo.mostrar();
    cout << endl;
}