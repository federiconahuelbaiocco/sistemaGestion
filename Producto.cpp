  #include<iostream>
  #include<cstdlib>
  #include<cstring>
 using namespace std;

#include "Producto.h"
#include "archivoProducto.h"

#include <cctype>
#include <limits>

void mayusculas(char* cad) {
    for (int i = 0; cad[i] != '\0'; ++i) {
        cad[i] = toupper(cad[i]); // TOUPPER PASA 1 CARACTER A MAYUSCULA A LA VEZ
    }
}

float solicitarPrecio() {



    float precio;

    while (true) {

        cin >> precio;


        if (cin.fail()) { /// VERIFICA SI ES VALIDA LA ENTRADA
            cin.clear(); /// LIMPIA EL ESTADO DE ERROR
            cin.ignore(10000,'\n');
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NÚMERO PARA EL PRECIO: " << endl;
        } else if (precio <= 0) {
            cout << " EL PRECIO NO PUEDE SER CERO O NEGATIVO. INGRESE NUEVAMENTE" << endl;

        } else {
            cin.ignore(10000,'\n');
            return precio;

        }
    }
}

int solicitarStock() {

    int stock;

    while (true) {
        cin >> stock;


        if (cin.fail()) { /// VERIFICA SI ES VALIDA LA ENTRADA
            cin.clear(); /// LIMPIA EL ESTADO DE ERROR
            cin.ignore(10000,'\n');
            cout << "ENTRADA NO VALIDA. POR FAVOR INGRESE UN NÚMERO PARA EL STOCK: " << endl;
        } else if (stock <= 0) {
            cout << "STOCK NO PUEDE SER CERO O NEGATIVO. INGRESE NUEVAMENTE" << endl;

        } else {
            cin.ignore(10000,'\n');
            return stock;

        }
    }
}



Producto::Producto()
{
    //ctor
}

Producto::~Producto()
{
    //dtor
}

void Producto::cargar() {
    archivoProducto archiP;


    if(archiP.cantidadRegistros()==-1) {

        id=1;
    } else {
        id=archiP.cantidadRegistros()+1;
    }

    cout<<"ID: "<<id<<endl;
    cin.ignore();


    cout<<"INGRESE NOMBRE DEL PRODUCTO: "<<endl;
    cin.getline(nombre,20);
        mayusculas(nombre);   /// ESTANDARIZAR A MAYUSCULAS PARA BUSQUEDAS


     cout<<"INGRESE MARCA DEL PRODUCTO: "<<endl;
    cin.getline(marca,20);
        mayusculas(marca);    /// ESTANDARIZAR A MAYUSCULAS PARA BUSQUEDAS



    cout<<"INGRESE NOMBRE DEL PROVEEDOR: "<<endl;
    cin.getline(proveedor,20);
        mayusculas(proveedor);   /// ESTANDARIZAR A MAYUSCULAS PARA BUSQUEDAS



    cout<<"INGRESE PRECIO COMPRA DEL PRODUCTO: "<<endl;
      precioCompra = solicitarPrecio();   /// FUNCION QUE NO PERMITE CARACTERES NI NEGATIVOS

    cout<<"INGRESE PRECIO VENTA DEL PRODUCTO: "<<endl;
      precioVenta = solicitarPrecio();  /// FUNCION QUE NO PERMITE CARACTERES NI NEGATIVOS


    cout<<"INGRESE STOCK: "<<endl;
      stock = solicitarStock();    /// FUNCION QUE NO PERMITE CARACTERES NI NEGATIVOS

    estado=true;

}



void Producto::mostrar() {
    if(estado) {
    cout<<"ID: "<<id<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"MARCA: "<<marca<<endl;
    cout<<"PROVEEDOR: "<<proveedor<<endl;
    cout<<"PRECIO COMPRA: "<<precioCompra<<"$"<<endl;
    cout<<"PRECIO VENTA: "<<precioVenta<<"$"<<endl;
    cout<<"STOCK: "<<stock<<endl;
    }




}

int Producto::getID() {
    return id;
}
const char* Producto::getName() const {
    return nombre;
}
char* Producto::getMarca() {
    return marca;
}
char* Producto::getProveedor() {
    return proveedor;
}
float Producto::getPrecioCompra() {
    return precioCompra;
}
float Producto::getPrecioVenta() {
    return precioVenta;
}
int Producto::getStock() {
    return stock;
}

void Producto::setID(int _id) {
    id=_id;

}

void Producto::setName(char _nombre[]) {
    strcpy(nombre,_nombre);
}
void Producto::setMarca(char _marca[]) {
    strcpy(marca,_marca);
}
void Producto::setProveedor(char _proveedor[]) {
    strcpy(proveedor,_proveedor);
}
void Producto::setPrecioCompra(float _precioCompra) {
    precioCompra = _precioCompra;
}
void Producto::setPrecioVenta(float _precioVenta) {
    precioVenta = _precioVenta;
}
void Producto::setStock(int _stock) {
    stock = _stock;
}
float Producto::calcularGanancia() {
    float ganancia = precioVenta - precioCompra;

    return ganancia;
}

bool Producto::getEstado() {
    return estado;
}

void Producto::setEstado(bool _estado) {
    estado = _estado;
}


bool Producto::operator<(const Producto& otro) const {
    return strcmp(getName(), otro.getName()) < 0;
}

