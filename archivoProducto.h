#ifndef ARCHIVOPRODUCTO_H
#define ARCHIVOPRODUCTO_H
#include "Producto.h"





class archivoProducto
{
    public:
        archivoProducto(const char *n="productos.dat",int tamanioRegistro =sizeof(Producto));
        ~archivoProducto();
        bool GrabarRegistro(Producto &reg);
        bool ListarRegistros();
        int cantidadRegistros();
        Producto leerRegistrosID(int posReg);
        int buscarRegistro(int id, bool queHago);
        bool modificarRegistro(Producto reg,int pos);
        bool bajaRegistro();
        bool altaRegistro();
        bool modificacionRegistro();

    protected:

    private:
        char nombreArchivo[20];
        int tamanioRegistro;
};

#endif // ARCHIVOPRODUCTO_H
