#pragma once
#include "Material.h"
#include "Archivos.h"

class MaterialesManager{

    private:
        Archivos archivos;

    public:
        void cargarNuevoMaterial();
        void modificarStockMaterial();
        void registrarMaterialesUsados();
        void consultarStockActual();
        void consultarPeriodoConsumo();
        int getStockPorID(int idMaterial);
};


