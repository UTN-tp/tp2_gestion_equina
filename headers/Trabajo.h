#ifndef TRABAJO_H
#define TRABAJO_H

#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Trabajo {
private:
    int id;
    int idCaballo;
    int idCliente;
    float costo;
    Fecha fechaTrabajo;  
 

public:
    Trabajo(){}
    ~Trabajo(){}

    int getID() const;
    int getIdCliente() const;
    int getIdCaballo() const;
    float getCosto() const;
    Fecha getFecha() const;
   
    

    void setID(int valor);
    void setIdCliente(int valor);
    void setIdCaballo(int valor);
    void setCosto(float valor);
    void setFecha(const Fecha& f);
    
    void cargar();
    void mostrar() const;
};

#endif
