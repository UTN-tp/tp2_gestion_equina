#include "MaterialesManager.h"
#include "Archivos.h"
#include "InputManager.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

void MaterialesManager::cargarNuevoMaterial() {
    Material m;

    int maxID = 0;
    int cant = archivos.cantidadRegistrosMaterial();
    for (int i = 0; i < cant; i++) {
        Material aux = archivos.leerRegistroMaterial(i);
        if (aux.getID() > maxID) maxID = aux.getID();
    }
    m.setID(maxID + 1);

    string nombre = InputManager::leerLinea("Nombre de material: ", 40);
    m.setNombre(nombre.c_str());

    string tipo = InputManager::leerLinea("Tipo de material: ", 30);
    m.setTipo(tipo.c_str());

    int stock = InputManager::leerInt("Stock: ");
    m.setStock(stock);

    float precio = InputManager::leerFloat("Precio: ");
    m.setPrecio(precio);

    m.setEstado(true);



    if (archivos.guardarArchivoMaterial(m))
        cout << "Material registrado correctamente.\n";
    else
        cout << "No se pudo registrar el material.\n";
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

void MaterialesManager::registrarMaterialesUsados() {
    int idTrabajo, posTrabajo = -1;
    Trabajo trab;

    cout << "--- Registro de Materiales por Trabajo ---" << endl;
    idTrabajo = InputManager::leerInt("Ingrese ID del trabajo: ");

    // 1. Buscar el Trabajo en el archivo de trabajos
    int cantT = archivos.cantidadRegistrosTrabajo();
    for (int i = 0; i < cantT; i++) {
        Trabajo aux = archivos.leerRegistroTrabajo(i);
        if (aux.getID() == idTrabajo) {
            trab = aux;
            posTrabajo = i;
            break;
        }
    }

    if (posTrabajo == -1) {
        cout << "Error: El trabajo con ID " << idTrabajo << " no existe en los registros de trabajos realizados." << endl;
        return;
    }


    cout << "\n========================================" << endl;
    cout << "DETALLES DEL TRABAJO:" << endl;
    trab.mostrar(); // Muestra IDs de cliente, caballo y monto


    int posCab = archivos.buscarCaballoPorID(trab.getIdCaballo());
    if (posCab != -1) {
        Caballo c = archivos.leerRegistroCaballo(posCab);
        cout << "Nombre del Caballo: " << c.getNombre() << endl;
    } else {
        cout << "Caballo: No se pudo encontrar el nombre para el ID " << trab.getIdCaballo() << endl;
    }


    int posCli = archivos.buscarClientePorID(trab.getIdCliente());
    if (posCli != -1) {
        Cliente cl = archivos.leerRegistroCliente(posCli);
        cout << "Cliente: " << cl.getNombre() << " " << cl.getApellido() << endl;
    }
    cout << "========================================\n" << endl;

    if (!InputManager::confirmar("Es correcto este trabajo? (S/N): ")) {
        return;
    }


    bool continuarCargando = true;
    Fecha fechaActual;
    cout << "Ingrese la fecha de uso de los materiales:" << endl;
    fechaActual.cargar();

    while (continuarCargando) {

        cout << "\n--- Lista de Materiales Disponibles ---" << endl;
        consultarStockActual();

        int idMat = InputManager::leerInt("\nIngrese ID del material a cargar: ");
        int posMat = archivos.buscarMaterialPorID(idMat);

        if (posMat < 0) {
            cout << "Error: El ID de material no existe." << endl;
        } else {
            Material m = archivos.leerRegistroMaterial(posMat);

            cout << "Seleccionado: " << m.getNombre() << " | Stock: " << m.getStock() << endl;
            int cantUsada = InputManager::leerInt("Ingrese cantidad usada: ");

            if (cantUsada <= 0) {
                cout << "La cantidad debe ser mayor a cero." << endl;
            } else if (m.getStock() < cantUsada) {
                cout << "Error: Stock insuficiente (Disponible: " << m.getStock() << ")." << endl;
            } else {
                if (InputManager::confirmar("Confirmar registro de este material? (S/N): ")) {
                    // Actualizar Stock
                    m.setStock(m.getStock() - cantUsada);
                    archivos.modificarRegistroMaterial(m, posMat);

                    // Registrar Uso
                    MaterialesUsados mu;
                    mu.setIDMaterialUsado(archivos.cantidadRegistrosMaterialesUsados() + 1);
                    mu.setIDTrabajo(idTrabajo);
                    mu.setIDMaterial(idMat);
                    mu.setCantidad(cantUsada);
                    mu.setFechaUso(fechaActual);

                    if (archivos.guardarArchivoMaterialesUsados(mu)) {
                        cout << "Material cargado exitosamente!" << endl;
                    }
                }
            }
        }
        continuarCargando = InputManager::confirmar("\nDesea cargar otro material para este trabajo? (S/N): ");
    }
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
        if (!m.getEstado() || m.getID() <= 0) continue; // agrego
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
        if (mu.getIDMaterialUsado() <= 0) continue; // agrego
        Fecha f = mu.getFechaUso();

        if ( !f.fechaMenor(inicio) && !fin.fechaMenor(f) ) {
            Material m = arc.leerRegistroMaterial(mu.getIDMaterial());
            cout << "- " << m.getNombre() << " (" << mu.getCantidad() << " unidades)" << endl;
        }
    }
}
