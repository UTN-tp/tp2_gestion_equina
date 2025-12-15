#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // para rename, remove
#include "Material.h"
#include "Cliente.h"
#include "Usuario.h"
#include "MaterialesUsados.h"
#include "Archivos.h"

using namespace std;

class Configuracion {
public:

    bool exportarDatos();


    bool importarDatos();


    bool generarCSV(const string& nombreArchivoBinario, const string& nombreCSV);
};

#endif