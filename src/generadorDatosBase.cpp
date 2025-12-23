#include <iostream>
#include "Archivos.h"
#include "Material.h"
#include "GeneradorDatosBase.h"

using namespace std;

    void cargarDatosBase() {
    Archivos archivos;

    if (archivos.cantidadRegistrosMaterial() == 0) {

        int idBase = archivos.obtenerUltimoIDMaterial();

        // --- Clavos ---
        Material m1;
        m1.setID(idBase);
        m1.setNombre("Clavos");
        m1.setTipo("Clavo");
        m1.setStock(0);
        m1.setPrecio(100);
        m1.setEstado(false);

        archivos.guardarArchivoMaterial(m1);

        // --- Herradura ---
        Material m2;
        m2.setID(idBase);
        m2.setNombre("Herradura");
        m2.setTipo("Herradura");
        m2.setStock(0);
        m2.setPrecio(2800);
        m2.setEstado(false);

        archivos.guardarArchivoMaterial(m2);
    }
}





