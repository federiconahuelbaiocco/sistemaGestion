#ifndef PROVEEDORES_H
#define PROVEEDORES_H

#include "Persona.h"

class Proveedores {
private:
    Proveedor listaProveedores[100];  // Lista de proveedores
    int cantidad;  // Número de proveedores registrados

public:
    Proveedores();  // Constructor

    // Métodos
    void agregarProveedor(const Proveedor& proveedor);
    Proveedor* buscarProveedorPorID(int id);
    void listarProveedores();
};

#endif // PROVEEDORES_H
