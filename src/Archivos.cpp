#include "Archivos.h"
#include "Cliente.h"
#include "Material.h"
#include "Agenda.h"
#include "Caballo.h"
#include "MaterialesUsados.h"
#include "Usuario.h"
#include "Trabajo.h"

using namespace std;

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

    bool Archivos::guardarArchivoUsuario(const Usuario& usuario) {
        FILE* pArchivo = fopen("usuarios.dat", "ab");
        if (pArchivo == nullptr) {
            perror("Error al abrir el archivo usuario.dat");
            return false;
        }

        size_t escritos = fwrite(&usuario, sizeof(Usuario), 1, pArchivo);
        fclose(pArchivo);

        return escritos == 1;
    }

    bool Archivos::guardarArchivoAgenda(Agenda agenda){
        FILE *pArchivo = fopen("agendas.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&agenda, sizeof(Agenda), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoMaterial(Material& material){
        FILE* p = fopen("materiales.dat", "ab");
        if (p == nullptr) {
            cout << "Error al abrir el archivo materiales.dat\n";
            return false;
        }

        bool ok = fwrite(&material, sizeof(Material), 1, p);
        fclose(p);
        return ok;
    }

    bool Archivos::guardarArchivoMaterialesUsados (MaterialesUsados &materialesUsados){
        FILE *pArchivo = fopen("materialesusados.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&materialesUsados, sizeof(MaterialesUsados), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }

    bool Archivos::guardarArchivoCliente(const Cliente& cliente) {
        FILE* pArchivo = fopen("clientes.dat", "ab");
        if (pArchivo == nullptr) {
            perror("Error al abrir el archivo cliente.dat");
            return false;
        }

        size_t escritos = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);

        return escritos == 1;
    }

    bool Archivos::guardarArchivoTrabajo(Trabajo& trabajo){
        FILE *pArchivo = fopen("trabajos.dat", "ab");
        if(pArchivo == NULL){

            return false;
        }

        bool ok = fwrite(&trabajo, sizeof(Trabajo), 1, pArchivo);
        fclose(pArchivo);

        return ok;
    }


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
        FILE *pArchivo = fopen("agendas.dat", "rb");
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
        FILE *pArchivo = fopen("clientes.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosTrabajo(){
        FILE *pArchivo = fopen("trabajos.dat", "rb");
        if(pArchivo == NULL){

            return 0;
        }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Trabajo);
        fclose(pArchivo);

        return cantidadRegistros;
    }

    int Archivos::cantidadRegistrosUsuario(){
        FILE *pArchivo = fopen("usuarios.dat", "rb");
        if(pArchivo == NULL){

            return 0;
     }

        fseek(pArchivo, 0, SEEK_END);
        int cantidadRegistros = ftell(pArchivo) / sizeof(Usuario);
        fclose(pArchivo);

        return cantidadRegistros;
    }


    Caballo Archivos::leerRegistroCaballo(int pos){
        FILE *pArchivo = fopen("caballos.dat", "rb");

        Caballo caballo;

        if(pArchivo == NULL){
            return caballo;
        }
        fseek(pArchivo, sizeof(Caballo) * pos, SEEK_SET);
        fread(&caballo, sizeof(Caballo), 1, pArchivo);
        fclose(pArchivo);
        return caballo;
    }

    Agenda Archivos::leerRegistroAgenda(int pos){
        FILE *pArchivo = fopen("agendas.dat", "rb");

        Agenda agenda;
        if(pArchivo == NULL){
            return agenda;
        }

        fseek(pArchivo, sizeof(Agenda) * pos, SEEK_SET);
        fread(&agenda, sizeof(Agenda), 1, pArchivo);
        fclose(pArchivo);
        return agenda;

    }

    Material Archivos::leerRegistroMaterial(int pos){
        Material material;
        FILE* p = fopen("materiales.dat", "rb");
        if (p == nullptr) return material;
        fseek(p, pos * sizeof(Material), SEEK_SET);
        fread(&material, sizeof(Material), 1, p);
        fclose(p);
        return material;
    }

    MaterialesUsados Archivos::leerRegistroMaterialesUsados(int pos){
        FILE *pArchivo = fopen("materiales_usados.dat", "rb");
        MaterialesUsados materialesUsados;

        if(pArchivo == NULL){
            return materialesUsados;
        }

        fseek(pArchivo, sizeof(MaterialesUsados) * pos, SEEK_SET);
        fread(&materialesUsados, sizeof(MaterialesUsados), 1, pArchivo);
        fclose(pArchivo);
        return materialesUsados;
    }

    Cliente Archivos::leerRegistroCliente(int pos){
        FILE *pArchivo = fopen("clientes.dat", "rb");
        Cliente cliente;
        if(pArchivo == NULL){
            return cliente;
        }

        fseek(pArchivo, sizeof(Cliente) * pos, SEEK_SET);
        fread(&cliente, sizeof(Cliente), 1, pArchivo);
        fclose(pArchivo);
        return cliente;
    }

    Trabajo Archivos::leerRegistroTrabajo(int pos){
        FILE *pArchivo = fopen("trabajos.dat", "rb");
        Trabajo trabajo;
        if(pArchivo == NULL){
            return trabajo;
        }
        fseek(pArchivo, sizeof(Trabajo) * pos, SEEK_SET);
        fread(&trabajo, sizeof(Trabajo), 1, pArchivo);
        fclose(pArchivo);
        return trabajo;
    }

    Usuario Archivos::leerRegistroUsuario(int pos){
        FILE *pArchivo = fopen("usuarios.dat", "rb");
        Usuario usuario;
        if(pArchivo == NULL){
            return usuario;
        }

        fseek(pArchivo, sizeof(Usuario) * pos, SEEK_SET);
        fread(&usuario, sizeof(Usuario), 1, pArchivo);
        fclose(pArchivo);
        return usuario;
    }

    // buscar por ID

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

  //modificar registro

  bool Archivos::modificarRegistroCaballo(const Caballo& caballo, int pos) {
    FILE *pArchivo = fopen("caballos.dat", "rb+");
    if (pArchivo == NULL) return false;

    fseek(pArchivo, sizeof(Caballo) * pos, SEEK_SET);
    bool ok = fwrite(&caballo, sizeof(Caballo), 1, pArchivo);
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




int Archivos::buscarMaterialPorID(int id) {
        Material material;
        FILE *pArchivo = fopen("materiales.dat", "rb");
        if (pArchivo == NULL) return -1;

        int pos = 0;
        while (fread(&material, sizeof(Material), 1, pArchivo)) {
            if (material.getID() == id && material.getEstado()) {
                fclose(pArchivo);
                return pos;
            }
            pos++;
        }

        fclose(pArchivo);
        return -1;
    }

bool Archivos::modificarRegistroMaterial(Material& material, int pos) {
        FILE *pArchivo = fopen("materiales.dat", "rb+");
        if (pArchivo == NULL) return false;

        fseek(pArchivo, sizeof(Material) * pos, SEEK_SET);
        bool ok = fwrite(&material, sizeof(Material), 1, pArchivo);
        fclose(pArchivo);
        return ok;
    }

void Archivos::calcularRecaudacionAnualPorMes() {
        int cantidad = cantidadRegistrosTrabajo();

        int anio;
        cout << "Ingrese el año para calcular la recaudacion: ";
        cin >> anio;


        float totalMes[12] = {0};

        for (int i = 0; i < cantidad; i++) {
            Trabajo t = leerRegistroTrabajo(i);
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int mes = f.getMes();
                if (mes >= 1 && mes <= 12) {
                    totalMes[mes - 1] += t.getMonto();
                }
            }
        }

        cout << "Recaudacion del año " << anio << " por mes:" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "Mes " << (i + 1) << ": $" << totalMes[i] << endl;
        }
    }

void Archivos::calcularRecaudacionPorCliente() {
        int cantidadTrabajos = cantidadRegistrosTrabajo();
        int cantidadClientes = cantidadRegistrosCliente();

        int anio;
        cout << "Ingrese el año para calcular la recaudacion por cliente: ";
        cin >> anio;

        // Array de clientes
        Cliente* clientes = new Cliente[cantidadClientes];
        for (int i = 0; i < cantidadClientes; i++) {
            clientes[i] = leerRegistroCliente(i);
        }

        // Array paralelo para acumular recaudacion
        float* recaudacion = new float[cantidadClientes];
        for (int i = 0; i < cantidadClientes; i++) {
            recaudacion[i] = 0;
        }

        // Recorremos los trabajos y acumulamos montos por cliente
        for (int i = 0; i < cantidadTrabajos; i++) {
            Trabajo t = leerRegistroTrabajo(i);
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int idCliente = t.getIdCliente();
                // Buscamos la posición del cliente en el array
                for (int j = 0; j < cantidadClientes; j++) {
                    if (clientes[j].getID() == idCliente) {
                        recaudacion[j] += t.getMonto();
                        break;
                    }
                }
            }
        }

        // Mostramos resultados
        cout << "Recaudacion por cliente en el año " << anio << ":\n";
        cout << "ID Cliente\tNombre\t\tTotal recaudado\n";
        cout << "-----------------------------------------\n";

        for (int i = 0; i < cantidadClientes; i++) {
            if (recaudacion[i] > 0) {
                cout << clientes[i].getID() << "\t\t"
                     << clientes[i].getNombre() << "\t\t$"
                     << recaudacion[i] << endl;
            }
        }

        delete[] clientes;
        delete[] recaudacion;
    }

void Archivos::consumoMaterialesPorAno() {
        int cantidadMU = cantidadRegistrosMaterialesUsados();
        int cantidadMateriales = cantidadRegistrosMaterial();

        int anio;
        cout << "Ingrese el año para calcular el consumo de materiales: ";
        cin >> anio;

        // Array de materiales
        Material* materiales = new Material[cantidadMateriales];
        for (int i = 0; i < cantidadMateriales; i++) {
            materiales[i] = leerRegistroMaterial(i);
        }

        // Array paralelo para acumular consumo
        int* consumo = new int[cantidadMateriales];
        for (int i = 0; i < cantidadMateriales; i++) {
            consumo[i] = 0;
        }

        // Recorremos los materiales usados
        for (int i = 0; i < cantidadMU; i++) {
            MaterialesUsados mu = leerRegistroMaterialesUsados(i);
            Trabajo t = leerRegistroTrabajo(mu.getIDTrabajo());
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int idMaterial = mu.getIDMaterial();
                // Buscamos la posición del material en el array
                for (int j = 0; j < cantidadMateriales; j++) {
                    if (materiales[j].getID() == idMaterial) {
                        consumo[j] += mu.getCantidad();
                        break;
                    }
                }
            }
        }

        // Mostramos resultados
        cout << "Consumo de materiales en el año " << anio << ":\n";
        cout << "ID\tNombre\t\tTipo\t\tCantidad consumida\n";
        cout << "-----------------------------------------------------\n";

        for (int i = 0; i < cantidadMateriales; i++) {
            if (consumo[i] > 0) {
                cout << materiales[i].getID() << "\t"
                     << materiales[i].getNombre() << "\t\t"
                     << materiales[i].getTipo() << "\t\t"
                     << consumo[i] << endl;
            }
        }

        delete[] materiales;
        delete[] consumo;
    }




