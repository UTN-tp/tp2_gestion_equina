#pragma once
#include <string>


class Fecha
{
    public:
        Fecha();
        Fecha (int dia, int mes, int anio);
        int getDia();
        int getMes();
        int getAnio();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void cargar();
        void mostrar() const;

    std::string toString() const; // convertir la fecha a formato "DD/MM/YYYY"

    private:
        int _dia;
        int _mes;
        int _anio;
};
