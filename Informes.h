#ifndef INFORMES_H
#define INFORMES_H

#include "archivoProducto.h"  // Aseg�rate de incluir la clase archivoProducto y Producto

class Informes {
public:
    Informes();                // Constructor
    ~Informes();               // Destructor
    int contarProductosSinStock();
};

#endif // INFORMES_H
