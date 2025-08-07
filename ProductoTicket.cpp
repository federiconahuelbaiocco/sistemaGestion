#include<iostream>

#include "ProductoTicket.h"
#include <cstring>

using namespace std;

void ProductoTicket::setProducto(Producto* producto){ProductoTicket::producto = producto;}
void ProductoTicket::setCantidad(int cantidad){
    ProductoTicket::cantidad = cantidad;
}
void ProductoTicket::setPrecioTotal(float precio){
    ProductoTicket::precioTotal = precio;
}
int ProductoTicket::getCantidad(){return ProductoTicket::cantidad;}
float ProductoTicket::getPrecioTotal(){return ProductoTicket::precioTotal;}
Producto* ProductoTicket::getProducto(){return ProductoTicket::producto;}

void ProductoTicket::modificarCantidad(int cantidad){
    if(ProductoTicket::cantidad + cantidad <= 0){
        ProductoTicket::cantidad = 0;
    }else{
        ProductoTicket::cantidad += cantidad;
    }
    ProductoTicket::precioTotal = (float) (ProductoTicket::producto->getPrecioVenta() * ProductoTicket::cantidad);
}

void ProductoTicket::imprimir(int index){
        int tamanio = strlen(producto->getName());
        char line[62] = {};
        line[0] = '|';line[1] = ' ';line[2] = (char)((index+1) + '0');line[3] = ' ';line[4] = '-';line[5] = ' ';
        strncpy(&line[6], producto->getName(), tamanio);
        for(int j = 6+tamanio; j < 61; j++){line[j] = ' ';}
        sprintf(&line[38], "%.2f", producto->getPrecioVenta());
        line[48] = 'x';
        sprintf(&line[49], "%.2f", cantidad);
        sprintf(&line[53], "%.2f", producto->getPrecioVenta() * cantidad);
        line[61] = '|';
        std::cout << line << std::endl;
}
