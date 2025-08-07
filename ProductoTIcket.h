#ifndef PRODUCTOTICKET_H_INCLUDED
#define PRODUCTOTICKET_H_INCLUDED

#include "Producto.h"

class ProductoTicket{
private:
    int cantidad;
    float precioTotal;
    Producto* producto;
public:

void setProducto(Producto* producto);
void setCantidad(int cantidad);
void setPrecioTotal(float precio);
int getCantidad();
float getPrecioTotal();
Producto* getProducto();

void modificarCantidad(int cantidad);

void imprimir(int index);


};

#endif // PRODUCTOTICKET_H_INCLUDED
