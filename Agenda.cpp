#include <iostream>
#include <string>
#include <cstring>
#include "Agenda.h"
#include "Caballo.h"
#include "CaballosManager.h"
#include "Archivos.h"
#include "Fecha.h"
#include "InputManager.h"



using namespace std;

Agenda::Agenda(){
    id = 0;
    idCliente = 0;
    idCaballo = 0;
    fechaTrabajo = Fecha(0, 0, 0);
    tipoTrabajo[0]  = '\0';
    trabajoRealizado = false;
}

Agenda::~Agenda(){}

int Agenda::getID() const{ return id; }
int Agenda::getIDCliente() const{ return idCliente; }
int Agenda::getIDCaballo() const{ return idCaballo; }
Fecha Agenda::getFechaTrabajo() const{ return fechaTrabajo; }
const char* Agenda::getTipoTrabajo() const{ return tipoTrabajo; }
bool Agenda::getTrabajoRealizado() const{ return trabajoRealizado; }

void Agenda::setID(int valor){ id = valor; }
void Agenda::setIDCliente(int valor){ idCliente = valor; }
void Agenda::setIDCaballo(int valor){ idCaballo = valor; }
void Agenda::setFechaTrabajo(const Fecha& valor){ fechaTrabajo = valor; }
void Agenda::setTipoTrabajo(const char* valor){
    strncpy(tipoTrabajo, valor, 29);
    tipoTrabajo[29] = '\0';
}
void Agenda::setTrabajoRealizado(bool valor){ trabajoRealizado = valor; }

void Agenda::mostrar() const {
    cout<<"-----------------------------------------\n";
    cout<<"ID: "<<getID()<<endl;
    cout<<"ID Cliente: "<<getIDCliente()<<endl;
    cout<<"ID Caballo: "<<getIDCaballo()<<endl;
    cout<<"Fecha de Trabajo: ";
    fechaTrabajo.mostrar();
    cout<<endl;
    cout<<"Tipo de Trabajo: "<<getTipoTrabajo()<<endl;

    if (getTrabajoRealizado())
        cout<<"Estado del trabajo: Realizado\n";
    else
        cout<<"Estado del trabajo: Pendiente\n";

    cout<<"-----------------------------------------\n";
}

void Agenda::registrarNuevoTrabajo(){


    if (!InputManager::confirmar("Desea cargar un nuevo trabajo? (s/n): "))
        return;

    Fecha regFecha;
    Caballo regCaballo;
    Archivos archivoAgenda;
    Archivos archivoCaballo;

    int nuevoID = archivoAgenda.cantidadRegistrosAgenda() + 1;
    int cantidadCaballos = archivoCaballo.cantidadRegistrosCaballo();

    setID(nuevoID);

    int idClienteIngresado;
    int idCaballoIngresado;
    char tipoTrabajoIngresado[30];
    char estadoOpcion;
    bool existenciaCaballo = false;
    bool estadoCaballo = false;

    cout<<"NUEVO TRABAJO A REGISTRAR\n-------------------------\n";


    idClienteIngresado = InputManager::leerInt("ID de cliente: ");
    setIDCliente(idClienteIngresado);

    idCaballoIngresado = InputManager::leerInt("ID de caballo: ");


    if (cantidadCaballos <= 0){
        cout<<"No hay caballos ingresados. No se puede registrar el trabajo.\n";
        return;
    }

    for (int i=0; i<cantidadCaballos; i++){
        regCaballo = archivoCaballo.leerRegistroCaballo(i);
        if (regCaballo.getID() == idCaballoIngresado){
            existenciaCaballo = true;
            estadoCaballo = regCaballo.getEstado();
            break;
        }
    }

    if (!existenciaCaballo){
        cout<<"No existe un caballo con el ID ingresado.\n";
        return;
    }

    if (!estadoCaballo){
        cout<<"El caballo se encuentra inactivo/vendido. No se puede registrar el trabajo.\n";
        return;
    }

    setIDCaballo(idCaballoIngresado);

    cout<<"Fecha de trabajo:\n";
    regFecha.cargar();
    setFechaTrabajo(regFecha);


    string texto = InputManager::leerLinea("Tipo de trabajo a realizar: ");
    strncpy(tipoTrabajoIngresado, texto.c_str(), 29);
    tipoTrabajoIngresado[29] = '\0';
    setTipoTrabajo(tipoTrabajoIngresado);



    estadoOpcion = InputManager::leerCharOpciones(
        "Estado del trabajo (R/r Realizado - P/p Pendiente): ",
        "RrPp"
    );


    setTrabajoRealizado(estadoOpcion == 'R' || estadoOpcion == 'r');


    if (!InputManager::confirmar("¿Confirmar registro del trabajo? (s/n): ")) {
        cout << "Registro cancelado.\n";
        return;
    }


    if (archivoAgenda.guardarArchivoAgenda(*this))
        cout << "Trabajo registrado correctamente.\n";
    else
        cout << "No se pudo registrar el trabajo.\n";
}

void Agenda::proximosTrabajos(){

    Archivos regArchivoAgenda;
    Agenda regAgenda;
    int cantidadTrabajos = regArchivoAgenda.cantidadRegistrosAgenda();
    bool trabajosPendientes = false;

    if (cantidadTrabajos <= 0){
        cout << "No hay trabajos registrados en la agenda.\n";
        return;
    }

    cout<<"AGENDA DE PROXIMOS TRABAJOS\n";

    for (int i=0; i<cantidadTrabajos; i++){
        regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
        if (!regAgenda.getTrabajoRealizado()){
            regAgenda.mostrar();
            trabajosPendientes=true;
        }
    }

    if (!trabajosPendientes)
        cout <<"No hay trabajos pendientes.\n";
}

void Agenda::consultasPorIDCaballo(){



    Archivos archAgenda;
    Archivos archCaballo;
    Agenda regAgenda;
    Caballo regCaballo;

    int idCaballo;
    int cantidadTrabajos = archAgenda.cantidadRegistrosAgenda();
    int cantidadCaballos = archCaballo.cantidadRegistrosCaballo();
    bool existenciaTrabajo = false;
    bool existenciaCaballo = false;
    bool estadoCaballo = false;

    if (cantidadTrabajos <= 0){
        cout<<"No se registraron trabajos en la agenda.\n";
        return;
    }


    idCaballo = InputManager::leerInt("Ingrese el ID del caballo: ");


    for (int i=0; i<cantidadCaballos; i++){
        regCaballo = archCaballo.leerRegistroCaballo(i);
        if (regCaballo.getID() == idCaballo){
            existenciaCaballo = true;
            estadoCaballo = regCaballo.getEstado();
            break;
        }
    }

    if (!existenciaCaballo){
        cout<<"No existe un caballo con ese ID.\n";
        return;
    }

    cout<<"LISTADO DE TRABAJOS DEL CABALLO "<<idCaballo<<"\n";
    cout<<"-----------------------------------------\n";

    for (int i=0; i<cantidadTrabajos; i++){
        regAgenda = archAgenda.leerRegistroAgenda(i);
        if (regAgenda.getIDCaballo() == idCaballo){
            regAgenda.mostrar();
            existenciaTrabajo = true;
        }
    }

    if (!existenciaTrabajo)
        cout<<"No hay trabajos registrados para este caballo.\n";

    if (!estadoCaballo)
        cout<<"ADVERTENCIA: El caballo está inactivo/vendido.\n";
}

void Agenda::historialTrabajosRealizados(){

    Archivos regArchivoAgenda;
    Agenda regAgenda;

    int cantidadTrabajos = regArchivoAgenda.cantidadRegistrosAgenda();
    bool existenciaTrabajo = false;

    if (cantidadTrabajos <= 0){
        cout<<"No hay trabajos registrados.\n";
        return;
    }

    cout<<"HISTORIAL DE TRABAJOS REALIZADOS:\n";

    for (int i=0; i<cantidadTrabajos; i++){
        regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
        if (regAgenda.getTrabajoRealizado()){
            regAgenda.mostrar();
            existenciaTrabajo = true;
        }
    }

    if (!existenciaTrabajo)
        cout<<"No hay registro de trabajos realizados.\n";
}

void Agenda::buscarTrabajo(){




    Archivos regArchivoAgenda;
    Archivos regArchivoCaballo;
    Agenda regAgenda;
    Caballo regCaballo;
    Fecha fechaBuscada;

    int idCaballo;
    int cantidadTrabajos = regArchivoAgenda.cantidadRegistrosAgenda();
    int cantidadCaballos = regArchivoCaballo.cantidadRegistrosCaballo();

    int opcion;

    if (cantidadTrabajos <= 0){
        cout<<"No se registraron trabajos en la agenda.\n";
        return;
    }

    cout<<"BUSCAR TRABAJO POR FECHA/CABALLO\n";
    cout<<"1-Buscar por Fecha\n";
    cout<<"2-Buscar por ID de Caballo\n";
    cout<<"0-Volver al menu\n";


    opcion = InputManager::leerIntEnRango("Ingrese una opcion: ", 0, 2);


    switch (opcion){
    case 1:{
        bool existenciaTrabajo = false;

        cout<<"Ingrese la fecha del trabajo:\n";
        fechaBuscada.cargar();

        cout<<"FECHA SELECCIONADA: ";
        fechaBuscada.mostrar();
        cout<<endl;

        for (int i=0; i<cantidadTrabajos; i++){
            regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
            Fecha fx = regAgenda.getFechaTrabajo();

            if (fx.getDia() == fechaBuscada.getDia() &&
                fx.getMes() == fechaBuscada.getMes() &&
                fx.getAnio() == fechaBuscada.getAnio()){
                regAgenda.mostrar();
                existenciaTrabajo = true;
            }
        }

        if (!existenciaTrabajo)
            cout<<"No hay trabajos registrados en esa fecha.\n";

    } break;

    case 2:{
        bool existenciaTrabajo = false;
        bool existenciaCaballo2 = false;
        bool estadoCaballo = false;


        idCaballo = InputManager::leerInt("Ingrese el ID del caballo: ");


        cout<<"ID CABALLO SELECCIONADO: "<<idCaballo<<endl;

        for (int i=0; i<cantidadCaballos; i++){
            regCaballo = regArchivoCaballo.leerRegistroCaballo(i);
            if (regCaballo.getID() == idCaballo){
                existenciaCaballo2 = true;
                estadoCaballo = regCaballo.getEstado();
                break;
            }
        }

        if (!existenciaCaballo2){
            cout<<"No existe un caballo con ese ID.\n";
            return;
        }

        if (!estadoCaballo)
            cout<<"ADVERTENCIA: El caballo está inactivo/vendido.\n";

        for (int i=0; i<cantidadTrabajos; i++){
            regAgenda = regArchivoAgenda.leerRegistroAgenda(i);

            if (regAgenda.getIDCaballo() == idCaballo){
                regAgenda.mostrar();
                existenciaTrabajo = true;
            }
        }

        if (!existenciaTrabajo)
            cout<<"No hay trabajos registrados para ese caballo.\n";

    } break;

    case 0:{

        if (InputManager::confirmar("¿Seguro quiere regresar al menú principal? (s/n): ")) {
            cout<<"Volviendo...\n";
            return;
        } else {
            cout<<"Solicitud cancelada.\n";
        }

    } break;
    }
}
