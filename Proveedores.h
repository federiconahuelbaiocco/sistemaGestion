#ifndef PROVEEDORES_H
#define PROVEEDORES_H

#include "Persona.h"

class Proveedores {
private:
    Proveedor listaProveedores[100];  // Lista de proveedores
    int cantidad;  // N�mero de proveedores registrados

public:
    Proveedores();  // Constructor

    // M�todos
    void agregarProveedor(const Proveedor& proveedor);
    Proveedor* buscarProveedorPorID(int id);
    void listarProveedores();
};

#endif // PROVEEDORES_H
