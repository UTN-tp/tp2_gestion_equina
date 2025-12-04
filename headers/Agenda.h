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
        int tipoTrabajo;
        bool trabajoRealizado;
        bool validarMaterialesStock(int);
        static const int clavosParaHerrado = 24;
        static const int herraduraParaHerrado = 4;

public:
    Agenda();
    ~Agenda();

        int getID() const;
        int getIDCliente() const;
        int getIDCaballo() const;
        Fecha getFechaTrabajo() const;
        int getTipoTrabajo() const;
        bool getTrabajoRealizado() const;

        void setID(int valor);
        void setIDCliente(int valor);
        void setIDCaballo(int valor);
        void setFechaTrabajo(const Fecha& valor);
        void setTipoTrabajo(int valor);
        void setTrabajoRealizado(bool valor);

        void mostrar() const;
        void registrarNuevoTrabajo();
        void proximosTrabajos();
        void consultasPorIDCaballo();
        void historialTrabajosRealizados();
        void buscarTrabajo();

};

