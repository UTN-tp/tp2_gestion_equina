#include <iostream>
using namespace std;
#include "Usuario.h"


int Usuario::getID() const {
    return id;
}

const char* Usuario::getNombre() const {
    return nombre;
}

const char* Usuario::getApellido() const {
    return apellido;
}

const char* Usuario::getTelefono() const {
    return telefono;
}

const char* Usuario::getEmail() const {
    return email;
}

bool Usuario::getEstado() const {
    return estado;
}

// --- SETTERS ---

void Usuario::setID(int valor) {
    id = valor;
}

void Usuario::setEstado(bool valor) {
    estado = valor;
}

void Usuario::setNombre(const char* valor) {

    strncpy(nombre, valor, 40);

    nombre[39] = '\0';
}

void Usuario::setApellido(const char* valor) {

    strncpy(apellido, valor, 40);

    apellido[39] = '\0';
}

void Usuario::setTelefono(const char* valor) {

    strncpy(telefono, valor, 20);

    telefono[19] = '\0';
}

void Usuario::setEmail(const char* valor) {

    strncpy(email, valor, 60);

    email[59] = '\0';
}
