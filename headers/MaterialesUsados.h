#pragma once
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class MaterialesUsados {
private:
    int idMaterialUsado;
    int idTrabajo;
    int idMaterial;
    int cantidad;
    Fecha fechaUso;

public:
    MaterialesUsados(){}
    ~MaterialesUsados(){}

    int getIDMaterialUsado() const;
    int getIDTrabajo() const;
    int getIDMaterial() const;
    int getCantidad() const;
    Fecha getFechaUso() const;

    void setIDMaterialUsado(int valor);
    void setIDTrabajo(int valor);
    void setIDMaterial(int valor);
    void setCantidad(int valor);
    void setFechaUso(const Fecha& valor);

    void mostrar() const;
};

