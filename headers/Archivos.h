#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <Cliente.h>
#include <Material.h>
#include <Agenda.h>
#include <MaterialesUsados.h>
#include <Usuario.h>
#include <Trabajo.h>

class Caballo;

class Archivos
{
    public:
    bool guardarArchivoCaballo(Caballo caballo);
    bool guardarArchivoAgenda(Agenda agenda);
    bool guardarArchivoMaterial(Material& material);
    bool guardarArchivoCliente (const Cliente& cliente);
    bool guardarArchivoCliente (const Usuario& usuario);
    bool guardarArchivoTrabajo (Trabajo& trabajo);
    bool guardarArchivoUsuario (const Usuario& usuario);
    bool modificarRegistroCaballo(const Caballo& caballo, int pos);
    bool modificarRegistroMaterial(Material& material, int pos);
    bool guardarArchivoMaterialesUsados(MaterialesUsados& materialesUsados);
    bool existeUsuarioPorID(int idBuscado);
    
    void listarCaballosPorCliente(int idCliente);
    void calcularRecaudacionAnualPorMes();
    void calcularRecaudacionPorCliente();
    void consumoMaterialesPorAno();
    void listarTodosLosCaballos();
    
    int buscarCaballoPorID(int idBuscado);
    int buscarMaterialPorID(int id);
    int cantidadRegistrosCaballo();
    int cantidadRegistrosAgenda();
    int cantidadRegistrosMaterial();
    int cantidadRegistrosMaterialesUsados();
    int cantidadRegistrosCliente();
    int cantidadRegistrosTrabajo();
    int cantidadRegistrosUsuario();
    int obtenerUltimoIDCaballo();
    int obtenerUltimoIDUsuario();

    Caballo leerRegistroCaballo(int pos);
    Agenda leerRegistroAgenda(int pos);
    Material leerRegistroMaterial(int pos);
    MaterialesUsados leerRegistroMaterialesUsados(int pos);
    Cliente leerRegistroCliente(int pos);
    Trabajo leerRegistroTrabajo(int pos);
    Usuario leerRegistroUsuario(int pos);







};

#endif // ARCHIVOS_H
