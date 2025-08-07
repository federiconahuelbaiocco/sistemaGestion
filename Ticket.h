#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include "Persona.h"
#include "Fecha.h"
#include "ProductoTicket.h"

class Ticket{
private:
    ProductoTicket* productos;
    int cantidadProductos;
    float precioAcumulado;
    Empleado* empleado;
    Fecha fechaEmision;
    bool anulado;
public:

    Ticket();
    void addProducto(Producto producto, int cantidad);
    void setCantidadProductos(int cantidad);
    void setPrecioAcumulado(float precioAcumulado);
    void setAnulado(bool estado);
    void setEmpleado(Empleado* empleado);

    ProductoTicket* getProducto();
    ProductoTicket getProducto(int index);
    int getCantidad();
    float getPrecio();
    Fecha getFecha();
    Empleado* getEmpleado();
    bool estaAnulado();
};


#endif // TICKET_H_INCLUDED
