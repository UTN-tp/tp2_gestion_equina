#ifndef USUARIO_H
#define USUARIO_H

#include <cstring>
#include <iostream>
using namespace std;

class Usuario {
protected:
    int id;
    char nombre[40];
    char apellido[40];
    char telefono[20];
    char email[60];
    bool estado;

public:
    Usuario();
    virtual ~Usuario();

    int getID() const;
    const char* getNombre() const;
    const char* getApellido() const;
    const char* getTelefono() const;
    const char* getEmail() const;
    bool getEstado() const;

    void setID(int valor);
    void setNombre(const char* valor);
    void setApellido(const char* valor);
    void setTelefono(const char* valor);
    void setEmail(const char* valor);
    void setEstado(bool valor);

    virtual void mostrar() const;
};

#endif