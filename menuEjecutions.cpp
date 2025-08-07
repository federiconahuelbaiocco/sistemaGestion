#include<iostream>
#include <cstring>

#include "Globales.h"
#include "menu.h"
#include "Producto.h"
#include "archivoProducto.h"
#include "archivoProveedor.h"
#include "Listados.h"
#include "Consultas.h"
#include "Ticket.h"
#include "ProductoTIcket.h"

using namespace std;

CreadorTicket::CreadorTicket(MenuManager& manager) : Menu(manager){
    CreadorTicket::setID("   CREAR TICKET   ", 1);
    char op[1][20] = {"Creador de Ticket"};
    CreadorTicket::setOpciones(1, op);
}
bool CreadorTicket::accion(){

    Ticket ticket;
    ticket.setEmpleado(manager->getUsuario());

    archivoProducto archivo;

    Producto producto;

    bool cargando = true;

    int idProducto;
    char confirmar;
    int unidades;

    int cargados = 0;

    while(cargando){
        system("cls");
        CreadorTicket::mostrarTitulo();
        std::cout << "|                                                            |" << std::endl;
        for(int i = 0; i < cargados; i++){ticket.getProducto(i).imprimir(i+1);}
        std::cout << "|                                                            |" << std::endl;
        std::cout << "+--------------------+------------------+--------------------+" << std::endl << std::endl;

        std::cout << "Ingresar la ID del producto: ";
        std::cin >> idProducto;

        int pos = archivo.buscarRegistro(idProducto, true);
        producto = archivo.leerRegistrosID(pos);

        if(producto.getID() == idProducto){
            std::cout << "Ha seleccionado el siguiente producto: ";
            std::cout << producto.getName() << "." << std::endl;
            std::cout << "Desea añadir este producto? (Y/N) : ";
            std::cin >> confirmar;
            if(confirmar == 'Y'){
                std::cout << "Cuantas unidades desea añadir? : ";
                std::cin >> unidades;
                std::cout << "Desea añadir " << unidades << " unidades de " << producto.getName() << "? (Y/N) : ";
                std::cin >> confirmar;
                if(confirmar == 'Y'){
                    ticket.setCantidadProductos(ticket.getCantidad()+1);
                    ticket.addProducto(producto, cargados);
                    ticket.getProducto(cargados).imprimir(0);
                    cargados++;
                }else{

                }

            }else{

            }
        }else{
            std::cout << "No se ha encontrado un producto con la ID solicitada." << std::endl;
        }
        std::cout << "Desea seguir cargando mas productos? (Y/N): " << std::endl;
        std::cin >> confirmar;
        if(confirmar == 'N'){
            cargando = false;
        }
    }
    std::cout << "Desea cerrar el ticket y guardarlo? (Y/N): " << std::endl;
    std::cin >> confirmar;
    if(confirmar == 'Y'){
        cargando = false;
    }else if(confirmar == 'N'){
        manager->cambiarMenuActual(1);
    }
    return true;
}
AnuladorTicket::AnuladorTicket(MenuManager& manager) : Menu(manager){
    AnuladorTicket::setID("  ANULAR TICKET   ", 1);
    char op[1][20] = {"Creador de Ticket"};
    AnuladorTicket::setOpciones(1, op);
}
bool AnuladorTicket::accion(){
    return true;
}

ListadosProductos::ListadosProductos(MenuManager& manager) : Menu(manager) {
    ListadosProductos::setID("  LISTA PRODUCTOS ",2);

    const char opciones[6][20] {
        "ORD.POR ID",
        "ORD.POR NOMBRE",
        "ORD.POR MARCA",
        "ORD.POR PROVEEDOR",
        "ORD.PRECIO DE VENTA",
        "ORD.POR STOCK",
    };
    ListadosProductos::setOpciones(6,opciones);
}
bool ListadosProductos::accion() {
    int resultado = seleccionarOpcion();
    archivoProducto archiP;
    Listados listados;

    switch(resultado) {
        case 0:
            ListadosProductos::manager->cambiarMenuActual(ListadosProductos::menuAnterior);
            break;
        case 1:archiP.ListarRegistros();
               system("pause");
            break;
        case 2:listados.ordenadoNombre();
               system("pause");
            break;
        case 3:listados.ordenadoMarca();
               system("pause");
            break;
        case 4:listados.ordenadoProveedor();
               system("pause");
            break;
        case 5:listados.ordenadoPrecio();
               system("pause");
            break;
        case 6:listados.ordenadoStock();
               system("pause");
            break;


    }

    return true;
}
ListadosProveedor::ListadosProveedor(MenuManager& manager) : Menu(manager) {
    ListadosProveedor::setID("  LISTA PROVEEDOR ",2);

    const char opciones[3][20] {
        "POR ID",
        "ORD.NOMBRE",
        "ORD.CANT DE PROD."};
    ListadosProveedor::setOpciones(3,opciones);
}
bool ListadosProveedor::accion() {
    int resultado = seleccionarOpcion();
    archivoProveedor archiP;
    Listados listados;

    switch(resultado) {
        case 0:
            ListadosProveedor::manager->cambiarMenuActual(ListadosProveedor::menuAnterior);
            break;
        case 1:archiP.ListarRegistros();
               system("pause");
            break;
        case 2:listados.ordenadoNombreProveedor();
               system("pause");
            break;
        case 3:listados.ordenadoCantidad();
               system("pause");
            break;


    }

    return true;
}
ListadosTicket::ListadosTicket(MenuManager& manager) : Menu(manager) {
    ListadosTicket::setID("  LISTA TICKETS   ",2);

    const char opciones[6][20] {
        "ORD.POR ID",
        "ORD.POR NOMBRE",
        "ORD.POR MARCA",
        "ORD.POR PROVEEDOR",
        "ORD.PRECIO DE VENTA",
        "ORD.POR STOCK",
    };
    ListadosTicket::setOpciones(6,opciones);
}
bool ListadosTicket::accion() {
    return true;
}

ConsultasProductos::ConsultasProductos(MenuManager& manager) : Menu(manager) {
    ConsultasProductos::setID("CONSULTAS PRODUCTO",3);

    const char opciones[6][20] {
        "BUSCAR POR ID",
        "POR NOMBRE Y MARCA",
        "FILTRADA MARCA",
        "FILTRADA PROVEEDOR",
        "POR RANGO DE PRECIO",
        "RANGO DE STOCK",
    };
    ConsultasProductos::setOpciones(6,opciones);
}
bool ConsultasProductos::accion() {
    int resultado = seleccionarOpcion();
    Consultas consultas;
    Producto reg;

    switch(resultado) {
        case 0:
            ConsultasProductos::manager->cambiarMenuActual(ConsultasProductos::menuAnterior);
            break;
        case 1:consultas.busquedaIndividualID();
               system("pause");
            break;
        case 2:consultas.busquedaIndividualNombreyMarca();
               system("pause");
            break;
        case 3:consultas.listadoPorMarca();
               system("pause");
            break;
        case 4:consultas.listaPorProveedor();
               system("pause");
            break;
        case 5:consultas.listaRangoPrecio();
               system("pause");
            break;
        case 6:consultas.listaRangoStock();
               system("pause");
            break;
    }

    return true;
}
ConsultaProveedor::ConsultaProveedor(MenuManager& manager) : Menu(manager) {
    ConsultaProveedor::setID("CONSULTAS PROVEED.",3);

    const char opciones[3][20] {
        "BUSCAR POR ID",
        "POR NOMBRE",
        "POR CANT. DE PROD."};
    ConsultaProveedor::setOpciones(3,opciones);
}
bool ConsultaProveedor::accion() {
    int resultado = seleccionarOpcion();
    Consultas consultas;
    Proveedor reg;

    switch(resultado) {
        case 0:
            ConsultaProveedor::manager->cambiarMenuActual(ConsultaProveedor::menuAnterior);
            break;
        case 1:consultas.busquedaIndividualIDProveedor();
               system("pause");
            break;
        case 2:consultas.busquedaIndividualNombre();
               system("pause");
            break;
        case 3:consultas.listaRangoProductos();
               system("pause");
            break;
    }

    return true;
}
ConsultaTicket::ConsultaTicket(MenuManager& manager) : Menu(manager) {
    ConsultaTicket::setID("CONSULTAS TICKETS ",3);

    const char opciones[6][20] {
        "BUSCAR POR ID",
        "POR NOMBRE Y MARCA",
        "FILTRADA MARCA",
        "FILTRADA PROVEEDOR",
        "POR RANGO DE PRECIO",
        "RANGO DE STOCK",
    };
    ConsultaTicket::setOpciones(6,opciones);
}
bool ConsultaTicket::accion() {
    return true;
}

InformeStock::InformeStock(MenuManager& manager) : Menu(manager){
    InformeStock::setID("  INFORME STOCK   ",4);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    InformeStock::setOpciones(4,opciones);
}
bool InformeStock::accion(){
    return true;
}
InformeRecDia::InformeRecDia(MenuManager& manager) : Menu(manager){
    InformeRecDia::setID(" INFORME REC.DIA  ",4);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    InformeRecDia::setOpciones(4,opciones);
}
bool InformeRecDia::accion(){
    return true;
}
InformeRecMes::InformeRecMes(MenuManager& manager) : Menu(manager){
    InformeRecMes::setID(" INFORME REC.MES  ",4);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    InformeRecMes::setOpciones(4,opciones);
}
bool InformeRecMes::accion(){
    return true;
}
InformeTicketAC::InformeTicketAC(MenuManager& manager) : Menu(manager){
    InformeTicketAC::setID("INFORME TICKET AC ",4);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    InformeTicketAC::setOpciones(4,opciones);
}
bool InformeTicketAC::accion(){
    return true;
}

ABMProductos::ABMProductos(MenuManager& manager) : Menu(manager) {
    ABMProductos::setID("  ABM PRODUCTOS   ",5);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    ABMProductos::setOpciones(4,opciones);
}
bool ABMProductos::accion() {
    int resultado = seleccionarOpcion();
    archivoProducto archiP;
    Producto reg;


    switch(resultado) {
        case 0:
            ABMProductos::manager->cambiarMenuActual(ABMProductos::menuAnterior);
            break;
        case 1:reg.cargar();
         if (archiP.GrabarRegistro(reg)==true) {

                    cout<<"REGISTRO AGREGADO"<<endl;

                  } else {
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                  }
               system("pause");
            break;
        case 2:
               archiP.altaRegistro();
                system("pause");
            break;
        case 3: archiP.bajaRegistro();
               system("pause");
            break;
        case 4:archiP.modificacionRegistro();
               system("pause");
            break;

    }

    return true;
}
ABMProveedores::ABMProveedores(MenuManager& manager) : Menu(manager) {
    ABMProveedores::setID(" ABM PROVEEDORES  ",5);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    ABMProveedores::setOpciones(4,opciones);
}
bool ABMProveedores::accion() {
    int resultado = seleccionarOpcion();
    archivoProveedor archiP;
    Proveedor reg;


    switch(resultado) {
        case 0:
            ABMProveedores::manager->cambiarMenuActual(ABMProveedores::menuAnterior);
            break;
        case 1:reg.cargar();
         if (archiP.GrabarRegistro(reg)==true) {

                    cout<<"REGISTRO AGREGADO"<<endl;

                  } else {
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                  }
               system("pause");
            break;
        case 2:
               archiP.altaRegistro();
                system("pause");
            break;
        case 3: archiP.bajaRegistro();
               system("pause");
            break;
        case 4:archiP.modificacionRegistro();
               system("pause");
            break;

    }

    return true;
}
ABMEmpleados::ABMEmpleados(MenuManager& manager) : Menu(manager) {
    ABMEmpleados::setID("  ABM EMPLEADOS   ",5);

    const char opciones[4][20] {
        "CARGAR NUEVO ",
     "ALTA YA REGISTRADO",
        "BAJA",
        "MODIFICAR"
    };
    ABMEmpleados::setOpciones(4,opciones);
}
bool ABMEmpleados::accion() {
    return true;
}


