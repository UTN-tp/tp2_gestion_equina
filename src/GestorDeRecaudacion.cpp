#include <iostream>
#include "Archivos.h"
#include "Cliente.h"
#include "Material.h"
#include "Agenda.h"
#include "Caballo.h"
#include "MaterialesUsados.h"
#include "Usuario.h"
#include "Trabajo.h"
#include "InputManager.h"
#include "GestorDeRecaudacion.h"
using namespace std;


void GestorDeRecaudacion::calcularRecaudacionAnualPorMes() {
        Archivos a;

        int cantidad = a.cantidadRegistrosTrabajo();

        int anio = InputManager::leerInt("Ingrese el anio para calcular la recaudacion: ");


        float totalMes[12] = {0};

        for (int i = 0; i < cantidad; i++) {
            Trabajo t = a.leerRegistroTrabajo(i);
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int mes = f.getMes();
                if (mes >= 1 && mes <= 12) {
                    totalMes[mes - 1] += t.getCosto();
                }
            }
        }

        cout << "Recaudacion del anio " << anio << " por mes:" << endl;
        for (int i = 0; i < 12; i++) {
            cout << "Mes " << (i + 1) << ": $" << totalMes[i] << endl;
        }
    }

void GestorDeRecaudacion::calcularRecaudacionPorCliente() {

    Archivos a;
        int cantidadTrabajos = a.cantidadRegistrosTrabajo();
        int cantidadClientes = a.cantidadRegistrosCliente();

        int anio = InputManager::leerInt("Ingrese el anio para calcular la recaudacion: ");

        // Array de clientes
        Cliente* clientes = new Cliente[cantidadClientes];
        for (int i = 0; i < cantidadClientes; i++) {
            clientes[i] = a.leerRegistroCliente(i);
        }

        // Array paralelo para acumular recaudacion
        float* recaudacion = new float[cantidadClientes];
        for (int i = 0; i < cantidadClientes; i++) {
            recaudacion[i] = 0;
        }

        // Recorremos los trabajos y acumulamos montos por cliente
        for (int i = 0; i < cantidadTrabajos; i++) {
            Trabajo t = a.leerRegistroTrabajo(i);
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int idCliente = t.getIdCliente();
                // Buscamos la posici¢n del cliente en el array
                for (int j = 0; j < cantidadClientes; j++) {
                    if (clientes[j].getID() == idCliente) {
                        recaudacion[j] += t.getCosto();
                        break;
                    }
                }
            }
        }

        // Mostramos resultados
        cout << "Recaudacion por cliente en el anio " << anio << ":\n";
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


    //CONSUMO MATERIALES

    void GestorDeRecaudacion::consumoMaterialesPorAnio() {

        Archivos archivos;

        int cantidadMU = archivos.cantidadRegistrosMaterialesUsados();
        int cantidadMateriales = archivos.cantidadRegistrosMaterial();

        int anio = InputManager::leerInt("Ingrese el anio para calcular de materiales: ");


        // Array de materiales
        Material* materiales = new Material[cantidadMateriales];
        for (int i = 0; i < cantidadMateriales; i++) {
            materiales[i] = archivos.leerRegistroMaterial(i);
        }

        // Array paralelo para acumular consumo
        int* consumo = new int[cantidadMateriales];
        for (int i = 0; i < cantidadMateriales; i++) {
            consumo[i] = 0;
        }

        // Recorremos los materiales usados
        for (int i = 0; i < cantidadMU; i++) {
            MaterialesUsados mu = archivos.leerRegistroMaterialesUsados(i);
            Trabajo t = archivos.leerRegistroTrabajo(mu.getIDTrabajo());
            Fecha f = t.getFecha();

            if (f.getAnio() == anio) {
                int idMaterial = mu.getIDMaterial();
                // Buscamos la posici¢n del material en el array
                for (int j = 0; j < cantidadMateriales; j++) {
                    if (materiales[j].getID() == idMaterial) {
                        consumo[j] += mu.getCantidad();
                        break;
                    }
                }
            }
        }

        // Mostramos resultados
        cout << "Consumo de materiales en el anio " << anio << ":\n";
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
