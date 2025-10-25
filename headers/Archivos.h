#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Usuario.h"
#include "Cliente.h"
#include "Caballo.h"
#include "Material.h"
#include "MaterialesUsados.h"
#include "Trabajo.h"
#include "Agenda.h"

class Archivos {
public:
    Archivos();
    ~Archivos();

    void crearArchivo(const std::string& nombreArchivo);
    void leerArchivo(const std::string& nombreArchivo);
    void modificarArchivo(const std::string& nombreArchivo);
    void eliminarArchivo(const std::string& nombreArchivo);

    void guardarCliente(const Cliente& cliente, const std::string& nombreArchivo);
    void cargarClientes(const std::string& nombreArchivo);
    void guardarCaballo(const Caballo& caballo, const std::string& nombreArchivo);
    void cargarCaballos(const std::string& nombreArchivo);
    void guardarMaterial(const Material& material, const std::string& nombreArchivo);
    void cargarMateriales(const std::string& nombreArchivo);
    void guardarTrabajo(const Trabajo& trabajo, const std::string& nombreArchivo);
    void cargarTrabajos(const std::string& nombreArchivo);
    void guardarAgenda(const Agenda& agenda, const std::string& nombreArchivo);
    void cargarAgendas(const std::string& nombreArchivo);
};

#endif