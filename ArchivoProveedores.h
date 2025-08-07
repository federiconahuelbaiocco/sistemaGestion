#ifndef ARCHIVOPROVEEDORES_H
#define ARCHIVOPROVEEDORES_H

#include "Proveedores.h"
#include <fstream>
#include "Persona.h"

class ArchivoProveedores {
private:
    const char* nombreArchivo = "proveedores.dat"; // Nombre del archivo de proveedores

public:
    bool guardarProveedor(const Proveedor& proveedor);
    void listarProveedores();
    Proveedor leerProveedor(int id);
    bool modificarProveedor(int id, const Proveedor& proveedor);
    bool eliminarProveedor(int id);
};

#endif // ARCHIVOPROVEEDORES_H
