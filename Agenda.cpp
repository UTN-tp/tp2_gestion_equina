#include <iostream>
#include <string>
#include <cstring>
#include "Agenda.h"
#include "Caballo.h"
#include "Archivos.h"
#include "Fecha.h"
using namespace std;

Agenda::Agenda() {
    id = 0;
    idCliente = 0;                     // constructor inicializado en 0
    idCaballo = 0;
    fechaTrabajo = Fecha(0, 0, 0);
    tipoTrabajo[0]  = '\0';
    trabajoRealizado = false;
}

Agenda::~Agenda() {
}

int Agenda::getID() const {
    return id;
}

int Agenda::getIDCliente() const{
    return idCliente;
}

int Agenda::getIDCaballo() const{
    return idCaballo;
}

Fecha Agenda::getFechaTrabajo() const {
    return fechaTrabajo;
}

const char* Agenda::getTipoTrabajo() const{
    return tipoTrabajo;
}

bool Agenda::getTrabajoRealizado() const {
    return trabajoRealizado;
}

void Agenda::setID(int valor){
    id = valor;
}

void Agenda::setIDCliente(int valor){
    idCliente = valor;
}

void Agenda::setIDCaballo(int valor){
    idCaballo = valor;
}

void Agenda::setFechaTrabajo(const Fecha& valor) {
    fechaTrabajo = valor;
}

void Agenda::setTipoTrabajo(const char* valor) {
    strncpy(tipoTrabajo, valor, 29);             // uso de strncpy para evitar errores si se sobrepasa el valor del array
    tipoTrabajo[29] = '\0';
}

void Agenda::setTrabajoRealizado(bool valor) {
    trabajoRealizado = valor;
}

void Agenda::mostrar() const {
    cout<<"-----------------------------------------" << endl;
    cout<<"ID: "<<getID()<<endl;
    cout<<"ID Cliente: "<<getIDCliente()<<endl;
    cout<<"ID Caballo: "<<getIDCaballo()<<endl;
    cout<<"Fecha de Trabajo: ";
    fechaTrabajo.mostrar();
    cout<<endl;
    cout<<"Tipo de Trabajo: "<<getTipoTrabajo()<<endl;
    if (getTrabajoRealizado() == true){
    cout<<"Estado del trabajo: Realizado"<<endl;
    } else {
    cout <<"Estado del trabajo: Pendiente"<<endl;
    }
    cout<<"-----------------------------------------"<<endl;
}

void Agenda::registrarNuevoTrabajo(){

    Fecha regFecha;
    Archivos archivoAgenda;
 //   int nuevoID = 0; // lo calcularemos después cuando este el archivo, por ahora en 0
    int idClienteIngresado;
    int idCaballoIngresado;
    char tipoTrabajo[30];
    char estadoOpcion;

    cout<<"NUEVO TRABAJO A REGISTRAR"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"ID de cliente: ";
    cin>>idClienteIngresado;
    setIDCliente(idClienteIngresado);
    //Falta validar que exista cliente
    cout<<"ID de caballo: ";
    cin>>idCaballoIngresado;
    // Falta validar que exista caballo
    setIDCaballo(idCaballoIngresado);
    cout<<"Fecha de trabajo:"<<endl;
    regFecha.cargar();                 // uso de la clase fecha para guardar valor
    setFechaTrabajo(regFecha);
    cin.ignore();                  // limpieza del enter pendiente de ultimo cin >>
    do {
        cout<<"Tipo de trabajo a realizar: ";
        cin.getline(tipoTrabajo, 30); // permite ingresar texto con espacios
        if (strlen(tipoTrabajo) == 0) {  // Verificamos que el usuario ingrese un caracter obligatoriamente
        cout <<"Ingrese una descripcion del tipo de trabajo"<<endl;
        }
    } while (strlen(tipoTrabajo) == 0);     // validacion nuevamente con strlen
    setTipoTrabajo(tipoTrabajo);
    cout<<"Estado del trabajo (Realizado: R/r, Pendiente: P/p): ";
    cin>>estadoOpcion;
    while (estadoOpcion != 'R' && estadoOpcion != 'r'                  //validacion
        && estadoOpcion != 'P' && estadoOpcion != 'p'){
        cout<<"Opción invalida, ingrese P o R segun corresponde"<<endl;
        cin>>estadoOpcion;
    }
    if (estadoOpcion == 'R' || estadoOpcion == 'r'){
        setTrabajoRealizado(true);
    } else {
        setTrabajoRealizado(false);
    }
    // crear o guardar el archivo de agenda
    if (archivoAgenda.guardarArchivoAgenda(*this) == true ) {
        cout << "Trabajo registrado correctamente." << endl;
    }
    else {
        cout << "No se pudo registrar el trabajo." << endl;
    }
}

void Agenda::proximosTrabajos(){

    Archivos regArchivoAgenda;
    Agenda regAgenda;
    int cantidadTrabajos;
    cantidadTrabajos = regArchivoAgenda.cantidadRegistrosAgenda();
    bool trabajosPendientes = false;

    if (cantidadTrabajos <= 0) {
        cout << "No hay trabajos registrados en la agenda." << endl;
        return;
    }

    cout<<"AGENDA DE PROXIMOS TRABAJOS"<<endl;
    cout<<"---------------------------"<<endl;

    for (int i = 0; i < cantidadTrabajos; i++) {
        regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
        // solo mostrara si el trabajo esta pendiente
        if (regAgenda.getTrabajoRealizado() == false) {
            regAgenda.mostrar();
            cout<<"-----------------------------------------"<<endl;
            trabajosPendientes=true;
        }
    }

    if (trabajosPendientes == false) {
        cout << "No hay trabajos pendientes." << endl;
    }
}
