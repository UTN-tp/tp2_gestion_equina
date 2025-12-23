#ifndef ARCHIVOS_H
#define ARCHIVOS_H
#include "Cliente.h"
#include "Material.h"
#include "Agenda.h"
#include "Caballo.h"
#include "MaterialesUsados.h"
#include "Usuario.h"
#include "Trabajo.h"


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
    bool modificarRegistroCliente(const Cliente cliente, int pos);
    Caballo obtenerCaballoPorIdCliente(int idCliente);
    int contarCaballosPorCliente(int idCliente);
    void cargarCaballosPorCliente(int idCliente, Caballo* vec, int cant);

    // metodo de validacion de mail
    bool existeEmailCliente(const char* emailNuevo);
    int buscarClientePorEmail(const char* emailBuscado);

    void listarCaballosPorCliente(int idCliente); //agrego
    void listarTodosLosCaballos();  //agrego 2
    void listarTodosLosClientes ();

    int buscarClientePorID(int idBuscado); //agrego nuevo
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

    // VALIDACION AGENDA
    bool validarExistenciaCaballo(int idCaballo, Caballo &caballo);

    Caballo leerRegistroCaballo(int pos);
    Agenda leerRegistroAgenda(int pos);
    Material leerRegistroMaterial(int pos);
    MaterialesUsados leerRegistroMaterialesUsados(int pos);
    Cliente leerRegistroCliente(int pos);
    Trabajo leerRegistroTrabajo(int pos);
    Usuario leerRegistroUsuario(int pos);



};

#endif // ARCHIVOS_H
