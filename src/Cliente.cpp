#include <iostream>
using namespace std;
#include "cstring"
#include "Cliente.h"
#include "InputManager.h"
#include "Usuario.h"
#include "Archivos.h"
#include "rlutil.h"


//GETTERS Y SETTERS

    Cliente::Cliente (){
    id= -1;

    }

const char* Cliente::getDireccion() const {
    return direccion;
}

int Cliente::getCantidadCaballos() const {
    return cantidadCaballos;
}



void Cliente::setDireccion(const char* valor) {

    strncpy(direccion, valor, 100);

    direccion[99] = '\0';
}

void Cliente::setCantidadCaballos(int valor) {
    cantidadCaballos = valor;
}

//Funciones propias de Cliente

//Agregar cliente:

    void Cliente::agregarNuevoCliente(){

        Cliente cliente;
        Archivos archivos;


        string nombre = InputManager::leerLinea("Ingrese el nombre del nuevo cliente. ", 40);
        cliente.setNombre(nombre.c_str());


        string apellido = InputManager::leerLinea("Ingrese el apellido del nuevo cliente. ", 40);
        cliente.setApellido(apellido.c_str());

        string email = InputManager::leerLinea("Ingrese el email del nuevo cliente. ", 60);
        cliente.setEmail(email.c_str());

         //===================== agrego
        if (archivos.existeEmailCliente(cliente.getEmail())) {
            cout << "\nERROR: El email ingresado ya esta registrado. Carga cancelada.\n";
            return;
        }
        //==================== hasta aca

        string telefono = InputManager::leerLinea("Ingrese el telefono del nuevo cliente. ", 20);
        cliente.setTelefono(telefono.c_str());

        string direccion = InputManager::leerLinea("Ingrese la direccion del nuevo cliente. ", 100);
        cliente.setDireccion(direccion.c_str());


        cliente.setEstado(true);
        int idNuevoCliente = archivos.cantidadRegistrosCliente () +1;
        cliente.setID (idNuevoCliente);



        //Confirmacion agregar Cliente

         rlutil::cls();

         cout << "\n--- CONFIRMAR DATOS DEL CLIENTE ---\n";
        cliente.mostrar();
        cout << "-----------------------------------\n";

        if (!InputManager::confirmar("Desea guardar este cliente? (s/n): ")) {
            cout << "\nCarga cancelada. No se guardaron datos.\n";
            return;
        }

        archivos.guardarArchivoCliente(cliente);
        cout << "Cliente agregado correctamente." << endl;
    }

   //MODIFICAR CLIENTE
void Cliente::modificarDatosCliente (){
   int idEnArchivo;

   Archivos archivos;

   int id = InputManager::leerInt("Ingrese ID del cliente: ");

    Cliente cliente = archivos.leerRegistroCliente(id-1);
    idEnArchivo = cliente.getID();


    if (idEnArchivo == -1) {
        cout << "Cliente no encontrado." << endl;
        return;
    }


    cliente.mostrar();

    if (!InputManager::confirmar("Desea modificar este cliente? S/N: "))
        return;
    bool modificado = false;
    int opcion;
    do
    {
        rlutil::cls();
        rlutil::setColor(rlutil::BLACK);
        cout << "---SELECIONE DATO A MODIFICAR---\n";
        rlutil::setColor(rlutil::WHITE);
        cout << "---------------------------------\n";
        cout << "1. Nombre" << endl;
        cout << "2. Apellido" << endl;
        cout << "3. Email" << endl;
        cout << "4. Telefono" << endl;
        cout << "5. Direccion" << endl;
        cout << "9. Salir y guardar" << endl;
        opcion = InputManager::leerInt("Seleccione una opcion: ");

        switch (opcion)
        {
        case 1:
        {
            string nombre = InputManager::leerLinea("Ingrese el nuevo nombre: ", 40);
            cliente.setNombre(nombre.c_str());
            modificado = true;
            cout << "Cambios preguardados" << endl;
            rlutil::anykey ();

            break;
        }

        case 2:
        {
            string apellido = InputManager::leerLinea("Ingrese el nuevo apellido: ", 40);
            cliente.setApellido(apellido.c_str());
            modificado = true;
            cout << "Cambios preguardados" << endl;
            rlutil::anykey ();
            break;
        }

        case 3:
        {
            string nuevoEmail = InputManager::leerLinea("Ingrese el nuevo email: ", 60);
            string emailActual = cliente.getEmail ();

        //Validacion mail
            if (nuevoEmail != emailActual) {

                if (archivos.existeEmailCliente(nuevoEmail.c_str())) {

                    rlutil::setColor(rlutil::GREEN);
                    cout << "\nERROR: El email ingresado ya esta registrado. Carga cancelada.\n";
                    rlutil::setColor(rlutil::WHITE);
                    return;
                }

            else {
            cliente.setEmail(nuevoEmail.c_str());
            cout << "Cambios preguardados" << endl;
            rlutil::anykey ();

            }
            }

            modificado = true;

            break;
        }

        case 4:
        {
            string telefono = InputManager::leerLinea("Ingrese el nuevo telefono: ", 20);
            cliente.setTelefono(telefono.c_str());
            modificado = true;
            cout << "Cambios preguardados" << endl;
            rlutil::anykey ();
            break;
        }

        case 5:
        {
            string direccion = InputManager::leerLinea("Ingrese la nueva direccion: ", 100);
            cliente.setDireccion(direccion.c_str());
            modificado = true;
            cout << "Cambios preguardados" << endl;
            rlutil::anykey ();
            break;
        }



        }

    }

    while(opcion != 9);


        if(modificado){
        archivos.modificarRegistroCliente(cliente, id-1);
        cout << "Cliente modificado correctamente." << endl;
        }



   }





   //MOSTRAR CLIENTE

void Cliente::mostrar() const {

    cout << "--- Datos del Cliente ---" << endl;
    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Direccion: " << getDireccion() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Cantidad de caballos: " << getCantidadCaballos() << endl;
    cout << "Telefono: " << getTelefono() << endl;

    if (getEstado()){

        cout << "El estado actual es:";
        rlutil::setColor(rlutil::GREEN);
        cout << "ACTIVO" << endl;
        rlutil::setColor(rlutil::WHITE);
    }

    else {
        cout << "El estado actual es:";
        rlutil::setColor(rlutil::RED);
        cout << "INACTIVO" << endl;
        rlutil::setColor(rlutil::WHITE);
    }

   }

   //CONSULTAR POR ID

void Cliente::consultarporId(){
        int idEnArchivo;

        Archivos archivos;

        int id = InputManager::leerInt("Ingrese ID del cliente: ");

        Cliente cliente = archivos.leerRegistroCliente(id-1);
        idEnArchivo = cliente.getID();


        if (idEnArchivo == -1) {
            cout << "Cliente no encontrado." << endl;
            return;
        }


        cliente.mostrar();
    }

    // BUSCARPORIDc/parametro

    int Cliente::buscarPorID(int idCliente) {
    Archivos archivo;
    int cantidad = archivo.cantidadRegistrosCliente();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idCliente) {
            cliente.mostrar();
            return cliente.getID();
        }
    }

    cout << "No se encontro un cliente con ese ID.\n";
    return 0;
}


    //CONSULTAR TODOS LOS CLIENTES
    void Cliente::listarTodosLosClientes (){
        Archivos archivo;


        archivo.listarTodosLosClientes();

    }

    //CAMBIAR ESTADO CLIENTE
void Cliente::cambiarEstadoCliente(){
        int idEnArchivo;

        Archivos archivos;

        int id = this->buscarClientePorEmail();

        Cliente cliente = archivos.leerRegistroCliente(id);
        idEnArchivo = cliente.getID();


        if (idEnArchivo == -1) {
            cout << "Cliente no encontrado." << endl;
            return;
        }


        if (cliente.getEstado()){
            rlutil::setColor(rlutil::GREEN);
           cout << "El estado actual es ACTIVO." << endl;
           rlutil::setColor(rlutil::WHITE);
        }
        else {
            rlutil::setColor(rlutil::RED);
            cout << "El estado actual es INACTIVO." << endl;
            rlutil::setColor(rlutil::WHITE);

        }
        //CONFIRMACION CAMBIAR ESTADO

    if (!InputManager::confirmar("Desea modificar el estado de este cliente? S/N: "))
        return;
        cliente.setEstado(!cliente.getEstado());

        archivos.modificarRegistroCliente(cliente, id-1);

        if (cliente.getEstado()){

            cout << "Estado de Cliente modificado correctamente. El estado actual es: ACTIVO" << endl;
        }

        else {
             cout << "Estado de Cliente modificado correctamente. El estado actual es: INACTIVO" << endl;
        }
    }

    //BUSCAR CLIENTE POR EMAIL

int Cliente::buscarClientePorEmail(std::string email) {
    Archivos archivos;

    if (email.empty()) {
        email = InputManager::leerLinea("Ingrese email del cliente: ", 60);
    }

    int pos = archivos.buscarClientePorEmail(email.c_str());

    if (pos == -1) {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontro ningun cliente con ese email.\n";
        rlutil::setColor(rlutil::WHITE);
        return -1;
    }

    Cliente cliente = archivos.leerRegistroCliente(pos);

    rlutil::setColor(rlutil::BLACK);
    cout << "\n--- CLIENTE ENCONTRADO: ---\n";
    rlutil::setColor(rlutil::WHITE);

    cliente.mostrar();
    cout << "--------------------------\n";

    if (!InputManager::confirmar("Es este el cliente que busca? (s/n): ")) {
        rlutil::setColor(rlutil::BLACK);
        cout << "\n--- POR FAVOR, REINTENTE LA BUSQUEDA ---\n";
        rlutil::setColor(rlutil::WHITE);

        return buscarClientePorEmail(); // vuelve a intentar
    }

    rlutil::setColor(rlutil::GREEN);
    cout << "Busqueda exitosa.\n";
    rlutil::setColor(rlutil::WHITE);

    return pos;
}



