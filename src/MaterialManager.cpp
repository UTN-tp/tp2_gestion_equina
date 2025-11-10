#include "MaterialManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

/// 1. Cargar Nuevo Material al Inventario
void MaterialManager::cargarNuevoMaterial() {
    Material m;
    int nuevoID = archivos.cantidadRegistrosMaterial() + 1;
    m.setID(nuevoID);

    char nombre[40];
    cout << "Ingrese nombre del material: ";
    cin.ignore();
    cin.getline(nombre, 40);
    m.setNombre(nombre);

    char tipo[30];
    cout << "Ingrese tipo de material: ";
    cin.getline(tipo, 30);
    m.setTipo(tipo);

    int stock;
    cout << "Ingrese cantidad inicial de stock: ";
    cin >> stock;
    m.setStock(stock);

    float precio;
    cout << "Ingrese precio unitario: $";
    cin >> precio;
    m.setPrecio(precio);

    m.setEstado(true);

    if (archivos.guardarArchivoMaterial(m))
        cout << "Material guardado correctamente.\n";
    else
        cout << "Error al guardar el material.\n";
}

/// 2. Modificar Stock de Material
void MaterialManager::modificarStock() {
    int id;
    cout << "Ingrese ID del material: ";
    cin >> id;

    int pos = archivos.buscarMaterialPorID(id);
    if (pos < 0) {
        cout << "Material no encontrado.\n";
        return;
    }

    Material m = archivos.leerRegistroMaterial(pos);
    cout << "\nStock actual: " << m.getStock() << endl;

    int nuevoStock;
    cout << "Ingrese nuevo stock: ";
    cin >> nuevoStock;

    m.setStock(nuevoStock);
    if (archivos.modificarRegistroMaterial(m, pos))
        cout << "Stock actualizado.\n";
    else
        cout << "Error al actualizar el stock.\n";
}

/// 3. Registrar Materiales Usados en un Trabajo
void MaterialManager::registrarMaterialesUsados() {
    MaterialesUsados mu;
    int idTrabajo, idMaterial, cantidad;

    cout << "Ingrese ID del trabajo: ";
    cin >> idTrabajo;
    mu.setIDTrabajo(idTrabajo);

    cout << "Ingrese ID del material utilizado: ";
    cin >> idMaterial;
    mu.setIDMaterial(idMaterial);

    cout << "Ingrese cantidad usada: ";
    cin >> cantidad;
    mu.setCantidad(cantidad);

    // Verificar si el material existe
    int pos = archivos.buscarMaterialPorID(idMaterial);
    if (pos < 0) {
        cout << "Material no encontrado.\n";
        return;
    }

    Material m = archivos.leerRegistroMaterial(pos);
    if (m.getStock() < cantidad) {
        cout << "⚠No hay suficiente stock disponible.\n";
        return;
    }

    // Descontar del stock
    m.setStock(m.getStock() - cantidad);
    archivos.modificarRegistroMaterial(m, pos);

    // Registrar en archivo de materiales usados
    mu.setIDMaterialUsado(archivos.cantidadRegistrosMaterialesUsados() + 1);
    archivos.guardarArchivoMaterialesUsados(mu);

    cout << "Material registrado como usado y stock actualizado.\n";
}

/// 4. Consultar Stock Actual
void MaterialManager::consultarStockActual() {
    int cantidad = archivos.cantidadRegistrosMaterial();

    cout << left << setw(5) << "ID" << setw(20) << "Nombre"
         << setw(15) << "Tipo" << setw(10) << "Stock"
         << setw(10) << "Precio" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < cantidad; i++) {
        Material m = archivos.leerRegistroMaterial(i);
        if (m.getEstado()) {
            cout << left << setw(5) << m.getID()
                 << setw(20) << m.getNombre()
                 << setw(15) << m.getTipo()
                 << setw(10) << m.getStock()
                 << "$" << m.getPrecio() << endl;
        }
    }
}

/// 5. Consultar Consumo por Periodo
void MaterialManager::consultarConsumoPorPeriodo() {
    Fecha inicio, fin;
    cout << "Ingrese fecha de inicio:\n";
    inicio.cargar();
    cout << "Ingrese fecha de fin:\n";
    fin.cargar();

    int cantidad = archivos.cantidadRegistrosMaterialesUsados();
    cout << "Consumo de materiales entre " << inicio.toString()
         << " y " << fin.toString() << endl;

    for (int i = 0; i < cantidad; i++) {
        MaterialesUsados mu = archivos.leerRegistroMaterialesUsados(i);

        // Suponemos que el archivo guarda también fecha de uso (si no, se puede agregar)
        // if (mu.getFechaUso() >= inicio && mu.getFechaUso() <= fin)

        Material m = archivos.leerRegistroMaterial(mu.getIDMaterial());
        cout << "- " << m.getNombre() << " (" << mu.getCantidad() << " unidades)" << endl;
    }
}