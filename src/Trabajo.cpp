#include "Trabajo.h"
#include "Fecha.h"
#include <iostream>
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
    cout << "ID Trabajo: ";
    cin >> id;
    cout << "ID Cliente: ";
    cin >> idCliente;
    cout << "Monto: $";
    cin >> monto;

    cout << "Ingrese fecha del trabajo:\n";
    fechaTrabajo.cargar();
}

void Trabajo::mostrar() const {
    cout << "ID Trabajo: " << id << endl;
    cout << "ID Cliente: " << idCliente << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Fecha: ";
    fechaTrabajo.mostrar();
    cout << endl;
}