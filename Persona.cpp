#include<iostream>

#include "Globales.h"
#include "Persona.h"
#include "archivoProveedor.h"

using namespace std;

int Persona::getID() const {return Persona::id;}
const char* Persona::getNombre() const {return Persona::nombre;}
void Persona::setID(int id) {Persona::id = id;}
void Persona::setNombre(const char* nombre) {copiarCharArray(Persona::nombre, nombre);}
void Persona::Cargar() {
    std::cout << "Ingrese ID: ";
    std::cin >> id;
    std::cout << "Ingrese Nombre: ";
    std::cin >> nombre;
    std::cout << "Ingrese Fecha de Nacimiento: " << std::endl;
    Persona::fechaNacimiento.cargar();
}
void Persona::Mostrar() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << std::endl;
    std::cout << "Fecha de Nacimiento: ";
    Persona::fechaNacimiento.mostrar();
}

Empleado::Empleado() {

}
Empleado::Empleado(Empleado* empleado){  /// RECIBO UN PUNTERO A UN OBJETO EMPLEADO Y COPIO LOS VALORES DE LA DIRECCION DE MEMORIA DONDE APUNTA
                                         /// A UN NUEVO OBJETO
    Empleado::setUsuario(empleado->usuario);
    Empleado::setContrasenia(empleado->contrasenia);
    Empleado::setAdmin(empleado->admin);
    Empleado::setID(empleado->id);
    Empleado::setNombre(empleado->nombre);
    Empleado::setTicketsAnulados(empleado->ticketAnulados);
    Empleado::setTicketsCerrados(empleado->ticketCerrados);
}





const char* Empleado::getUsuario() const {return Empleado::usuario;}
const char* Empleado::getContrasenia()const {return Empleado::contrasenia;}
bool Empleado::esAdmin() const {return Empleado::admin;}
int Empleado::getTicketsCerrados() const {return Empleado::ticketCerrados;}
int Empleado::getTicketsAnulados() const {return Empleado::ticketAnulados;}
void Empleado::setUsuario(const char* usuario){copiarCharArray(Empleado::usuario, usuario);}
void Empleado::setContrasenia(const char* contrasenia){copiarCharArray(Empleado::contrasenia, contrasenia);}
void Empleado::setAdmin(bool admin){Empleado::admin = admin;}
void Empleado::setTicketsCerrados(int tickets){Empleado::ticketCerrados = tickets;}
void Empleado::setTicketsAnulados(int tickets){Empleado::ticketAnulados = tickets;}

Proveedor::Proveedor(){

}
int Proveedor::getCantidadProductos() const {return Proveedor::cantidadProductos;}
void Proveedor::setCantidadProductos(const int cantidad){Proveedor::cantidadProductos = cantidad;}
void Proveedor::cargar() {
    archivoProveedor archiP;

    if(archiP.cantidadRegistros()==-1) {
        id=1;
    } else {
        id=archiP.cantidadRegistros()+1;
    }

    cout<<"ID: "<<id<<endl;
    cin.ignore();


    cout<<"INGRESE NOMBRE DEL PROVEEDOR: "<<endl;
    cin.getline(Proveedor::nombre,20);
        mayusculas(Proveedor::nombre);   /// ESTANDARIZAR A MAYUSCULAS PARA BUSQUEDAS

    cout <<"INGRESE LA CANTIDAD DE PRODUCTOS RELACIONADOS: " << endl;
    cin >> Proveedor::cantidadProductos;

    cin.ignore();

     cout<<"INGRESE TELEFONO DEL PROVEEDOR: "<<endl;
    cin.getline(Proveedor::telefono,11);
        mayusculas(Proveedor::telefono);    /// ESTANDARIZAR A MAYUSCULAS PARA BUSQUEDAS

    estado=true;

}
void Proveedor::mostrar(){

    if(estado) {
    cout<<"ID: "<<Proveedor::id<<endl;
    cout<<"NOMBRE: "<<Proveedor::nombre<<endl;
    cout<<"PROD. RELACIONADOS: "<<Proveedor::cantidadProductos<<endl;
    cout<<"TELEFONO: "<<Proveedor::telefono<<endl;
    }
}
bool Proveedor::getEstado(){return Proveedor::estado;}
void Proveedor::setEstado(bool estado){Proveedor::estado = estado;}
void Proveedor::setTelefono(char* telefono){copiarCharArray(Proveedor::telefono, telefono);}

