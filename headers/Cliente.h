#ifndef CLIENTE_H
#define CLIENTE_H

#include "Usuario.h"

class Cliente : public Usuario {
private:
    char direccion[100];
    int cantidadCaballos;

public:
    Cliente();

    void agregarNuevoCliente ();
    void modificarDatosCliente ();
    void listarTodosLosClientes ();
    void consultarporId();
    void cambiarEstadoCliente ();


    //Getters/Setters:
    const char* getDireccion() const;
    int getCantidadCaballos() const;

    void setDireccion(const char* valor);
    void setCantidadCaballos(int valor);

    void mostrar() const override;
};

#endif
