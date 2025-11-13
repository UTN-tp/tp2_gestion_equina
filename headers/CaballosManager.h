#pragma once
#include "Caballo.h"
#include "Archivos.h"

class CaballosManager {
private:
    Archivos archivos;

public:
    void cargarCaballo();
    void modificarCaballo();
    void consultarPorID();
    void listarPorCliente();
    void cambiarEstado();
    void listarTodos();
};


