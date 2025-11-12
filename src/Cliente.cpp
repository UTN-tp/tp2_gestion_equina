
#include <iostream>
#include <cstring>
#include "./Archivos.h"
#include "./Cliente.h"
#include "InputManager.h"
using namespace std;
// Getter: devuelve la dirección
const char* Cliente::getDireccion() const {
    return direccion;
}

// Getter: devuelve la cantidad de caballos
int Cliente::getCantidadCaballos() const {
    return cantidadCaballos;
}

// Setter: asigna una nueva dirección
void Cliente::setDireccion(const char* valor) {
    if (valor != nullptr) {
        std::strncpy(direccion, valor, sizeof(direccion) - 1);
        direccion[sizeof(direccion) - 1] = '\0';
    } else {
        direccion[0] = '\0';
    }
}

// Setter: asigna la cantidad de caballos
void Cliente::setCantidadCaballos(int valor) {
    cantidadCaballos = valor;
}

// ===== CARGAR =====

void Cliente::cargar() {
      if (!InputManager::confirmar("Desea cargar un nuevo cliente? (s/n): "))
        return;

    cout << "\n=== CARGA DE CLIENTE ===\n";

    // Esto ya incluye su propia confirmación interna
     Usuario::cargar();


    setDireccion(InputManager::leerLinea("Direccion: ").c_str());
    cantidadCaballos = InputManager::leerInt("Cantidad de caballos: ");


    cout << "\n--- CONFIRMAR DATOS DEL CLIENTE ---\n";
    mostrar();
    cout << "------------------------------------\n";

    if (!InputManager::confirmar("Desea guardar este cliente? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }


    Archivos archivo;

    if (archivo.guardarArchivoCliente(*this))
        cout << "\nCliente guardado correctamente.\n";
    else
        cout << "\nError al guardar el cliente.\n";

    if (!archivo.guardarArchivoUsuario(static_cast<Usuario>(*this)))
        cout << "Error al guardar el usuario base.\n";
}

// ===== MOSTRAR =====

void Cliente::mostrar() const {
    Usuario::mostrar();
    cout << "Direccion: " << direccion << endl;
    cout << "Cantidad de caballos: " << cantidadCaballos << endl;
}

// ===== BUSCAR POR ID =====

void Cliente::buscarPorID() {
    int idBuscado = InputManager::leerInt("Ingrese el ID del cliente a buscar: ");

    Archivos archivo;
    int cantidad = archivo.cantidadRegistrosCliente();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idBuscado) {
            cout << "\nCliente encontrado:\n";
            cliente.mostrar();
            return;
        }
    }

    cout << "No se encontro un cliente con ese ID.\n";
}

// ===== BUSCAR POR ID (int) =====

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

// ===== EDITAR POR ID =====

void Cliente::editarPorID() {
    Archivos archivo;

    int idBuscado = InputManager::leerInt("Ingrese el ID del cliente que desea modificar: ");
    int cantidad = archivo.cantidadRegistrosCliente();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idBuscado) {
            cout << "\nCliente encontrado:\n";
            cliente.mostrar();

            if (!InputManager::confirmar("Desea modificar este cliente? (s/n): "))
                return;

            string s;

            s = InputManager::leerLinea("Nuevo nombre: ");
            if (!s.empty()) cliente.setNombre(s.c_str());

            s = InputManager::leerLinea("Nuevo apellido: ");
            if (!s.empty()) cliente.setApellido(s.c_str());

            s = InputManager::leerLinea("Nuevo telefono: ");
            if (!s.empty()) cliente.setTelefono(s.c_str());

            s = InputManager::leerLinea("Nuevo email: ");
            if (!s.empty()) cliente.setEmail(s.c_str());

            s = InputManager::leerLinea("Nueva direccion: ");
            if (!s.empty()) cliente.setDireccion(s.c_str());

            s = InputManager::leerLinea("Nueva cantidad de caballos: ");
            if (!s.empty()) cliente.setCantidadCaballos(stoi(s));

             cout << "\n--- CONFIRMAR CAMBIOS ---\n";
             cliente.mostrar();
             cout << "----------------------------------\n";

             if (!InputManager::confirmar("Desea guardar los cambios? (s/n): ")) {
             cout << "\nModificación cancelada. No se guardaron datos.\n";
             return;
             }


            FILE* pArchivo = fopen("clientes.dat", "rb+");
            if (!pArchivo) {
                cout << "No se pudo abrir clientes.dat\n";
                return;
            }

            fseek(pArchivo, sizeof(Cliente) * i, SEEK_SET);
            fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
            fclose(pArchivo);

            cout << "\nCliente actualizado correctamente.\n";
            return;
        }
    }

    cout << "No se encontro un cliente con ese ID.\n";
}

// ===== CAMBIAR ESTADO =====

void Cliente::cambiarEstadoPorID() {
    Archivos archivo;

    int idBuscado = InputManager::leerInt("Ingrese el ID del cliente: ");
    int cantidad = archivo.cantidadRegistrosCliente();

    for (int i = 0; i < cantidad; i++) {

        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idBuscado) {

            cout << "\nCliente encontrado:\n";
            cliente.mostrar();


            if (!InputManager::confirmar("Desea modificar el estado de este cliente? (s/n): "))
                return;


            const char* estados[] = {
                "Activo",
                "Inactivo",
                "Suspendido"
            };

            int numEstados = 3;

            cout << "\n--- SELECCIONE EL NUEVO ESTADO ---\n";
            int opcion = InputManager::seleccionarOpcion(
                "Elija una opcion (1-3): ",
                estados,
                numEstados
            );


            bool nuevoEstadoLogico = (opcion == 1);

            cliente.setEstado(nuevoEstadoLogico);


            FILE* pArchivo = fopen("clientes.dat", "rb+");
            if (!pArchivo) {
                cout << "No se pudo abrir clientes.dat para modificar.\n";
                return;
            }

            fseek(pArchivo, sizeof(Cliente) * i, SEEK_SET);
            fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
            fclose(pArchivo);

            cout << "\nEstado modificado correctamente.\n";
            cout << "Nuevo estado: " << estados[opcion - 1] << endl;

            return;
        }
    }

    cout << "No se encontro un cliente con ese ID.\n";
}

    cout << "\n========== LISTADO DE CLIENTES ==========\n";

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        cout << "-----------------------------------------\n";
        cout << "ID: " << cliente.getID() << endl;
        cout << "Nombre: " << cliente.getNombre() << " " << cliente.getApellido() << endl;
        cout << "Direccion: " << cliente.getDireccion() << endl;
        cout << "Telefono: " << cliente.getTelefono() << endl;
        cout << "Email: " << cliente.getEmail() << endl;
        cout << "Cantidad de caballos: " << cliente.getCantidadCaballos() << endl;
        cout << "Estado: " << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;
    }

    cout << "-----------------------------------------\n";
    cout << "Total de clientes: " << cantidad << endl;
}

