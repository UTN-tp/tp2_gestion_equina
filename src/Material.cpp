#include "Material.h"
#include <iostream>
#include <cstring>
using namespace std;

// ======== GETTERS ========

int Material::getID() const {
    return id;
}

const char* Material::getNombre() const {
    return nombre;
}

const char* Material::getTipo() const {
    return tipo;
}

int Material::getStock() const {
    return stock;
}

float Material::getPrecio() const {
    return precio;
}

bool Material::getEstado() const {
    return estado;
}

// ======== SETTERS ========

void Material::setID(int valor) {
    id = valor;
}

void Material::setNombre(const char* valor) {
    if (valor != nullptr) {
        strncpy(nombre, valor, sizeof(nombre) - 1);
        nombre[sizeof(nombre) - 1] = '\0';
    } else {
        nombre[0] = '\0';
    }
}

void Material::setTipo(const char* valor) {
    if (valor != nullptr) {
        strncpy(tipo, valor, sizeof(tipo) - 1);
        tipo[sizeof(tipo) - 1] = '\0';
    } else {
        tipo[0] = '\0';
    }
}

void Material::setStock(int valor) {
    stock = valor;
}

void Material::setPrecio(float valor) {
    precio = valor;
}

void Material::setEstado(bool valor) {
    estado = valor;
}

// ======== MOSTRAR ========

void Material::mostrar() const {
    cout << "======================================" << endl;
    cout << "ID Material: " << id << endl;
    cout << "Nombre:      " << nombre << endl;
    cout << "Tipo:        " << tipo << endl;
    cout << "Stock:       " << stock << endl;
    cout << "Precio:      $" << precio << endl;
    cout << "Estado:      " << (estado ? "Activo" : "Inactivo") << endl;
    cout << "======================================" << endl;
}