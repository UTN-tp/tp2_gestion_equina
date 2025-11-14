#include <iostream>
using namespace std;
#include "cstring"
#include "Cliente.h"
#include "InputManager.h"
#include "Usuario.h"
#include "Archivos.h"

/*Cargar Nuevo Cliente
Modificar Datos de Cliente
Consultar Cliente por ID
Listar Todos los Clientes
Cambiar Estado del Cliente (Activo/Inactivo)*/

//GETTERS Y SETTERS

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

    void Cliente::agregarNuevoCliente(){

        Cliente cliente;

        string nombre = InputManager::leerString("Ingrese el nombre del nuevo cliente: ");
        cliente.setNombre(nombre.c_str());


        string apellido = InputManager::leerString("Ingrese el apellido del nuevo cliente: ");
        cliente.setApellido(apellido.c_str());

        string email = InputManager::leerString("Ingrese el email del nuevo cliente: ");
        cliente.setEmail(email.c_str());

        string telefono = InputManager::leerString("Ingrese el telefono del nuevo cliente: ");
        cliente.setTelefono(telefono.c_str());

        string direccion = InputManager::leerLinea("Ingrese la direccion del nuevo cliente: ");
        cliente.setDireccion(direccion.c_str());


        int cantidadCaballos = InputManager::leerInt("Ingrese la cantidad de caballos que posee el cliente: ");
        cliente.setCantidadCaballos(cantidadCaballos);

        //Confirmacion agregar Cliente

         cout << "\n--- CONFIRMAR DATOS DEL CLIENTE ---\n";
        cliente.mostrar();
        cout << "-----------------------------------\n";

        if (!InputManager::confirmar("Desea guardar este cliente? (s/n): ")) {
            cout << "\nCarga cancelada. No se guardaron datos.\n";
            return;
        }

        Archivos archivos;
        archivos.guardarArchivoCliente(cliente);
        cout << "Cliente agregado correctamente." << endl;
    }


   /* bool Cliente::modificarDatosCliente (){

    }
    bool Cliente::consultarporId(){
    }

    bool Cliente::listarTodosClientes (){
    }
    void Cliente::cambiarEstadoCliente(){
        Usuario::setEstado();
    }
    */

