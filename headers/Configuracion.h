#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>  // se agrega
#include <cstdio> // para rename, remove
#include "Material.h"
#include "Cliente.h"
#include "Usuario.h"
#include "MaterialesUsados.h"
#include "Archivos.h"
#include "InputManager.h"  // se agrega

using namespace std;

class Configuracion {
private:               // agrego atributo privado
    vector<string> obtenerArchivosDisponibles(); // agrego esto
public:

    bool exportarDatos();


    bool importarDatos();

    bool generarCSV();   // agrego

};


#endif
