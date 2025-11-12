#include "MaterialManager.h"
#include <iostream>
#include <iomanip>
using namespace std;

/// 1. Cargar Nuevo Material al Inventario
void MaterialManager::cargarNuevoMaterial() {
    if (!InputManager::confirmar("Desea cargar un nuevo material? (s/n): "))
        return;

    Material m;
    int nuevoID = archivos.cantidadRegistrosMaterial() + 1;
    m.setID(nuevoID);

    cout << "\n=== CARGA DE MATERIAL ===\n";

    string nombre = InputManager::leerLinea("Nombre del material: ");
    m.setNombre(nombre.c_str());

    string tipo = InputManager::leerLinea("Tipo de material: ");
    m.setTipo(tipo.c_str());

    int stock = InputManager::leerInt("Cantidad inicial de stock: ");
    m.setStock(stock);

    float precio = InputManager::leerFloat("Precio unitario: $");
    m.setPrecio(precio);

    m.setEstado(true);

    // --- Confirmación previa al guardado ---
    cout << "\n--- CONFIRMAR DATOS DEL MATERIAL ---\n";
    cout << "ID: " << m.getID() << endl;
    cout << "Nombre: " << m.getNombre() << endl;
    cout << "Tipo: " << m.getTipo() << endl;
    cout << "Stock: " << m.getStock() << endl;
    cout << "Precio: $" << m.getPrecio() << endl;
    cout << "------------------------------------\n";

    if (!InputManager::confirmar("¿Desea guardar este material? (s/n): ")) {
        cout << "\nCarga cancelada. No se guardaron datos.\n";
        return;
    }

    if (archivos.guardarArchivoMaterial(m))
        cout << "Material guardado correctamente.\n";
    else
        cout << "Error al guardar el material.\n";
}


/// 2. Modificar Stock de Material
void MaterialManager::modificarStock() {
    int id = InputManager::leerInt("Ingrese ID del material: ");

    int pos = archivos.buscarMaterialPorID(id);
    if (pos < 0) {
        cout << "Material no encontrado.\n";
        return;
    }

    Material m = archivos.leerRegistroMaterial(pos);
    cout << "\nStock actual: " << m.getStock() << endl;
    cout << "\n--- MATERIAL ENCONTRADO ---\n";
     cout << "ID: " << m.getID() << endl;
     cout << "Nombre: " << m.getNombre() << endl;
     cout << "Stock actual: " << m.getStock() << endl;

     if (!InputManager::confirmar("Desea modificar el stock? (s/n): "))
          return;


    int nuevoStock = InputManager::leerInt("Ingrese nuevo stock: ");
     cout << "\nNuevo stock será: " << nuevoStock << endl;
    if (!InputManager::confirmar("¿Confirmar cambios? (s/n): "))
        return;


    m.setStock(nuevoStock);
    

    if (archivos.modificarRegistroMaterial(m, pos))
        cout << "Stock actualizado.\n";
    else
        cout << "Error al actualizar el stock.\n";
}

/// 3. Registrar Materiales Usados en un Trabajo
void MaterialManager::registrarMaterialesUsados() {
    
     if (!InputManager::confirmar("Desea registrar materiales usados? (s/n): "))
        return;

    MaterialesUsados mu;
    
    int idTrabajo = InputManager::leerInt("ID del trabajo: ");
    mu.setIDTrabajo(idTrabajo);
    
    int idMaterial = InputManager::leerInt("ID del material utilizado: ");
    mu.setIDMaterial(idMaterial);
    
    int cantidad = InputManager::leerInt("Ingrese cantidad usada: ");
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