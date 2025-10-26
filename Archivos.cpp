#include "Archivos.h"
#include <Cliente.h>
#include <Material.h>
#include <Agenda.h>
#include <Caballo.h>
#include <MaterialesUsados.h>
#include <Usuario.h>
#include <Trabajo.h>

    //Guardar
    bool Archivos::guardarArchivoCaballo(Caballo caballo){
        FILE *pArchivo = fopen("caballos.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&caballo, sizeof(Caballo), 1, pArchivo);
        fclose(pArchivo);

        return ok;

    }

    bool Archivos::guardarArchivoAgenda(Agenda agenda){
        FILE *pArchivo = fopen("agenda.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&agenda, sizeof(Agenda), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool guardarArchivoMaterial (Material material){
        FILE *pArchivo = fopen("materiales.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&material, sizeof(Material), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool guardarArchivoMaterialesUsados (MaterialesUsados materialesUsados){
        FILE *pArchivo = fopen("materialesusados.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&materialesUsados, sizeof(MaterialesUsados), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool guardarArchivoCliente (Cliente cliente){
        FILE *pArchivo = fopen("cliente.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool guardarArchivoTrabajo (Trabajo trabajo){
        FILE *pArchivo = fopen("trabajo.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&trabajo, sizeof(Trabajo), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool guardarArchivoUsuario (Usuario usuario){
        FILE *pArchivo = fopen("usuario.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&usuario, sizeof(Usuario), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    //Cantidad Registros
    int Archivos::cantidadRegistrosCaballo(){
        FILE *pArchivo = fopen("caballos.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Caballo);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosAgenda(){
        FILE *pArchivo = fopen("agenda.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Agenda);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosMaterial(){
        FILE *pArchivo = fopen("material.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Material);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosMaterialesUsados(){
        FILE *pArchivo = fopen("materiales_usados.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(MaterialesUsados);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosCliente(){
        FILE *pArchivo = fopen("registros_cliente.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosTrabajo(){
        FILE *pArchivo = fopen("trabajo.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Trabajo);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int cantidadRegistrosUsuario(){
        FILE *pArchivo = fopen("usuario.dat", "rb");
        if(pArchivo == NULL){

            return 0;
     }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Usuario);
        fclose(pArchivo);

        return cantidadRegistros;
    }


    //Leer
    Caballo Archivos::leerRegistroCaballo(int pos){
        FILE *pArchivo = fopen("caballo.dat", "rb");
        if(pArchivo == NULL){
            return Caballo();
        }
        Caballo caballo;
        fseek(pArchivo, sizeof(Caballo) * pos, SEEK_SET);
        fread(&caballo, sizeof(Caballo), 1, pArchivo);
        fclose(pArchivo);
        return caballo;
    }

    Agenda Archivos::leerRegistroAgenda(int pos){
        FILE *pArchivo = fopen("agenda.dat", "rb");
        if(pArchivo == NULL){
            return Agenda();
        }
        Agenda agenda;
        fseek(pArchivo, sizeof(Agenda) * pos, SEEK_SET);
        fread(&agenda, sizeof(Agenda), 1, pArchivo);
        fclose(pArchivo);
        return agenda;

    }

    Material Archivos::leerRegistroMaterial(int pos){
        FILE *pArchivo = fopen("registro_material.dat", "rb");
        if(pArchivo == NULL){
            return Material();
        }
        Material material;
        fseek(pArchivo, sizeof(Material) * pos, SEEK_SET);
        fread(&material, sizeof(Agenda), 1, pArchivo);
        fclose(pArchivo);
        return material;
    }

    MaterialesUsados Archivos::leerRegistroMaterialesUsados(int pos){
        FILE *pArchivo = fopen("materiales_usados.dat", "rb");
        if(pArchivo == NULL){
            return MaterialesUsados();
        }
        MaterialesUsados materialesUsados;
        fseek(pArchivo, sizeof(MaterialesUsados) * pos, SEEK_SET);
        fread(&materialesUsados, sizeof(MaterialesUsados), 1, pArchivo);
        fclose(pArchivo);
        return materialesUsados;
    }

    Cliente Archivos::leerRegistroCliente(int pos){
        FILE *pArchivo = fopen("cliente.dat", "rb");
        if(pArchivo == NULL){
            return Cliente();
        }
        Cliente cliente;
        fseek(pArchivo, sizeof(Cliente) * pos, SEEK_SET);
        fread(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);
        return cliente;
    }

    Trabajo Archivos::leerRegistroTrabajo(int pos){
        FILE *pArchivo = fopen("trabajo.dat", "rb");
        if(pArchivo == NULL){
            return Trabajo();
        }
        Trabajo trabajo;
        fseek(pArchivo, sizeof(Trabajo) * pos, SEEK_SET);
        fread(&trabajo, sizeof(Trabajo), 1, pArchivo);
        fclose(pArchivo);
        return trabajo;
    }

    Usuario Archivos::leerRegistroUsuario(int pos){
        FILE *pArchivo = fopen("usuario.dat", "rb");
        if(pArchivo == NULL){
            return Usuario();
        }
        Usuario usuario;
        fseek(pArchivo, sizeof(Usuario) * pos, SEEK_SET);
        fread(&usuario, sizeof(Usuario), 1, pArchivo);
        fclose(pArchivo);
        return usuario;
    }
