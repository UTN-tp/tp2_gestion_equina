
#include "./Cliente.h"
#include <cstring>
#include "./Archivos.h"


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

void Cliente::cargar() {
    Usuario::cargar();

    cout << "Direccion: ";
    cin.ignore();
    cin.getline(direccion, sizeof(direccion));

    cout << "Cantidad de caballos: ";
    cin >> cantidadCaballos;
    cin.ignore();

    // Instanciamos Archivos y guardamos directamente
    Archivos archivo;
    if (archivo.guardarArchivoCliente(*this)) {
        cout << "\nCliente guardado correctamente en 'cliente.dat'\n";
    } else {
        cout << "\nError al guardar el cliente.\n";
    }

    if (!archivo.guardarArchivoUsuario(static_cast<Usuario>(*this))) {
        cout << "Error al guardar el usuario base.\n";
    }

}

void Cliente::mostrar() const {
    Usuario::mostrar();
    cout << "Direccion: " << direccion << endl;
    cout << "Cantidad de caballos: " << cantidadCaballos << endl;
}

void Cliente::buscarPorID() {
    int idBuscado;
    cout << "Ingrese el ID del cliente a buscar: ";
    cin >> idBuscado;

    Archivos archivo;
    int cantidad = archivo.cantidadRegistrosCliente();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);
        if (cliente.getID() == idBuscado) {
            cout << "\nCliente encontrado:\n";
            cliente.mostrar();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró un cliente con el ID " << idBuscado << endl;
    }
}

int Cliente::buscarPorID(int idCliente) {

    int idBuscado = idCliente;

    Archivos archivo;
    int cantidad = archivo.cantidadRegistrosCliente();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);
        if (cliente.getID() == idBuscado) {
            cout << "\nCliente encontrado:\n";
            cliente.mostrar();
            return  cliente.getID();
        }
    }

    if (!encontrado) {
        cout << "No se encontró un cliente con el ID " << idBuscado << endl;
        return 0;
    }
}


void Cliente::editarPorID() {
    Archivos archivo;
    int idBuscado;

    cout << "Ingrese el ID del cliente que desea modificar: ";
    cin >> idBuscado;
    cin.ignore();

    int cantidad = archivo.cantidadRegistrosCliente();
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idBuscado) {
            encontrado = true;
            cout << "\nCliente encontrado:\n";
            cliente.mostrar();

            cout << "\n--- Modificar datos (Enter = no modificar) ---\n";

            string buffer;

            // Nombre
            cout << "Nuevo nombre (" << cliente.getNombre() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                strncpy(cliente.nombre, buffer.c_str(), sizeof(cliente.nombre));

            // Apellido
            cout << "Nuevo apellido (" << cliente.getApellido() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                strncpy(cliente.apellido, buffer.c_str(), sizeof(cliente.apellido));

            // Teléfono
            cout << "Nuevo telefono (" << cliente.getTelefono() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                strncpy(cliente.telefono, buffer.c_str(), sizeof(cliente.telefono));

            // Email
            cout << "Nuevo email (" << cliente.getEmail() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                strncpy(cliente.email, buffer.c_str(), sizeof(cliente.email));

            // Dirección
            cout << "Nueva direccion (" << cliente.getDireccion() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                strncpy(cliente.direccion, buffer.c_str(), sizeof(cliente.direccion));

            // Cantidad de caballos
            cout << "Nueva cantidad de caballos (" << cliente.getCantidadCaballos() << "): ";
            getline(cin, buffer);
            if (!buffer.empty())
                cliente.cantidadCaballos = stoi(buffer);

            // Guardar cambios
            FILE* pArchivo = fopen("clientes.dat", "rb+");
            if (pArchivo == nullptr) {
                cout << " No se pudo abrir cliente.dat para modificar.\n";
                return;
            }

            fseek(pArchivo, sizeof(Cliente) * i, SEEK_SET);
            fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
            fclose(pArchivo);

            cout << "\nCliente actualizado correctamente.\n";
            return;
        }
    }

    if (!encontrado)
        cout << " No se encontró un cliente con ese ID.\n";

}

void Cliente::cambiarEstadoPorID() {
    Archivos archivo;
    int idBuscado;
    bool encontrado = false;

    cout << "Ingrese el ID del cliente que desea cambiar de estado: ";
    cin >> idBuscado;
    cin.ignore();

    int cantidad = archivo.cantidadRegistrosCliente();

    for (int i = 0; i < cantidad; i++) {
        Cliente cliente = archivo.leerRegistroCliente(i);

        if (cliente.getID() == idBuscado) {
            encontrado = true;

            cout << "\nCliente encontrado:\n";
            cliente.mostrar();

            cout << "\nEstado actual: "
                 << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;

            char opcion;
            cout << "Desea cambiar el estado? (s/n): ";
            cin >> opcion;
            cin.ignore();

            if (opcion == 's' || opcion == 'S') {
                cliente.setEstado(!cliente.getEstado());
                cout << "Nuevo estado: "
                     << (cliente.getEstado() ? "Activo" : "Inactivo") << endl;

                FILE* pArchivo = fopen("clientes.dat", "rb+");
                if (pArchivo == nullptr) {
                    cout << "No se pudo abrir cliente.dat para modificar.\n";
                    return;
                }

                fseek(pArchivo, sizeof(Cliente) * i, SEEK_SET);
                fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
                fclose(pArchivo);

                cout << "\nEstado actualizado correctamente.\n";
            } else {
                cout << "\nNo se realizaron cambios.\n";
            }

            return;
        }
    }

    if (!encontrado)
        cout << "No se encontro un cliente con ese ID.\n";
}

void Cliente::mostrarListado() {
    Archivos archivo;
    int cantidad = archivo.cantidadRegistrosCliente();

    if (cantidad == 0) {
        cout << "No hay clientes registrados.\n";
        return;
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

