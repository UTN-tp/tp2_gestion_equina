#include <cstring>
#include <iostream>
#include "Material.h"
using namespace std;

Material::Material() {
    id = 0;
    nombre[0] = '\0';
    tipo[0] = '\0';
    stock = 0;
    precio = 0;
    estado = true;
}

Material::~Material(){
}

int Material::getID() const{
    return id;
}

const char* Material::getNombre() const{
    return nombre;
}

const char* Material::getTipo() const{
    return tipo;
}

int Material::getStock() const{
    return stock;
}

float Material::getPrecio() const{
    return precio;
}

bool Material::getEstado() const{
    return estado;
}

void Material::setID(int valor){
    id = valor;
}

void Material::setNombre(const char* valor){
    strncpy(nombre, valor, 39);
    nombre[39] = '\0';
}

void Material::setTipo(const char* valor){
    strncpy(tipo, valor, 29);
    tipo[29] = '\0';
}
void Material::setStock(int valor){
    stock = valor;
}

void Material::setPrecio(float valor){
    precio = valor;
}

void Material::setEstado(bool valor){
    estado = valor;
}

void Material::mostrar() const{
    cout << "--- Datos del Material ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Tipo: " << getTipo() << endl;
    cout << "Stock: " << getStock() << endl;
    cout << "Precio: " << getPrecio() << endl;
    cout << "Estado: " << (getEstado() ? "Activo" : "Inactivo") << endl;
    cout << "-------------------------" << endl;
}
