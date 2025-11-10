#ifndef TRABAJO_H
#define TRABAJO_H

#include <iostream>
#include "Fecha.h"
using namespace std;

class Trabajo {
private:
    int id;
    int idCliente;
    float monto;
    Fecha fechaTrabajo;

public:
    Trabajo(){}
    ~Trabajo(){}

    int getID() const;
    int getIdCliente() const;
    float getMonto() const;
    Fecha getFecha() const;

    void setID(int valor);
    void setIdCliente(int valor);
    void setMonto(float valor);
    void setFecha(const Fecha& f);

    void cargar();
    void mostrar() const;
};

#endif