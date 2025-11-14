#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"

class Cliente : public Usuario {
private:
    char direccion[100];
    int cantidadCaballos;

public:
    Cliente(){}
    ~Cliente(){}

    void agregarNuevoCliente ();

    const char* getDireccion() const;
    int getCantidadCaballos() const;

    void setDireccion(const char* valor);
    void setCantidadCaballos(int valor);

    void mostrar() const override {}
};

#endif
