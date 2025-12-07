#include "MaterialesManager.h"
#include "Archivos.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void MaterialesManager::cargarNuevoMaterial(){
    Material m;

    int nuevoID = archivos.cantidadRegistrosMaterial() + 1;
    m.setID(nuevoID);

    cout << "Nombre de material: ";
    char nombreMaterial[40];
    cin.getline(nombreMaterial, 40);
    m.setNombre(nombreMaterial);

    char tipoMaterial[30];
    cout << "Tipo de material: ";
    cin.getline(tipoMaterial, 30);
    m.setTipo(tipoMaterial);

    cout << "Stock: ";
    int stock;
     cin >> stock;
    m.setStock(stock);

    float precio;
    cout << "Precio: ";
    cin >> precio;
    m.setPrecio(precio);

    m.setEstado(true);

    if (archivos.guardarArchivoMaterial(m) == true ){
        cout << "Material registrado correctamente." << endl;
    }
    else {
        cout << "No se pudo registrar el material." << endl;
    }
}

void MaterialesManager::modificarStockMaterial(){

    int idMaterial;
    cout << "Ingrese ID del material a modificar stock: ";
    cin >> idMaterial;

    int pos = archivos.buscarMaterialPorID(idMaterial);
    if (pos < 0) {
        cout << "Material no encontrado.\n";
        return;
    }

    Material m = archivos.leerRegistroMaterial(pos);

    int nuevoStock;
    cout << "Nuevo stock: ";
    cin >> nuevoStock;
    m.setStock(nuevoStock);

    archivos.modificarRegistroMaterial(m, pos);
    cout << "Stock modificado correctamente.\n";
}

void MaterialesManager::registrarMaterialesUsados(){

    MaterialesUsados mu;
    Fecha fechaActual;
    int idTrabajo, idMaterial, cantidad;

    cout << "Ingrese la fecha actual: ";
    fechaActual.cargar();
    mu.setFechaUso(fechaActual);

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
        cout << "No hay suficiente stock disponible.\n";
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

void MaterialesManager::consultarStockActual() {
    int cantidad = archivos.cantidadRegistrosMaterial();
    // uso de la libreria iomanip para encabezado de tabla con formato fijo
    // left: alinea el texto a la izquierda dentro del ancho definido
    cout << left << setw(5) << "ID" << setw(20) << "Nombre";
    cout << setw(15) << "Tipo" << setw(10) << "Stock";                // setw: define el ancho de columna
    cout << setw(10) << "Precio" << endl;
    cout << string(60, '-') << endl;

    for (int i = 0; i < cantidad; i++) {
        Material m = archivos.leerRegistroMaterial(i);
        if (m.getEstado()) {      // se muestra solo materiales activos
            cout << left << setw(5) << m.getID();
            cout << setw(20) << m.getNombre();
            cout << setw(15) << m.getTipo();
            cout << setw(10) << m.getStock();
            cout << "$" << m.getPrecio() << endl;
        }
    }
}

void MaterialesManager::consultarPeriodoConsumo(){
    Fecha inicio;
    Fecha fin;
    Archivos arc;
    cout << "Ingrese fecha de inicio:\n";
    inicio.cargar();
    cout << "Ingrese fecha de fin:\n";
    fin.cargar();

    int cantidad = arc.cantidadRegistrosMaterialesUsados();
    cout << "Consumo de materiales entre " << inicio.toString()
         << " y " << fin.toString() << endl;

    for (int i = 0; i < cantidad; i++) {
        MaterialesUsados mu = arc.leerRegistroMaterialesUsados(i);
        Fecha f = mu.getFechaUso();

        if ( !f.fechaMenor(inicio) && !fin.fechaMenor(f) ) {
            Material m = arc.leerRegistroMaterial(mu.getIDMaterial());
            cout << "- " << m.getNombre() << " (" << mu.getCantidad() << " unidades)" << endl;
        }
    }
}
