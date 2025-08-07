#include "ArchivoProveedores.h"
#include <iostream>
#include <fstream>

using namespace std;

bool ArchivoProveedores::guardarProveedor(const Proveedor& proveedor) {
    ofstream archivo(nombreArchivo, std::ios::binary | std::ios::app);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo para guardar." << endl;
        return false;
    }
    archivo.write(reinterpret_cast<const char*>(&proveedor), sizeof(Proveedor));
    archivo.close();
    return true;
}

void ArchivoProveedores::listarProveedores() {
    ifstream archivo(nombreArchivo, std::ios::binary);
    Proveedor proveedor;

    if (archivo.is_open()) {
        while (archivo.read(reinterpret_cast<char*>(&proveedor), sizeof(Proveedor))) {
            proveedor.Mostrar(); // Asumiendo que Mostrar() está implementado en Proveedor
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

Proveedor ArchivoProveedores::leerProveedor(int id) {
    ifstream archivo(nombreArchivo, std::ios::binary);
    Proveedor proveedor;

    if (archivo.is_open()) {
        while (archivo.read(reinterpret_cast<char*>(&proveedor), sizeof(Proveedor))) {
            if (proveedor.getID() == id) {
                archivo.close();
                return proveedor;
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return proveedor; // Retorna un objeto vacío si no lo encuentra
}

bool ArchivoProveedores::modificarProveedor(int id, const Proveedor& proveedor) {
    ofstream archivoTemp("temp.dat", std::ios::binary);
    ifstream archivo(nombreArchivo, std::ios::binary);
    Proveedor proveedorTemp;

    if (archivo.is_open() && archivoTemp.is_open()) {
        while (archivo.read(reinterpret_cast<char*>(&proveedorTemp), sizeof(Proveedor))) {
            if (proveedorTemp.getID() == id) {
                archivoTemp.write(reinterpret_cast<const char*>(&proveedor), sizeof(Proveedor));
            } else {
                archivoTemp.write(reinterpret_cast<const char*>(&proveedorTemp), sizeof(Proveedor));
            }
        }
        archivo.close();
        archivoTemp.close();

        remove(nombreArchivo); // Eliminar archivo original
        rename("temp.dat", nombreArchivo); // Renombrar archivo temporal
        return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return false;
}

bool ArchivoProveedores::eliminarProveedor(int id) {
    ifstream archivo(nombreArchivo, std::ios::binary);
    ofstream tempArchivo("temp.dat", std::ios::binary);
    Proveedor proveedor;

    if (archivo.is_open() && tempArchivo.is_open()) {
        while (archivo.read(reinterpret_cast<char*>(&proveedor), sizeof(Proveedor))) {
            if (proveedor.getID() != id) {
                tempArchivo.write(reinterpret_cast<const char*>(&proveedor), sizeof(Proveedor));
            }
        }
        archivo.close();
        tempArchivo.close();

        remove(nombreArchivo); // Eliminar archivo original
        rename("temp.dat", nombreArchivo); // Renombrar archivo temporal

        return true;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
    return false;
}
