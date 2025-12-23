//Version nueva:

#include <iostream>
#include <string>
#include <cstring>
#include "rlutil.h"
#include "Agenda.h"
#include "Caballo.h"
#include "CaballosManager.h"
#include "Archivos.h"
#include "Fecha.h"
#include "InputManager.h"
#include "MaterialesManager.h"



using namespace std;



Agenda::Agenda(){
    id = 0;
    idCliente = 0;
    idCaballo = 0;
    fechaTrabajo = Fecha(0, 0, 0);
    tipoTrabajo;
    trabajoRealizado = false;
}

Agenda::~Agenda(){}

int Agenda::getID() const{ return id; }
int Agenda::getIDCliente() const{ return idCliente; }
int Agenda::getIDCaballo() const{ return idCaballo; }
Fecha Agenda::getFechaTrabajo() const{ return fechaTrabajo; }
int Agenda::getTipoTrabajo() const{ return tipoTrabajo; }
bool Agenda::getTrabajoRealizado() const{ return trabajoRealizado; }

void Agenda::setID(int valor){ id = valor; }
void Agenda::setIDCliente(int valor){ idCliente = valor; }
void Agenda::setIDCaballo(int valor){ idCaballo = valor; }
void Agenda::setFechaTrabajo(const Fecha& valor){ fechaTrabajo = valor; }
void Agenda::setTipoTrabajo(int valor){
   tipoTrabajo = valor;
}
void Agenda::setTrabajoRealizado(bool valor){ trabajoRealizado = valor; }

bool Agenda::validarMaterialesStock (int tipoTrabajo){

    if(tipoTrabajo==2){
        Archivos archivos;
        Material m1 = archivos.leerRegistroMaterial(1);
        Material m2 = archivos.leerRegistroMaterial(2);

        if (m1.getStock() < Agenda::clavosParaHerrado && m2.getStock()< Agenda::herraduraParaHerrado) {
            rlutil::setColor(rlutil::RED);
            cout << "No hay suficiente stock de materiales disponible para ese trabajo.\n -- Es necesario realizar una reposicion --";
            rlutil::setColor(rlutil::WHITE);
            return false;
        }
    }
    return true;

}

void Agenda::mostrar() const {
    cout<<"-----------------------------------------\n";
    cout<<"ID: "<<getID()<<endl;
    cout<<"ID Cliente: "<<getIDCliente()<<endl;
    cout<<"ID Caballo: "<<getIDCaballo()<<endl;
    cout<<"Fecha de Trabajo: ";
    fechaTrabajo.mostrar();
    cout<<endl;

    getTipoTrabajo();
    if (tipoTrabajo==1){
        cout<<"Tipo de Trabajo: Desvasado" << endl;
    }

    else if (tipoTrabajo==2){
        cout<<"Tipo de Trabajo: Herrado" << endl;

    }


  //  cout<<"Tipo de Trabajo: "<<getTipoTrabajo()<<endl;

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
    Archivos archivos;
    Cliente clienteTemp;

    int nuevoID = archivos.cantidadRegistrosAgenda() + 1;

    setID(nuevoID);

    int idClienteIngresado;
    int idCaballoIngresado;
    char estadoOpcion;

    rlutil::setColor(rlutil::BLACK);
    cout<<"NUEVO TRABAJO A REGISTRAR\n-------------------------\n";
    rlutil::setColor(rlutil::WHITE);





    idClienteIngresado = clienteTemp.buscarClientePorEmail();

    if(idClienteIngresado == -1)
        return;

    clienteTemp = archivos.leerRegistroCliente(idClienteIngresado);


    rlutil::setColor(rlutil::BLACK);
    cout << "\n--- CABALLOS DEL CLIENTE CONFIRMADO ---\n";
    rlutil::setColor(rlutil::WHITE);

    archivos.listarCaballosPorCliente(clienteTemp.getID());

    idCaballoIngresado = InputManager::leerInt("ID de caballo: ");

    // Validacion
    if (!archivos.validarExistenciaCaballo(idCaballoIngresado, regCaballo)){
        return;   // si no hay un caballo valido, la funcion ya lo muestra con cout
    }

    if (regCaballo.getEstado() != 1) {   // 1 = caballo activo
        cout<<"El caballo se encuentra inactivo/vendido. No se puede registrar el trabajo.\n";
        return;
    }

    setIDCaballo(idCaballoIngresado);

    cout<<"Fecha de trabajo:\n";
    regFecha.cargar();
    setFechaTrabajo(regFecha);

    //Validar stock para el trabajo elegido

    int tipoTrabajoIngresado = InputManager::leerInt("Tipo de trabajo a realizar:\n 1- Desvasado \n 2- Herrado: ");
    if (!validarMaterialesStock (tipoTrabajoIngresado)){
        return;
    }

    setTipoTrabajo(tipoTrabajoIngresado);


    estadoOpcion = InputManager::leerCharOpciones(
        "Estado del trabajo (R/r Realizado - P/p Pendiente): ",
        "RrPp"
    );


    setTrabajoRealizado(estadoOpcion == 'R' || estadoOpcion == 'r');


    if (!InputManager::confirmar("¨Confirmar registro del trabajo? (s/n): ")) {
        cout << "Registro cancelado.\n";
        return;
    }
     // === GUARDA TAMBIEN UN TRABAJO ===
     Trabajo trabajo;

     // Generar ID de trabajo
     int nuevoIDTrabajo = archivos.cantidadRegistrosTrabajo() + 1;

     trabajo.setID(nuevoIDTrabajo);

     trabajo.setIdCliente(clienteTemp.getID());
     trabajo.setIdCaballo(idCaballoIngresado);  // agrego
     // Pedir monto
     float monto = InputManager::leerFloat("Monto del trabajo: $ ");
     trabajo.setCosto(monto);

     // Fecha = la misma de Agenda
     trabajo.setFecha(regFecha);

     // Guardar Trabajo
     if (archivos.guardarArchivoTrabajo(trabajo)) {
     cout << "Trabajo guardado correctamente.\n";
     } else {
      cout << "ERROR: no se pudo guardar el trabajo.\n";
     }

     this->setIDCliente(clienteTemp.getID());

    if (archivos.guardarArchivoAgenda(*this))
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
    rlutil::setColor(rlutil::BLACK);
    cout<<"AGENDA DE PROXIMOS TRABAJOS\n";
    rlutil::setColor(rlutil::WHITE);

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



    Archivos archivos;
    Agenda agenda;
    Caballo caballo;
    Cliente cliente;
    CaballosManager cabManager;

    int idCaballo;
    int idCliente;
    int cantidadTrabajos = archivos.cantidadRegistrosAgenda();
    bool existenciaTrabajo = false;

    if (cantidadTrabajos <= 0){
        cout<<"No se registraron trabajos en la agenda.\n";
        return;
    }

    cabManager.listarPorCliente();

    idCaballo = InputManager::leerInt("Ingrese el ID del caballo: ");


    // Validacion
    if (!archivos.validarExistenciaCaballo(idCaballo, caballo)){
        return;   // si no hay un caballo valido, la funcion ya lo muestra con cout
    }

    if (caballo.getEstado() != 1) {   // 1 = caballo activo
        cout<<"ADVERTENCIA: El caballo se encuentra inactivo/vendido."<<endl;
    }

    cout<<"LISTADO DE TRABAJOS DEL CABALLO "<<idCaballo<<"\n";
    cout<<"-----------------------------------------\n";

    for (int i=0; i<cantidadTrabajos; i++){
        agenda = archivos.leerRegistroAgenda(i);
        if (agenda.getIDCaballo() == idCaballo){
            agenda.mostrar();
            existenciaTrabajo = true;
        }
    }

    if (!existenciaTrabajo)
        cout<<"No hay trabajos registrados para este caballo.\n";
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

    Archivos archivos;
    Agenda agenda;
    Caballo caballo;
    Fecha fechaBuscada;
    CaballosManager cabManager;

    int idCaballo;
    int cantidadTrabajos = archivos.cantidadRegistrosAgenda();

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
            agenda = archivos.leerRegistroAgenda(i);
            Fecha fx = agenda.getFechaTrabajo();

            if (fx.getDia() == fechaBuscada.getDia() &&
                fx.getMes() == fechaBuscada.getMes() &&
                fx.getAnio() == fechaBuscada.getAnio()){
                agenda.mostrar();
                existenciaTrabajo = true;
            }
        }

        if (!existenciaTrabajo)
            cout<<"No hay trabajos registrados en esa fecha.\n";

    } break;

    case 2:{
        bool existenciaTrabajo = false;

        cabManager.listarPorCliente();

        idCaballo = InputManager::leerInt("Ingrese el ID del caballo: ");

        cout<<"ID CABALLO SELECCIONADO: "<<idCaballo<<endl;



        // Validacion
        if (!archivos.validarExistenciaCaballo(idCaballo, caballo)){
            return;   // si no hay un caballo valido, la funcion ya lo muestra con cout
        }

        if (caballo.getEstado() != 1) {   // 1 = caballo activo
            cout<<"ADVERTENCIA: El caballo se encuentra inactivo/vendido."<<endl;
        }

        for (int i=0; i<cantidadTrabajos; i++){
            agenda = archivos.leerRegistroAgenda(i);

            if (agenda.getIDCaballo() == idCaballo){
                agenda.mostrar();
                existenciaTrabajo = true;
            }
        }

        if (!existenciaTrabajo)
            cout<<"No hay trabajos registrados para ese caballo.\n";

    } break;

    case 0:{

        if (InputManager::confirmar("Seguro quiere regresar al menu principal? (s/n): ")) {
            cout<<"Volviendo...\n";
            return;
        } else {
            cout<<"Solicitud cancelada.\n";
        }

    } break;
    }
};
