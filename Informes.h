#ifndef INFORMES_H
#define INFORMES_H

#include "archivoProducto.h"  // Asegúrate de incluir la clase archivoProducto y Producto

class Informes {
public:
    Informes();                // Constructor
    ~Informes();               // Destructor
    int contarProductosSinStock();
};

#endif // INFORMES_H
