#pragma once

#include <cstring>
#include <iostream>
using namespace std;

class Caballo {
private:
    int id;
    int idCliente;
    char nombre[20];
    int edad;
    char raza[40];
    char tipoTrabajo[30];
    char ultimaAtencion[11];
    char proximaAtencion[11];
    //bool estado;
    int estado;

public:
    Caballo();
    ~Caballo();

    int getID() const;
    int getIDCliente() const;
    const char* getNombre() const;
    int getEdad() const;
    const char* getRaza() const;
    const char* getTipoTrabajo() const;
    const char* getUltimaAtencion() const;
    const char* getProximaAtencion() const;
    //bool getEstado() const;

    void setID(int valor);
    void setIDCliente(int valor);
    void setNombre(const char* valor);
    void setEdad(int valor);
    void setRaza(const char* valor);
    void setTipoTrabajo(const char* valor);
    void setUltimaAtencion(const char* valor);
    void setProximaAtencion(const char* valor);
    //void setEstado(bool valor);
     void setEstado(int valor);
    void mostrar() const;
};


