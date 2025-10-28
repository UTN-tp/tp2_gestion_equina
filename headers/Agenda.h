#pragma once
#include <cstring>
#include <iostream>
#include "Fecha.h"
using namespace std;

class Agenda {
    private:
        int id;
        int idCliente;
        int idCaballo;
        Fecha fechaTrabajo;
        char tipoTrabajo[30];
        bool trabajoRealizado;
    public:
        Agenda();
        ~Agenda();

        int getID() const;
        int getIDCliente() const;
        int getIDCaballo() const;
        Fecha getFechaTrabajo() const;
        const char* getTipoTrabajo() const;
        bool getTrabajoRealizado() const;

        void setID(int valor);
        void setIDCliente(int valor);
        void setIDCaballo(int valor);
        void setFechaTrabajo(const Fecha& valor);
        void setTipoTrabajo(const char* valor);
        void setTrabajoRealizado(bool valor);

        void mostrar() const;
        void registrarNuevoTrabajo();    //pendiente 2 validaciones
        void proximosTrabajos();
        void consultasPorIDCaballo();

};
