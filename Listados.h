#ifndef LISTADOS_H
#define LISTADOS_H

#include "Producto.h"
#include "Persona.h"
void ordenar(Producto *p, int tam,int opcion);
void ordenarProveedores(Proveedor *p, int tam, int opcion);

class Listados
{
    public:
        void ordenGeneralProductos(int opcion);
        void ordenadoNombre();
        void ordenadoMarca();
        void ordenadoProveedor();
        void ordenadoPrecio();
        void ordenadoStock();

        void ordenGeneralProveedor(int opcion);
        void ordenadoNombreProveedor();
        void ordenadoCantidad();

    protected:

    private:
};
#endif // LISTADOS_H
