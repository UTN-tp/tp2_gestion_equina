#ifndef MATERIAL_H
#define MATERIAL_H

#include <cstring>
#include <iostream>
using namespace std;

class Material {
private:
    int id;
    char nombre[40];
    char tipo[30];
    int stock;
    float precio;
    bool estado;

public:
    Material(){}
    ~Material(){}

    int getID() const;
    const char* getNombre() const;
    const char* getTipo() const;
    int getStock() const;
    float getPrecio() const;
    bool getEstado() const;

    void setID(int valor);
    void setNombre(const char* valor);
    void setTipo(const char* valor);
    void setStock(int valor);
    void setPrecio(float valor);
    void setEstado(bool valor);

    void mostrar() const;
};

#endif
