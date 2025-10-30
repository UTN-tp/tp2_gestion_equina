#ifndef AGENDA_H
#define AGENDA_H

#include <cstring>
#include <iostream>
using namespace std;

class Agenda {
private:
    int id;
    int idCliente;
    int idCaballo;
    char fechaTrabajo[11];
    char tipoTrabajo[30];
public:
    Agenda(){}
    ~Agenda(){}

    int getID() const;
    int getIDCliente() const;
    int getIDCaballo() const;
    const char* getFechaTrabajo() const;
    const char* getTipoTrabajo() const;

    void setID(int valor);
    void setIDCliente(int valor);
    void setIDCaballo(int valor);
    void setFechaTrabajo(const char* valor);
    void setTipoTrabajo(const char* valor);

    void mostrar() const;
};

#endif
