#include "Configuracion.h"
#include <vector>

#include "rlutil.h"

 vector<string> Configuracion::obtenerArchivosDisponibles() {
    return {
        "cliente.dat",
        "materiales.dat",
        "materiales_usados.dat",
        "caballos.dat"
    };
}

/// -------- EXPORTAR --------
bool Configuracion::exportarDatos() {

    auto archivos = obtenerArchivosDisponibles();

    int idx = InputManager::seleccionarIndice(
        "Archivos disponibles para EXPORTAR",
        archivos
    );

    cout << "\nArchivo seleccionado: " << archivos[idx] << endl;

    if (!InputManager::confirmar("Confirma exportar este archivo?(s/n):")) {
        cout << "Operacion cancelada.\n";
        return false;
    }

    string origenNombre = archivos[idx];
    string destinoNombre = origenNombre + ".bak";

    FILE* origen = fopen(origenNombre.c_str(), "rb");
    if (!origen) {
        cout << "No se encontro el archivo.\n";
        return false;
    }

    FILE* destino = fopen(destinoNombre.c_str(), "wb");
    if (!destino) {
        fclose(origen);
        cout << "No se pudo crear el backup.\n";
        return false;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), origen)) > 0) {
        fwrite(buffer, 1, bytes, destino);
    }

    fclose(origen);
    fclose(destino);

    cout << "Exportado correctamente: " << destinoNombre << endl;
    rlutil::anykey();
    return true;
}

/// -------- IMPORTAR --------
bool Configuracion::importarDatos() {

    auto archivos = obtenerArchivosDisponibles();

    int idx = InputManager::seleccionarIndice(
        "Archivos disponibles para IMPORTAR",
        archivos
    );

    cout << "\nArchivo seleccionado: " << archivos[idx] << endl;
    cout << "ATENCION: se sobrescribira el archivo actual.\n";

    if (!InputManager::confirmar("Confirma importar este archivo?(s/n):")) {
        cout << "Operacion cancelada.\n";
        return false;
    }

    string destinoNombre = archivos[idx];
    string respaldoNombre = destinoNombre + ".bak";

    FILE* origen = fopen(respaldoNombre.c_str(), "rb");
    if (!origen) {
        cout << "No existe respaldo.\n";
        return false;
    }

    FILE* destino = fopen(destinoNombre.c_str(), "wb");
    if (!destino) {
        fclose(origen);
        cout << "No se pudo restaurar el archivo.\n";
        return false;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), origen)) > 0) {
        fwrite(buffer, 1, bytes, destino);
    }

    fclose(origen);
    fclose(destino);

    cout << "Importado correctamente: " << destinoNombre << endl;
    rlutil::anykey();
    return true;
}

/// -------- CSV CON CONFIRMACION --------
bool Configuracion::generarCSV() {

    auto archivos = obtenerArchivosDisponibles();

    int idx = InputManager::seleccionarIndice(
        "Seleccione archivo para generar CSV",
        archivos
    );

    string binario = archivos[idx];
    string csvNombre = binario + ".csv";

    cout << "\nArchivo seleccionado: " << binario << endl;
    cout << "Se generara: " << csvNombre << endl;

    if (!InputManager::confirmar("Confirma generar el CSV?(s/n):")) {
        cout << "Operacion cancelada.\n";
        return false;
    }

    ifstream bin(binario, ios::binary);
    ofstream csv(csvNombre);

    if (!bin || !csv) {
        cout << "Error al abrir archivos.\n";
        return false;
    }

    if (binario == "materiales.dat") {
        csv << "ID,Nombre,Tipo,Stock,Precio,Estado\n";
        Material m;
        while (bin.read(reinterpret_cast<char*>(&m), sizeof(Material))) {
            csv << m.getID() << "," << m.getNombre() << "," << m.getTipo()
                << "," << m.getStock() << "," << m.getPrecio()
                << "," << (m.getEstado() ? "Activo" : "Inactivo") << "\n";
        }
    }
    else if (binario == "cliente.dat") {
        csv << "ID,Nombre,Apellido,Direccion,CantidadCaballos,Estado\n";
        Cliente c;
        while (bin.read(reinterpret_cast<char*>(&c), sizeof(Cliente))) {
            csv << c.getID() << "," << c.getNombre() << "," << c.getApellido()
                << "," << c.getDireccion() << "," << c.getCantidadCaballos()
                << "," << (c.getEstado() ? "Activo" : "Inactivo") << "\n";
        }
    }
    else if (binario == "caballos.dat") {
        csv << "ID,Nombre,Raza,Edad,IDCliente,Estado\n";
        Caballo c;
        while (bin.read(reinterpret_cast<char*>(&c), sizeof(Caballo))) {
            csv << c.getID() << "," << c.getNombre() << "," << c.getRaza()
                << "," << c.getEdad() << "," << c.getIDCliente()
                << "," << (c.getEstado() ? "Activo" : "Inactivo") << "\n";
        }
    }
    else if (binario == "materiales_usados.dat") {
        csv << "IDMaterialUsado,IDTrabajo,IDMaterial,Cantidad\n";
        MaterialesUsados mu;
        while (bin.read(reinterpret_cast<char*>(&mu), sizeof(MaterialesUsados))) {
            csv << mu.getIDMaterialUsado() << "," << mu.getIDTrabajo()
                << "," << mu.getIDMaterial() << "," << mu.getCantidad() << "\n";
        }
    }

    cout << "CSV generado correctamente.\n";
    rlutil::anykey();
    return true;
}
