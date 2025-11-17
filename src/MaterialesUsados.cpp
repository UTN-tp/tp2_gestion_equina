#include "MaterialesUsados.h"
#include "Fecha.h"
#include <iostream>
#include <string>
using namespace std;

// ---------- GETTERS ----------
int MaterialesUsados::getIDMaterialUsado() const {
    return idMaterialUsado;
}

int MaterialesUsados::getIDTrabajo() const {
    return idTrabajo;
}

int MaterialesUsados::getIDMaterial() const {
    return idMaterial;
}

int MaterialesUsados::getCantidad() const {
    return cantidad;
}

Fecha MaterialesUsados::getFechaUso() const{
    return fechaUso;
}

// ---------- SETTERS ----------
void MaterialesUsados::setIDMaterialUsado(int valor) {
    idMaterialUsado = valor;
}

void MaterialesUsados::setIDTrabajo(int valor) {
    idTrabajo = valor;
}

void MaterialesUsados::setIDMaterial(int valor) {
    idMaterial = valor;
}

void MaterialesUsados::setCantidad(int valor) {
    cantidad = valor;
}

void MaterialesUsados::setFechaUso(const Fecha& valor){
    fechaUso = valor;
}

// ---------- METODO MOSTRAR ----------
void MaterialesUsados::mostrar() const {
    cout << "----------------------------------" << endl;
    cout << "ID Material Usado: " << idMaterialUsado << endl;
    cout << "ID Trabajo:        " << idTrabajo << endl;
    cout << "ID Material:       " << idMaterial << endl;
    cout << "Cantidad:          " << cantidad << endl;
    cout << "Fecha de uso:      " << fechaUso.toString() << endl;
}
