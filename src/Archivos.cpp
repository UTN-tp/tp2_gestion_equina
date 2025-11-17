#include "Archivos.h"
#include "Cliente.h"
#include "Material.h"
#include "Agenda.h"
#include "Caballo.h"
#include "MaterialesUsados.h"
#include "Usuario.h"
#include "Trabajo.h"


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


      bool Archivos::guardarArchivoMaterial (Material material){
        FILE *pArchivo = fopen("materiales.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&material, sizeof(Material), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoMaterialesUsados (MaterialesUsados materialesUsados){
        FILE *pArchivo = fopen("materiales_usados.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&materialesUsados, sizeof(MaterialesUsados), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoCliente (Cliente cliente){
        FILE *pArchivo = fopen("cliente.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoTrabajo (Trabajo trabajo){
        FILE *pArchivo = fopen("trabajo.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&trabajo, sizeof(Trabajo), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoUsuario (Usuario usuario){
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

    int Archivos::cantidadRegistrosAgenda(){
        FILE *pArchivo = fopen("agenda.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Agenda);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosMaterial(){
        FILE *pArchivo = fopen("materiales.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Material);
        fclose(pArchivo);

        return cantidadRegistros;
    }


    int Archivos::cantidadRegistrosMaterialesUsados(){
        FILE *pArchivo = fopen("materiales_usados.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(MaterialesUsados);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosCliente(){
        FILE *pArchivo = fopen("cliente.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosTrabajo(){
        FILE *pArchivo = fopen("trabajo.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Trabajo);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosUsuario(){
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
        FILE *pArchivo = fopen("caballos.dat", "rb");
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
        FILE *pArchivo = fopen("materiales.dat", "rb");
        if(pArchivo == NULL){
            return Material();
        }
        Material material;
        fseek(pArchivo, sizeof(Material) * pos, SEEK_SET);
        fread(&material, sizeof(Material), 1, pArchivo);
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

    // Buscar:
    //buscar por ID

    int Archivos::buscarCaballoPorID(int idBuscado) {
    FILE *pArchivo = fopen("caballos.dat", "rb");
    if (pArchivo == NULL) return -1;

    Caballo aux;
    int pos = 0;

    while (fread(&aux, sizeof(Caballo), 1, pArchivo)) {
        if (aux.getID() == idBuscado) {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }

    fclose(pArchivo);
    return -1;
}

int Archivos::buscarMaterialPorID(int idBuscado) {
    FILE *pArchivo = fopen("materiales.dat", "rb");
    if (pArchivo == NULL) return -1;

    Material aux;
    int pos = 0;

    while (fread(&aux, sizeof(Material), 1, pArchivo)) {
        if (aux.getID() == idBuscado) {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }

    fclose(pArchivo);
    return -1;
}



  //modificar registros

  bool Archivos::modificarRegistroCaballo(const Caballo& caballo, int pos) {
    FILE *pArchivo = fopen("caballos.dat", "rb+");
    if (pArchivo == NULL) return false;

    fseek(pArchivo, sizeof(Caballo) * pos, SEEK_SET);
    bool ok = fwrite(&caballo, sizeof(Caballo), 1, pArchivo);
    fclose(pArchivo);

    return ok;
}

    bool Archivos::modificarRegistroMaterial(const Material& material, int pos) {
        FILE *pArchivo = fopen("materiales.dat", "rb+");
        if (pArchivo == NULL) return false;

        fseek(pArchivo, sizeof(Material) * pos, SEEK_SET);
        bool ok = fwrite(&material, sizeof(Material), 1, pArchivo);
        fclose(pArchivo);

    return ok;
}

    bool Archivos::modificarRegistroCliente(const Cliente cliente, int pos) {
        FILE *pArchivo = fopen("cliente.dat", "rb+");
        if (pArchivo == NULL) return false;

        fseek(pArchivo, sizeof(Cliente) * pos, SEEK_SET);
        bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);

    return ok;
    }

  //listar caballos por cliente

  void Archivos::listarCaballosPorCliente(int idCliente) {
    FILE *pArchivo = fopen("caballos.dat", "rb");
    if (pArchivo == NULL) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Caballo aux;
    bool hay = false;

    while (fread(&aux, sizeof(Caballo), 1, pArchivo)) {
        if (aux.getIDCliente() == idCliente) {
            aux.mostrar();
            cout << "---------------------\n";
            hay = true;
        }
    }

    fclose(pArchivo);

    if (!hay) {
        cout << "No se encontraron caballos para ese cliente.\n";
    }
}

// agrego  1
int Archivos::obtenerUltimoIDCaballo() {
    FILE* p = fopen("caballos.dat", "rb");
    if (p == nullptr) return 0;

    Caballo c;
    int maxID = 0;

    while (fread(&c, sizeof(Caballo), 1, p) == 1) {
        if (c.getID() > maxID) {
            maxID = c.getID();
        }
    }

    fclose(p);
    return maxID;
}
 // agrego 2
void Archivos::listarTodosLosCaballos() {
    FILE* pArchivo = fopen("caballos.dat", "rb");
    if (pArchivo == NULL) {
        cout << "No se pudo abrir el archivo caballos.dat\n";
        return;
    }

    Caballo aux;

    cout << "=== LISTA COMPLETA DE CABALLOS ===\n\n";

    while (fread(&aux, sizeof(Caballo), 1, pArchivo) == 1) {
        aux.mostrar();
        cout << "\n-----------------------------\n";
    }

    fclose(pArchivo);
}

void Archivos::listarTodosLosClientes() {
    FILE* pArchivo = fopen("cliente.dat", "rb");
    if (pArchivo == NULL) {
        cout << "No se pudo abrir el archivo cliente.dat\n";
        return;
    }

    Cliente aux;

    cout << "=== LISTA COMPLETA DE CLIENTES ===\n\n";

    while (fread(&aux, sizeof(Cliente), 1, pArchivo) == 1) {
        aux.mostrar();
        cout << "\n-----------------------------\n";
    }

    fclose(pArchivo);
}
