#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include <Cliente.h>
#include <Material.h>
#include <Agenda.h>
#include <Caballo.h>
#include <MaterialesUsados.h>
#include <Usuario.h>
#include <Trabajo.h>


class Archivos
{
    public:
    bool guardarArchivoCaballo(Caballo caballo);
    bool guardarArchivoAgenda(Agenda agenda);
    bool guardarArchivoMaterial (Material material);
    bool guardarArchivoMaterialesUsados (MaterialesUsados materialesUsados);
    bool guardarArchivoCliente (Cliente cliente);
    bool guardarArchivoTrabajo (Trabajo trabajo);
    bool guardarArchivoUsuario (Usuario usuario);
    bool modificarRegistroCaballo(const Caballo& caballo, int pos);// agrego
    bool modificarRegistroMaterial(const Material& material, int pos); //material: agrego


    void listarCaballosPorCliente(int idCliente); //agrego
    void listarTodosLosCaballos();  //agrego 2


    int buscarCaballoPorID(int idBuscado); //agrego
    int buscarMaterialPorID(int idBuscado); //material: agrego
    int cantidadRegistrosCaballo();
    int cantidadRegistrosAgenda();
    int cantidadRegistrosMaterial();
    int cantidadRegistrosMaterialesUsados();
    int cantidadRegistrosCliente();
    int cantidadRegistrosTrabajo();
    int cantidadRegistrosUsuario();
    int obtenerUltimoIDCaballo();   // agrego 1

    Caballo leerRegistroCaballo(int pos);
    Agenda leerRegistroAgenda(int pos);
    Material leerRegistroMaterial(int pos);
    MaterialesUsados leerRegistroMaterialesUsados(int pos);
    Cliente leerRegistroCliente(int pos);
    Trabajo leerRegistroTrabajo(int pos);
    Usuario leerRegistroUsuario(int pos);



};

#endif // ARCHIVOS_H
