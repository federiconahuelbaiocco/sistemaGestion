#ifndef ARCHIVOPROVEEDOR_H_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED

#include "Persona.h"

class archivoProveedor
{
    public:
        archivoProveedor(const char *n="proveedor.dat",int tamanioRegistro =sizeof(Proveedor));
        ~archivoProveedor();
        bool GrabarRegistro(Proveedor &reg);
        bool ListarRegistros();
        int cantidadRegistros();
        Proveedor leerRegistrosID(int posReg);
        int buscarRegistro(int id, bool queHago);
        bool modificarRegistro(Proveedor reg,int pos);
        bool bajaRegistro();
        bool altaRegistro();
        bool modificacionRegistro();

    protected:

    private:
        char nombreArchivo[20];
        int tamanioRegistro;
};

#endif // ARCHIVOPROVEEDOR_H_INCLUDED
