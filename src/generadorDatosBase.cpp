#include <iostream>
#include "Archivos.h"
#include "Material.h"
#include "generadorDatosBase.h"

using namespace std;

    void cargarDatosBase (){
        Archivos archivos;

        if(archivos.cantidadRegistrosMaterial()==0){


        //Carga Clavos


        Material m1;
        Archivos archivos;

        m1.setID(1);
        m1.setNombre("Clavos");
        m1.setTipo("Clavo");
        m1.setStock(0);
        m1.setPrecio(100);
        m1.setEstado(true);

        if (archivos.guardarArchivoMaterial(m1) == false ){
            cout << "No se pudo registrar el material inicial" << endl;
        }

        //Carga Herradura

        Material m2;
        m2.setID(2);
        m2.setNombre("Herradura");
        m2.setTipo("Herradura");
        m2.setTipo("Herradura");
        m2.setStock(0);
        m2.setPrecio(2800);
        m2.setEstado(true);

        if (archivos.guardarArchivoMaterial(m2) == false ){
            cout << "No se pudo registrar el material inicial" << endl;
        }

        }


        }


