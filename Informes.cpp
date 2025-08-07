#include "Informes.h"
#include <iostream>

Informes::Informes() {
    // Constructor
    std::cout << "Constructor de la clase Informes llamado." << std::endl;
}

Informes::~Informes() {
    // Destructor
    std::cout << "Destructor de la clase Informes llamado." << std::endl;
}

int Informes::contarProductosSinStock() {
    archivoProducto archiP;
    int cantidadSinStock = 0;
    int cantidadRegistros = archiP.cantidadRegistros();
    Producto reg;

    for (int i = 0; i < cantidadRegistros; i++) {
        reg = archiP.leerRegistrosID(i);

        // Verifica si el producto está activo y su stock es 0
        if (reg.getEstado() == true && reg.getStock() == 0) {
            cantidadSinStock++;
        }
    }
    return cantidadSinStock;
}



/// uso de contar productos sin stock

/*int main() {
    Informes informe;
    int cantidadSinStock = informe.contarProductosSinStock();
    std::cout << "Cantidad de productos con stock = 0: " << cantidadSinStock << std::endl;
    return 0;
}*/
