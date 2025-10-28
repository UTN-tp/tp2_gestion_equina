#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha() {
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha (int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

int Fecha::getDia(){
    return _dia;
}

int Fecha::getMes(){
    return _mes;
}

int Fecha::getAnio(){
    return _anio;
}

void Fecha::setDia(int dia){
    _dia = dia;
}

void Fecha::setMes(int mes){
    _mes = mes;
}

void Fecha::setAnio(int anio){
    _anio = anio;
}

string Fecha::toString() const {
    return to_string(_dia) + "/"+ to_string(_mes) + "/" + to_string(_anio);
}

void Fecha::cargar(){
    do {
        cout<< "Dia: ";
        cin>> _dia;
        if (_dia < 1 || _dia > 31) {
            cout<< "Ingrese parametros validos."<<endl;
        }
    } while (_dia < 1 || _dia > 31);

    do {
        cout<< "Ingrese mes: ";
        cin>> _mes;
        if (_mes < 1 || _mes > 12) {
            cout << "Ingrese parametros validos."<<endl;
        }
    } while (_mes < 1 || _mes > 12);

    cout<<"Anio: ";
    cin>> _anio;
}

void Fecha::mostrar() const {
    cout << _dia << "/" << _mes << "/" << _anio;
}
