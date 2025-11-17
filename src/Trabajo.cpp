#include <iostream>
#include "Trabajo.h"
#include "Fecha.h"
#include "InputManager.h"
using namespace std;


int Trabajo::getID() const { return id; }
int Trabajo::getIdCliente() const { return idCliente; }
int Trabajo::getIdCaballo() const { return idCaballo; }
float Trabajo::getCosto() const { return costo; }
Fecha Trabajo::getFecha() const { return fechaTrabajo; }

void Trabajo::setID(int valor) { id = valor; }
void Trabajo::setIdCliente(int valor) { idCliente = valor; }
void Trabajo::setIdCaballo(int valor) { idCaballo = valor; }
void Trabajo::setCosto(float valor) { costo = valor; }
void Trabajo::setFecha(const Fecha& f) { fechaTrabajo = f; }

void Trabajo::cargar() {

    if (!InputManager::confirmar("Desea cargar un trabajo? S/N: "))
        return;


    int id = InputManager::leerInt("ID Trabajo: ");
    int idCliente = InputManager::leerInt("ID Cliente: ");
    int idCaballo = InputManager::leerInt("ID caballo: ");
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
    cout << "ID Caballo: " << idCaballo << endl;
    cout << "Monto: $" << costo << endl;
    cout << "Fecha: ";
    fechaTrabajo.mostrar();
    cout << endl;
}
