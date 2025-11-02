#include <iostream>
#include "Fecha.h"
using namespace std;

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    anio = 0;
}

Fecha::Fecha (int dia, int mes, int anio){
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

int Fecha::getDia(){
    return dia;
}

int Fecha::getMes(){
    return mes;
}

int Fecha::getAnio(){
    return anio;
}

void Fecha::setDia(int dia){
    dia = dia;
}

void Fecha::setMes(int mes){
    mes = mes;
}

void Fecha::setAnio(int anio){
    anio = anio;
}

string Fecha::toString() const {
    return to_string(dia) + "/"+ to_string(mes) + "/" + to_string(anio);
}

void Fecha::cargar(){
    do {
        cout<< "Dia: ";
        cin>> dia;
        if (dia < 1 || dia > 31) {
            cout<< "Ingrese parametros validos."<<endl;
        }
    } while (dia < 1 || dia > 31);

    do {
        cout<< "Ingrese mes: ";
        cin>> mes;
        if (mes < 1 || mes > 12) {
            cout << "Ingrese parametros validos."<<endl;
        }
    } while (mes < 1 || mes > 12);

    cout<<"Anio: ";
    cin>> anio;
}

void Fecha::mostrar() const {
    cout << dia << "/" << mes << "/" << anio;
}
