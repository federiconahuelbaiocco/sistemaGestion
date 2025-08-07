#include<iostream>
  #include<cstdlib>
  #include<cstring>
 using namespace std;

#include "Consultas.h"
#include "Producto.h"
#include "Persona.h"
#include "archivoProducto.h"
#include "archivoProveedor.h"


 void Consultas::busquedaIndividualID() {
    archivoProducto archiP;
    Producto reg;

    int id,cantidadRegistros;
    bool encontro=false;

    cantidadRegistros = archiP.cantidadRegistros();

    cout<<"INGRESE EL ID DEL PRODUCTO A BUSCAR"<<endl;
    cin>>id;

    for(int i = 0 ;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);
        if(reg.getEstado()==true && reg.getID()==id) {
            reg.mostrar();
            encontro=true;
        }
    }
    if(encontro==false) {
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    }
 }
 void Consultas::busquedaIndividualNombreyMarca() {
    archivoProducto archiP;
    Producto reg;

    char marca[20];
    char nombre[20];

    bool encontro=false;
    cin.ignore();


    cout<<"INGRESE EL NOMBRE DEL PRODUCTO QUE DESEA BUSCAR"<<endl;
    cin.getline(nombre,20);
    mayusculas(nombre);

    cout<<"INGRESE LA MARCA DEL PRODUCTO QUE DESEA BUSCAR"<<endl;
    cin.getline(marca,20);
    mayusculas(marca);


    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && strcmp(reg.getMarca(),marca)==0 && strcmp(reg.getName(),nombre)==0) {
                    encontro=true;

                reg.mostrar();
            }



        }
        if(encontro==false) {
        cout<<endl;
        cout<<"NO EXISTE REGISTRO CON ESA COMBINACION NOMBRE Y MARCA"<<endl;
    }
 }
void Consultas::listadoPorMarca() {
    archivoProducto archiP;
    Producto reg;

    char _marca[20];

    int cant=0;
    cin.ignore();

    cout<<"INGRESE LA MARCA QUE DESEA BUSCAR"<<endl;
    cin.getline(_marca,20);
    mayusculas(_marca);


    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && strcmp(reg.getMarca(),_marca)==0) {
                    cant++;

                reg.mostrar();
            }



        }
        if (cant ==0) {

            cout<<"NO HAY REGISTROS CON ESA MARCA"<<endl;
        }

}
void Consultas::listaPorProveedor() {
        archivoProducto archiP;
    Producto reg;

    char _proveedor[20];

    int cant=0;

    cin.ignore();

    cout<<"INGRESE EL PROVEEDOR QUE DESEA BUSCAR"<<endl;

    cin.getline(_proveedor,20);
    mayusculas(_proveedor);


    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && strcmp(reg.getProveedor(),_proveedor)==0) {
                cant++;
                reg.mostrar();
            }


        }
         if (cant ==0) {

            cout<<"NO HAY REGISTROS CON ESE PROVEEDOR"<<endl;
        }

}
void Consultas::listaRangoPrecio() {

    archivoProducto archiP;
    Producto reg;

    float precioMinimo;
    float precioMaximo;
    int cant = 0;

    cout<<"INGRESE PRECIO MINIMO PARA EL RANGO DE PRECIO"<<endl;
    precioMinimo = solicitarPrecio();
    cout<<"INGRESE PRECIO MAXIMO PARA EL RANGO DE PRECIO"<<endl;

    precioMaximo = solicitarPrecio();



        while(precioMinimo>precioMaximo) {
            cout<<"PRECIO MINIMO NO PUEDE SER MAYOR AL MAXIMO"<<endl;
             cout<<"INGRESE PRECIO MINIMO PARA EL RANGO DE PRECIO"<<endl;
            precioMinimo = solicitarPrecio();
            cout<<"INGRESE PRECIO MAXIMO PARA EL RANGO DE PRECIO"<<endl;
             precioMaximo = solicitarPrecio();
        }



    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && reg.getPrecioVenta() >= precioMinimo && reg.getPrecioVenta() <= precioMaximo ) {
                cant++;
                reg.mostrar();
            }


        }

         if (cant ==0) {

            cout<<"NO HAY REGISTROS CON ESE RANGO DE PRECIOS"<<endl;
        }
}
void Consultas::listaRangoStock() {

    archivoProducto archiP;
    Producto reg;

    int stockMinimo;
    int stockMaximo;
    int cant=0;

    cout<<"INGRESE VALOR MINIMO PARA EL RANGO DE STOCK"<<endl;
    stockMinimo = solicitarStock();
    cout<<"INGRESE VALOR MAXIMO PARA EL RANGO DE STOCK"<<endl;

    stockMaximo = solicitarStock();


      while(stockMinimo>stockMaximo) {
            cout<<"STOCK MINIMO NO PUEDE SER MAYOR AL MAXIMO"<<endl;
             cout<<"INGRESE STOCK MINIMO PARA EL RANGO DE STOCK"<<endl;
            stockMinimo = solicitarPrecio();
            cout<<"INGRESE STOCK MAXIMO PARA EL RANGO DE STOCK"<<endl;
             stockMaximo = solicitarPrecio();
        }


    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && reg.getStock() >= stockMinimo && reg.getStock() <=stockMaximo ) {
                cant++;
                reg.mostrar();
            }


        }
        if(cant==0) {
            cout<<"NO HAY REGISTROS EN ESE RANGO DE STOCK"<<endl;

        }

}


//////////////////////////////////////////////

void Consultas::busquedaIndividualIDProveedor() {
    archivoProveedor archiP;
    Proveedor reg;

    int id,cantidadRegistros;
    bool encontro=false;

    cantidadRegistros = archiP.cantidadRegistros();

    cout<<"INGRESE EL ID DEL PRODUCTO A BUSCAR"<<endl;
    cin>>id;

    for(int i = 0 ;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);
        if(reg.getEstado()==true && reg.getID()==id) {
            reg.mostrar();
            encontro=true;
        }
    }
    if(encontro==false) {
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    }
 }

 void Consultas::busquedaIndividualNombre() {
    archivoProveedor archiP;
    Proveedor reg;

    char nombre[20];

    bool encontro=false;
    cin.ignore();


    cout<<"INGRESE EL NOMBRE DEL PROVEEDOR QUE DESEA BUSCAR"<<endl;
    cin.getline(nombre,20);
    mayusculas(nombre);


    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && strcmp(reg.getNombre(),nombre)==0) {
                    encontro=true;

                reg.mostrar();
            }



        }
        if(encontro==false) {
        cout<<endl;
        cout<<"NO EXISTE REGISTRO CON ESE NOMBRE"<<endl;
    }
 }

void Consultas::listaRangoProductos() {

    archivoProveedor archiP;
    Proveedor reg;

    float precioMinimo;
    float precioMaximo;
    int cant = 0;

    cout<<"INGRESE CANTIDAD MINIMA PARA EL RANGO DE PRODUCTOS"<<endl;
    precioMinimo = solicitarPrecio();
    cout<<"INGRESE CANTIDAD MAXIMA PARA EL RANGO DE PRODUCTOS"<<endl;

    precioMaximo = solicitarPrecio();



        while(precioMinimo>precioMaximo) {
            cout<<"CANTIDAD MINIMA NO PUEDE SER MAYOR AL MAXIMO"<<endl;
             cout<<"INGRESE CANTIDAD MINIMA PARA EL RANGO DE PRODUCTOS"<<endl;
            precioMinimo = solicitarPrecio();
            cout<<"INGRESE CANTIDAD MAXIMA PARA EL RANGO DE PRODUCTOS"<<endl;
             precioMaximo = solicitarPrecio();
        }



    int cantidadRegistros = archiP.cantidadRegistros();

        for(int i=0;i<cantidadRegistros;i++) {
            reg = archiP.leerRegistrosID(i);

            if(reg.getEstado()==true && reg.getCantidadProductos() >= precioMinimo && reg.getCantidadProductos() <= precioMaximo ) {
                cant++;
                reg.mostrar();
            }


        }

         if (cant ==0) {

            cout<<"NO HAY REGISTROS CON ESE RANGO DE PRODUCTOS"<<endl;
        }
}

