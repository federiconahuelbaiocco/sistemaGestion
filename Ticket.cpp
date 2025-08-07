#include<iostream>

#include "Ticket.h"

using namespace std;


Ticket::Ticket(){
    Ticket::productos = new ProductoTicket[30];
}

void Ticket::setCantidadProductos(int cantidad){Ticket::cantidadProductos = cantidad;}
void Ticket::setPrecioAcumulado(float precio){Ticket::precioAcumulado = precio;}
void Ticket::addProducto(Producto producto, int cantidad){
    for(int i = 0; i < sizeof(Ticket::productos); i++){
        if(Ticket::productos[i].getCantidad() == 0){
            Ticket::productos[i].setProducto(&producto);
            Ticket::productos[i].modificarCantidad(cantidad);
        }
    }
}
void Ticket::setEmpleado(Empleado* empleado){Ticket::empleado = empleado;}
void Ticket::setAnulado(bool estado){Ticket::anulado = estado;}
bool Ticket::estaAnulado(){return Ticket::anulado;}
int Ticket::getCantidad(){return Ticket::cantidadProductos;}
Empleado* Ticket::getEmpleado(){return empleado;}
ProductoTicket Ticket::getProducto(int index){return productos[index];}

