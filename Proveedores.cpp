#include "Proveedores.h"
#include <iostream>
#include "ArchivoProveedores.h"

Proveedores::Proveedores() : cantidad(0) {}

void Proveedores::agregarProveedor(const Proveedor& proveedor) {
    if (cantidad < 100) {
        listaProveedores[cantidad++] = proveedor;  // Agregar proveedor
    } else {
        std::cout << "No se pueden agregar más proveedores. Limite alcanzado." << std::endl;
    }
}

Proveedor* Proveedores::buscarProveedorPorID(int id) {
    for (int i = 0; i < cantidad; ++i) {
        if (listaProveedores[i].getID() == id) {
            return &listaProveedores[i];  // Retornar el proveedor por ID
        }
    }
    return nullptr;  // Si no se encuentra, retornar nullptr
}

void Proveedores::listarProveedores() {
    if (cantidad == 0) {
        std::cout << "No hay proveedores registrados." << std::endl;
        return;
    }
    for (int i = 0; i < cantidad; ++i) {
        listaProveedores[i].Mostrar();  // Mostrar los datos del proveedor
        std::cout << "----------------------" << std::endl;
    }
}

