#ifndef MATERIALESUSADOS_H
#define MATERIALESUSADOS_H

#include <iostream>
using namespace std;

class MaterialesUsados {
private:
    int idMaterialUsado;
    int idTrabajo;
    int idMaterial;
    int cantidad;

public:
    MaterialesUsados(){}
    ~MaterialesUsados(){}

    int getIDMaterialUsado() const;
    int getIDTrabajo() const;
    int getIDMaterial() const;
    int getCantidad() const;

    void setIDMaterialUsado(int valor);
    void setIDTrabajo(int valor);
    void setIDMaterial(int valor);
    void setCantidad(int valor);

    void mostrar() const;
};

#endif
