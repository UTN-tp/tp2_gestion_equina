#include "Usuario.h"
#include <cstring>  // para strncpy

// ======= GETTERS =======

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

// ======= SETTERS =======

void Usuario::setID(int valor) {
    id = valor;
}

void Usuario::setNombre(const char* valor) {
    if (valor != nullptr) {
        std::strncpy(nombre, valor, sizeof(nombre) - 1);
        nombre[sizeof(nombre) - 1] = '\0';
    } else {
        nombre[0] = '\0';
    }
}

void Usuario::setApellido(const char* valor) {
    if (valor != nullptr) {
        std::strncpy(apellido, valor, sizeof(apellido) - 1);
        apellido[sizeof(apellido) - 1] = '\0';
    } else {
        apellido[0] = '\0';
    }
}

void Usuario::setTelefono(const char* valor) {
    if (valor != nullptr) {
        std::strncpy(telefono, valor, sizeof(telefono) - 1);
        telefono[sizeof(telefono) - 1] = '\0';
    } else {
        telefono[0] = '\0';
    }
}

void Usuario::setEmail(const char* valor) {
    if (valor != nullptr) {
        std::strncpy(email, valor, sizeof(email) - 1);
        email[sizeof(email) - 1] = '\0';
    } else {
        email[0] = '\0';
    }
}

void Usuario::setEstado(bool valor) {
    estado = valor;
}


// ======= CARGAR =======
void Usuario::cargar() {
    cout << "=== CARGA DE USUARIO ===" << endl;

    cout << "ID: ";
    cin >> id;
    cin.ignore(); // limpia el salto de línea pendiente

    cout << "Nombre: ";
    cin.getline(nombre, sizeof(nombre));

    cout << "Apellido: ";
    cin.getline(apellido, sizeof(apellido));

    cout << "Telefono: ";
    cin.getline(telefono, sizeof(telefono));

    cout << "Email: ";
    cin.getline(email, sizeof(email));

    estado = true; // por defecto activo
}

// ======= MOSTRAR =======
void Usuario::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "Telefono: " << telefono << endl;
    cout << "Email: " << email << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
}