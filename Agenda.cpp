//Version nueva:

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
    CaballosManager managerCaballos;
    cout<<"NUEVO TRABAJO A REGISTRAR\n-------------------------\n";


    Cliente clienteTemp;

    do {

        idClienteIngresado = InputManager::leerInt("ID de cliente: ");

        cout << "\n--- Buscando Cliente con ID " << idClienteIngresado << " ---\n";


        int idEncontrado = clienteTemp.buscarPorID(idClienteIngresado);

        if (idEncontrado == 0) {

            if (!InputManager::confirmar("\nDesea intentar con otro ID? (s/n): ")) {
                cout << "\nCarga de trabajo cancelada.\n";
                return;
            }
        } else {

            if (InputManager::confirmar("\nEs este el cliente correcto? (s/n): ")) {
                 setIDCliente(idClienteIngresado);
                 break;
            } else {
                 cout << "Por favor, ingrese el ID correcto.\n";
            }
        }

    } while(true);


    cout << "\n--- CABALLOS DEL CLIENTE CONFIRMADO ---\n";

    archivoCaballo.listarCaballosPorCliente(idClienteIngresado);

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


    if (!InputManager::confirmar("¨Confirmar registro del trabajo? (s/n): ")) {
        cout << "Registro cancelado.\n";
        return;
    }
     // === GUARDA TAMBIN UN TRABAJO ===
     Trabajo t;
     Archivos archTrabajo;

     // Generar ID de trabajo
     int nuevoIDTrabajo = archTrabajo.cantidadRegistrosTrabajo() + 1;

     t.setID(nuevoIDTrabajo);
      t.setIdCliente(idClienteIngresado);

     // Pedir monto
     float monto = InputManager::leerFloat("Monto del trabajo: $ ");
     t.setCosto(monto);

     // Fecha = la misma de Agenda
     t.setFecha(regFecha);

     // Guardar Trabajo
     if (archTrabajo.guardarArchivoTrabajo(t)) {
     cout << "Trabajo (economico) guardado correctamente.\n";
     } else {
      cout << "ERROR: no se pudo guardar el trabajo economico.\n";
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
        cout<<"ADVERTENCIA: El caballo est  inactivo/vendido.\n";
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
            cout<<"ADVERTENCIA: El caballo est  inactivo/vendido.\n";

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

        if (InputManager::confirmar("¨Seguro quiere regresar al men£ principal? (s/n): ")) {
            cout<<"Volviendo...\n";
            return;
        } else {
            cout<<"Solicitud cancelada.\n";
        }

    } break;
    }
}








/*Version anterior Agenda:
#include <iostream>
#include <string>
#include <cstring>
#include "Agenda.h"
#include "Caballo.h"
#include "CaballosManager.h"
#include "Archivos.h"
#include "Fecha.h"
#include "rlutil.h"
using namespace std;

Agenda::Agenda(){
    id = 0;
    idCliente = 0;                     // constructor inicializado en 0
    idCaballo = 0;
    fechaTrabajo = Fecha(0, 0, 0);
    tipoTrabajo[0]  = '\0';
    trabajoRealizado = false;
}

Agenda::~Agenda(){
}

int Agenda::getID() const{
    return id;
}

int Agenda::getIDCliente() const{
    return idCliente;
}

int Agenda::getIDCaballo() const{
    return idCaballo;
}

Fecha Agenda::getFechaTrabajo() const{
    return fechaTrabajo;
}

const char* Agenda::getTipoTrabajo() const{
    return tipoTrabajo;
}

bool Agenda::getTrabajoRealizado() const{
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

void Agenda::setFechaTrabajo(const Fecha& valor){
    fechaTrabajo = valor;
}

void Agenda::setTipoTrabajo(const char* valor){
    strncpy(tipoTrabajo, valor, 29);             // uso de strncpy para evitar errores si se sobrepasa el valor del array
    tipoTrabajo[29] = '\0';
}

void Agenda::setTrabajoRealizado(bool valor){
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
    Caballo regCaballo;
    Archivos archivoAgenda;
    Archivos archivoCaballo;
    int nuevoID = archivoAgenda.cantidadRegistrosAgenda() + 1;
    int cantidadCaballos = archivoCaballo.cantidadRegistrosCaballo();
    setID(nuevoID);
    int idClienteIngresado;
    int idCaballoIngresado;
    char tipoTrabajo[30];
    char estadoOpcion;
    bool existenciaCaballo;
    bool estadoCaballo;

    cout<<"NUEVO TRABAJO A REGISTRAR"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"ID de cliente: ";
    cin>>idClienteIngresado;
    setIDCliente(idClienteIngresado);
    cout<<"ID de caballo: ";
    cin>>idCaballoIngresado;

    if (cantidadCaballos <= 0){
    cout<<"No hay caballos ingresados. No se puede registrar el trabajo."<<endl;
    return;
    }

    for (int i=0; i<cantidadCaballos; i++){
    regCaballo = archivoCaballo.leerRegistroCaballo(i);
    if (regCaballo.getID() == idCaballoIngresado){
        existenciaCaballo = true;                                //validacion de estado y existencia del caballo
        estadoCaballo = regCaballo.getEstado();
        break;
    }
    }

    if (existenciaCaballo == false){
        cout<<"No existe un caballo con el ID ingresado."<<endl;
        return;
    }

    if (estadoCaballo == false){
        cout<<"El caballo se encuentra inactivo/vendido. No se puede registrar el trabajo."<<endl;
        return;
    }

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

      // agrego monto para trabajo
    Trabajo t;
    Archivos archTrabajo;
    float costo;
    int nuevoIDTrabajo = archTrabajo.cantidadRegistrosTrabajo() + 1;

    t.setID(nuevoIDTrabajo);
    t.setIdCliente(idClienteIngresado);
    t.setIdCaballo(idCaballoIngresado);
    t.setFecha(regFecha);

    cout << "Costo del Trabajo: $ ";
    cin >> costo;
    t.setCosto(costo);

    if (archTrabajo.guardarArchivoTrabajo(t)){
        cout << "Registro guardado correctamente.\n";
    }
    else {
        cout << "ERROR al guardar el registro.\n";
    }

    // hasta aca agregue lo de Guille para probar

    cout<<"Estado del trabajo (Realizado: R/r, Pendiente: P/p): ";
    cin>>estadoOpcion;
    while (estadoOpcion != 'R' && estadoOpcion != 'r'                  //validacion
        && estadoOpcion != 'P' && estadoOpcion != 'p'){
        cout<<"Opciï¿½n invalida, ingrese P o R segun corresponde"<<endl;
        cin>>estadoOpcion;
    }
    if (estadoOpcion == 'R' || estadoOpcion == 'r'){
        setTrabajoRealizado(true);
    } else {
        setTrabajoRealizado(false);
    }
    // crear o guardar el archivo de agenda
    if (archivoAgenda.guardarArchivoAgenda(*this) == true ){
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

    if (cantidadTrabajos <= 0){
        cout << "No hay trabajos registrados en la agenda." << endl;
        return;
    }

    cout<<"AGENDA DE PROXIMOS TRABAJOS"<<endl;

    for (int i=0; i<cantidadTrabajos; i++){
        regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
        // solo mostrara si el trabajo esta pendiente
        if (regAgenda.getTrabajoRealizado() == false){
            regAgenda.mostrar();
            trabajosPendientes=true;
        }
    }

    if (trabajosPendientes == false){
        cout <<"No hay trabajos pendientes."<<endl;
    }
}

void Agenda::consultasPorIDCaballo(){

    Archivos archAgenda;
    Archivos archCaballo;
    Agenda regAgenda;
    Caballo regCaballo;
    int idCaballo;
    int cantidadTrabajos;
    int cantidadCaballos;
    bool existenciaTrabajo = false;
    bool existenciaCaballo = false;
    bool estadoCaballo = false;

    cantidadCaballos = archCaballo.cantidadRegistrosCaballo();
    cantidadTrabajos = archAgenda.cantidadRegistrosAgenda();

    if (cantidadTrabajos <= 0) {
        cout<<"No se registraron trabajos en la agenda."<<endl;
        return;
    }

    cout<<"Ingrese el ID del caballo: ";
    cin>>idCaballo;

    for (int i=0; i<cantidadCaballos; i++){
        regCaballo = archCaballo.leerRegistroCaballo(i);
        if (regCaballo.getID() == idCaballo) {
            existenciaCaballo = true;
            estadoCaballo = regCaballo.getEstado();         //Validar existencia y estado de caballo unica vez
            break;
        }
    }

    if (existenciaCaballo == false){
        cout<<"No existe un caballo con ese ID ingresado."<<endl;
        return;
    }

    cout<< "LISTADO DE TRABAJOS DEL ID CABALLO N: "<<idCaballo<<endl;
    cout<<"-----------------------------------------"<<endl;

    for (int i = 0; i < cantidadTrabajos; i++){
        regAgenda = archAgenda.leerRegistroAgenda(i);
        if (regAgenda.getIDCaballo() == idCaballo){
            regAgenda.mostrar();
            existenciaTrabajo = true;
        }
    }

    if (existenciaTrabajo == false){
        cout<<"No hay trabajos registrados para este caballo."<<endl;
    }

    if (estadoCaballo == false){
        cout<<"ADVERTENCIA: El caballo se encuentra inactivo/vendido."<<endl;
    }
}

void Agenda::historialTrabajosRealizados(){

    Archivos regArchivoAgenda;
    Agenda regAgenda;

    int cantidadTrabajos = regArchivoAgenda.cantidadRegistrosAgenda();
    bool existenciaTrabajo = false;

    if (cantidadTrabajos <= 0){
        cout<<"No hay trabajos registrados en la agenda."<<endl;
        return;
    }

    cout<<"HISTORIAL DE TRABAJOS REALIZADOS: "<<endl;

    for (int i=0; i<cantidadTrabajos; i++){
        regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
        if (regAgenda.getTrabajoRealizado() == true) {
            regAgenda.mostrar();
            existenciaTrabajo = true;
        }
    }

    if (existenciaTrabajo == false){
        cout<<"El historial se encuentra vacio. No hay registro de trabajo realizado."<<endl;
    }
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
        cout<<"No se registraron trabajos en la agenda."<<endl;
        return;
    }
    rlutil::cls();
    cout<<"BUSCAR TRABAJO POR FECHA/CABALLO"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"1-Buscar por Fecha"<<endl;
    cout<<"2-Buscar por ID de Caballo"<<endl;
    cout<<"0-Volver al menu"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<< "Ingrese una opcion (1, 2, 0): ";
    cin>>opcion;

    switch (opcion){
        case 1:{
            rlutil::cls();
            bool existenciaTrabajo = false;

            cout<<"Ingrese la fecha del trabajo a buscar: "<<endl;
            fechaBuscada.cargar();
            cout<<"FECHA SELECCIONADA: ";
            fechaBuscada.mostrar();
            cout<<endl;

            for (int i=0; i<cantidadTrabajos; i++){
                regAgenda = regArchivoAgenda.leerRegistroAgenda(i);
                Fecha regFecha = regAgenda.getFechaTrabajo();

                if (regFecha.getDia() == fechaBuscada.getDia() && regFecha.getMes() == fechaBuscada.getMes()
                     && regFecha.getAnio() == fechaBuscada.getAnio()){
                    regAgenda.mostrar();
                    existenciaTrabajo = true;
                }
            }

            if (existenciaTrabajo == false){
                cout<<"No se encontraron trabajos registrados en esa fecha."<<endl;
            }
        } break;

        case 2:{
            rlutil::cls();
            bool existenciaTrabajo = false;
            bool existenciaCaballo = false;
            bool estadoCaballo = false;

            cout<< "Ingrese el ID del caballo: ";
            cin>>idCaballo;

            cout<<"ID CABALLO SELECCIONADO: "<<idCaballo<<endl;

            for (int i=0; i<cantidadCaballos; i++){
                regCaballo = regArchivoCaballo.leerRegistroCaballo(i);  // validamos que exista caballo y su estado
                if (regCaballo.getID() == idCaballo){
                    existenciaCaballo = true;
                    estadoCaballo = regCaballo.getEstado();
                    break;
                }
            }

            if (existenciaCaballo == false){
                cout<<"No existe un caballo con el ID ingresado."<<endl;
                return;
            }

            if (estadoCaballo == false){
                cout<<"ADVERTENCIA: El caballo se encuentra inactivo/vendido."<<endl;
            }

            for (int i=0; i<cantidadTrabajos; i++){
                regAgenda = regArchivoAgenda.leerRegistroAgenda(i);

                if (regAgenda.getIDCaballo() == idCaballo){
                    regAgenda.mostrar();
                    existenciaTrabajo = true;
                }
            }

            if (existenciaTrabajo == false){
                cout<< "No se encontraron trabajos registrados para ese caballo."<<endl;
            }
        } break;

        case 0: {
            char opcion;
            cout<<"ï¿½Seguro quiere regresar al menï¿½ principal? (ingrese s/S para confirmar): ";
            cin>>opcion;

            if (opcion == 's' || opcion == 'S'){
                cout << "Volviendo al menï¿½ principal..." << endl;
                return;
            }
            else{
                cout<<"Caracter incorrecto, anulando solicitud"<<endl;
            }
        } break;

        default:
            cout<<"Opciï¿½n incorrecta, ingrese un numero valido."<<endl;
            break;
    }
}
*/
