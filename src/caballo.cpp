#include <cstring>
#include <iostream>
#include "Caballo.h"
#include "rlutil.h" //esta linea
using namespace std;

// Constructor
Caballo::Caballo() {
    id = 0;
    idCliente = 0;
    nombre[0] = {};
    edad = 0;
    raza[0] = {};
    ultimaAtencion[0] = {};
    proximaAtencion[0] = {};
    estado = 1; // esta linea faltaba

}

// Destructor
Caballo::~Caballo() {
}

// Getters
int Caballo::getID() const {
    return id;
}

int Caballo::getIDCliente() const {
    return idCliente;
}

const char* Caballo::getNombre() const {
    return nombre;
}

int Caballo::getEdad() const {
    return edad;
}

const char* Caballo::getRaza() const {
    return raza;
}


const char* Caballo::getUltimaAtencion() const {
    return ultimaAtencion;
}

const char* Caballo::getProximaAtencion() const {
    return proximaAtencion;
}

int Caballo::getEstado() const {     // esta linea
    return estado;
}


// Setters
void Caballo::setID(int valor) {
    id = valor;
}

void Caballo::setIDCliente(int valor) {
    idCliente = valor;
}

void Caballo::setNombre(const char* valor) {
    strncpy(nombre, valor, 19);
    nombre[19] = {};
}

void Caballo::setEdad(int valor) {
    edad = valor;
}

void Caballo::setRaza(const char* valor) {
    strncpy(raza, valor, 39);
    raza[39] = {};
}


void Caballo::setUltimaAtencion(const char* valor) {
    strncpy(ultimaAtencion, valor, 10);
    ultimaAtencion[10] = {};
}

void Caballo::setProximaAtencion(const char* valor) {
    strncpy(proximaAtencion, valor, 10);
    proximaAtencion[10] = {};
}

void Caballo::setEstado(int valor) {     // esta linea
    estado = valor;
}


// Mostrar
void Caballo::mostrar() const {
    rlutil::setColor(rlutil::BLACK);
    cout << "--- Datos del Caballo ---" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << "ID: " << getID() << endl;
    cout << "ID Cliente: " << getIDCliente() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Edad: " << getEdad() << " anios" << endl;
    cout << "Raza: " << getRaza() << endl;
    //cout << "Ultima Atencion: " << getUltimaAtencion() << endl;
    //cout << "Proxima Atencion: " << getProximaAtencion() << endl;
   // cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
   // cout << "-------------------------" << endl;
    cout << "Estado: ";
    switch (estado) {
        case 1:
            rlutil::setColor(rlutil::GREEN);       
            cout << "Activo" << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
        case 2:
            rlutil::setColor(rlutil::RED);
            cout << "Inactivo" << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
        case 3:
            rlutil::setColor(rlutil::BLACK);
            cout << "Vendido" << endl;
            rlutil::setColor(rlutil::WHITE);
            break;
        default:
            cout << "Desconocido (" << estado << ")" << endl;
            break;
    }

}



