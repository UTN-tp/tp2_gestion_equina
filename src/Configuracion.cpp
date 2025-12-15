#include "Configuracion.h"
#include "Caballo.h"

/// --- EXPORTAR ---
bool Configuracion::exportarDatos()
{
    string archivos[] = {
        "cliente.dat",
        //"usuario.dat",
        "materiales.dat",
        "materiales_usados.dat",
        "caballos.dat"

    };
    bool ok = true;

    for (const string& nombre : archivos)
    {
        string destino = nombre + ".bak";

        FILE* origen = fopen(nombre.c_str(), "rb");
        if (origen == nullptr)
        {
            cout << "No se encontro el archivo: " << nombre << endl;
            ok = false;
            continue;
        }

        FILE* copia = fopen(destino.c_str(), "wb");
        if (copia == nullptr)
        {
            cout << "No se pudo crear el archivo de respaldo: " << destino << endl;
            fclose(origen);
            ok = false;
            continue;
        }

        char buffer[1024];
        size_t bytes;
        while ((bytes = fread(buffer, 1, sizeof(buffer), origen)) > 0)
        {
            fwrite(buffer, 1, bytes, copia);
        }

        fclose(origen);
        fclose(copia);
        cout << "Exportado correctamente: " << destino << endl;
    }

    return ok;
}

/// --- IMPORTAR ---
bool Configuracion::importarDatos()
{
    string archivos[] = {
        "cliente.dat",
        //"usuario.dat",
        "materiales.dat",
        "materiales_usados.dat",
        "caballos.dat"

    };
    bool ok = true;

    for (const string& nombre : archivos)
    {
        string respaldo = nombre + ".bak";

        FILE* origen = fopen(respaldo.c_str(), "rb");
        if (origen == nullptr)
        {
            cout << "No se encontró respaldo: " << respaldo << endl;
            ok = false;
            continue;
        }

        FILE* destino = fopen(nombre.c_str(), "wb");
        if (destino == nullptr)
        {
            cout << "No se pudo restaurar archivo: " << nombre << endl;
            fclose(origen);
            ok = false;
            continue;
        }

        char buffer[1024];
        size_t bytes;
        while ((bytes = fread(buffer, 1, sizeof(buffer), origen)) > 0)
        {
            fwrite(buffer, 1, bytes, destino);
        }

        fclose(origen);
        fclose(destino);
        cout << "Importado correctamente: " << nombre << endl;
    }

    return ok;
}

/// --- GENERAR CSV ---
bool Configuracion::generarCSV(const string& nombreArchivoBinario, const string& nombreCSV)
{
    ifstream bin(nombreArchivoBinario, ios::binary);
    if (!bin)
    {
        cout << "No se pudo abrir el archivo binario: " << nombreArchivoBinario << endl;
        return false;
    }

    ofstream csv(nombreCSV);
    if (!csv)
    {
        cout << "No se pudo crear el archivo CSV: " << nombreCSV << endl;
        return false;
    }

    int tipoArchivo = -1;

    if (nombreArchivoBinario == "materiales.dat") tipoArchivo = 1;
    else if (nombreArchivoBinario == "cliente.dat") tipoArchivo = 2;
    else if (nombreArchivoBinario == "usuario.dat") tipoArchivo = 3;
    else if (nombreArchivoBinario == "caballos.dat") tipoArchivo = 4;
    else if (nombreArchivoBinario == "materiales_usados.dat") tipoArchivo = 5;
    else tipoArchivo = 0;

    switch (tipoArchivo)
    {
    case 1:
        {
            csv << "ID,Nombre,Tipo,Stock,Precio,Estado\n";
            Material m;
            while (bin.read(reinterpret_cast<char*>(&m), sizeof(Material)))
            {
                csv << m.getID() << ","
                    << m.getNombre() << ","
                    << m.getTipo() << ","
                    << m.getStock() << ","
                    << m.getPrecio() << ","
                    << (m.getEstado() ? "Activo" : "Inactivo") << "\n";
            }
            break;
        }
    case 2:
        {
            csv << "ID,Nombre,Apellido,Direccion,CantidadCaballos,Estado\n";
            Cliente c;
            while (bin.read(reinterpret_cast<char*>(&c), sizeof(Cliente)))
            {
                csv << c.getID() << ","
                    << c.getNombre() << ","
                    << c.getApellido() << ","
                    << c.getDireccion() << ","
                    << c.getCantidadCaballos() << ","
                    << (c.getEstado() ? "Activo" : "Inactivo") << "\n";
            }
            break;
        }
    case 3:
        {
            csv << "ID,Nombre,Apellido,Email,Estado\n";
            Usuario u;
            while (bin.read(reinterpret_cast<char*>(&u), sizeof(Usuario)))
            {
                csv << u.getID() << ","
                    << u.getNombre() << ","
                    << u.getApellido() << ","
                    << u.getEmail() << ","
                    << (u.getEstado() ? "Activo" : "Inactivo") << "\n";
            }
            break;
        }
    case 4:
        {
            csv << "ID,Nombre,Raza,Edad,IDCliente,Estado\n";
            Caballo c;
            while (bin.read(reinterpret_cast<char*>(&c), sizeof(Caballo)))
            {
                csv << c.getID() << ","
                    << c.getNombre() << ","
                    << c.getRaza() << ","
                    << c.getEdad() << ","
                    << c.getIDCliente() << ","
                    << (c.getEstado() ? "Activo" : "Inactivo") << "\n";
            }
            break;
        }
    case 5:
        {
            csv << "IDMaterialUsado,IDTrabajo,IDMaterial,Cantidad\n";
            MaterialesUsados mu;
            while (bin.read(reinterpret_cast<char*>(&mu), sizeof(MaterialesUsados)))
            {
                csv << mu.getIDMaterialUsado() << ","
                    << mu.getIDTrabajo() << ","
                    << mu.getIDMaterial() << ","
                    << mu.getCantidad() << "\n";
            }
            break;
        }
    default:
        cout << "Tipo de archivo no reconocido: " << nombreArchivoBinario << endl;
        return false;
    }

    cout << "Archivo CSV generado correctamente: " << nombreCSV << endl;
    return true;
}
