#include <cstring>
#include <iostream>
#include "Caballo.h" 
using namespace std;


Caballo::Caballo() {
    id = 0;
    idCliente = 0;
    nombre[0] = '\0';
    edad = 0;
    raza[0] = '\0';
    tipoTrabajo[0] = '\0';
    ultimaAtencion[0] = '\0';
    proximaAtencion[0] = '\0';
    estado = true; 
}


Caballo::~Caballo() {
}


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

const char* Caballo::getTipoTrabajo() const {
    return tipoTrabajo;
}

const char* Caballo::getUltimaAtencion() const {
    return ultimaAtencion;
}

const char* Caballo::getProximaAtencion() const {
    return proximaAtencion;
}

bool Caballo::getEstado() const {
    return estado;
}


void Caballo::setID(int valor) {
    id = valor;
}

void Caballo::setIDCliente(int valor) {
    idCliente = valor;
}

void Caballo::setNombre(const char* valor) {
    strncpy(nombre, valor, 19);
    nombre[19] = '\0';
}

void Caballo::setEdad(int valor) {
    edad = valor;
}

void Caballo::setRaza(const char* valor) {
    strncpy(raza, valor, 39);
    raza[39] = '\0';
}

void Caballo::setTipoTrabajo(const char* valor) {
    strncpy(tipoTrabajo, valor, 29);
    tipoTrabajo[29] = '\0';
}

void Caballo::setUltimaAtencion(const char* valor) {
    strncpy(ultimaAtencion, valor, 10);
    ultimaAtencion[10] = '\0';
}

void Caballo::setProximaAtencion(const char* valor) {
    strncpy(proximaAtencion, valor, 10);
    proximaAtencion[10] = '\0';
}

void Caballo::setEstado(bool valor) {
    estado = valor;
}


void Caballo::mostrar() const {
    cout << "--- Datos del Caballo ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "ID Cliente: " << getIDCliente() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Edad: " << getEdad() << " anios" << endl;
    cout << "Raza: " << getRaza() << endl;
    cout << "Tipo de Trabajo: " << getTipoTrabajo() << endl;
    cout << "Ultima Atencion: " << getUltimaAtencion() << endl;
    cout << "Proxima Atencion: " << getProximaAtencion() << endl;
    cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "-------------------------" << endl;
}