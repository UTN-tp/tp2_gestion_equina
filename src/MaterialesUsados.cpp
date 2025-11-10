#include "MaterialesUsados.h"
#include <iostream>
using namespace std;

// ======== GETTERS ========

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

// ======== SETTERS ========

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

// ======== MOSTRAR ========

void MaterialesUsados::mostrar() const {
    cout << "======================================" << endl;
    cout << "ID Material Usado: " << idMaterialUsado << endl;
    cout << "ID Trabajo:        " << idTrabajo << endl;
    cout << "ID Material:       " << idMaterial << endl;
    cout << "Cantidad:          " << cantidad << endl;
    cout << "======================================" << endl;
}