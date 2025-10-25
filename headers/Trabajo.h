#ifndef TRABAJO_H
#define TRABAJO_H

#include <cstring>
#include <iostream>
using namespace std;

class Trabajo {
private:
    int id; 
    int idCaballo; 
    char fecha[11]; 
    char tipoTrabajo[30]; 
    float costo;
    float precio;

public:
    Trabajo();
    ~Trabajo();

    int getID() const;
    int getIDCaballo() const;
    const char* getFecha() const;
    const char* getTipoTrabajo() const;
    float getCosto() const;
    float getPrecio() const;

    void setID(int valor);
    void setIDCaballo(int valor);
    void setFecha(const char* valor);
    void setTipoTrabajo(const char* valor);
    void setCosto(float valor);
    void setPrecio(float valor);

    void mostrar() const;
};

#endif