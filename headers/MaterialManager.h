
#ifndef MATERIALMANAGER_H
#define MATERIALMANAGER_H

#include "Material.h"
#include "MaterialesUsados.h"
#include "Archivos.h"
#include "Fecha.h"
#include <iostream>
using namespace std;

class MaterialManager {
private:
    Archivos archivos;

public:
    void cargarNuevoMaterial();
    void modificarStock();
    void registrarMaterialesUsados();
    void consultarStockActual();
    void consultarConsumoPorPeriodo();
};

#endif