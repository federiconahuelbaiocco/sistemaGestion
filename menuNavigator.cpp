#include<iostream>
#include <cstring>

#include "Globales.h"
#include "menu.h"

using namespace std;

InicioSesion::InicioSesion(MenuManager& manager) : Menu(manager){
    InicioSesion::setID("  INICIAR SESION  ", 0);
    const char op[][20] = {
        "Usuario: ",
        "Contraseña: "};
    InicioSesion::setOpciones(2, op);
}
bool InicioSesion::accion(){
    InicioSesion::manager->setUsuario(nullptr);
    char ingresoUsuario[20] = "";
    char ingresoContrasenia[20] = "";
    Empleado empleadoIngreso;

    while(InicioSesion::manager->getUsuario() == nullptr){
        system("cls");
        if(strcmp(ingresoUsuario,"") != 0){std::cout << "Usuario y/o contrasenia incorrecto/s. Intente denuevo." << std::endl;}
        mostrarTitulo();
        std::cout << "+--------------------+------------------+--------------------+" << std::endl;
        std::cout << InicioSesion::opciones[0];
        std::cin.getline(ingresoUsuario, 20);
        std::cout << std::endl;
        std::cout << InicioSesion::opciones[1];
        std::cin.getline(ingresoContrasenia, 20);
        std::cout << std::endl;

        empleadoIngreso.setUsuario(ingresoUsuario);
        empleadoIngreso.setContrasenia(ingresoContrasenia);
        Empleado* empleadoCargado = comprobarUsuario(&empleadoIngreso);
        if(empleadoCargado != nullptr && strcmp(empleadoIngreso.getContrasenia(), empleadoCargado->getContrasenia()) == 0){
            InicioSesion::manager->setUsuario(empleadoCargado);
            InicioSesion::manager->cambiarMenuActual(InicioSesion::menuAnterior);
            InicioSesion::manager->cargarMenus();
            system("cls");
            break;
        }
    }
    return false;
}

MenuPrincipal::MenuPrincipal(MenuManager& manager, bool admin) : Menu(manager){
    MenuPrincipal::setID("  MENU PRINCIPAL  ", -1);
    char adminOptions[5][20] = {
        "Gestionar Tickets",
        "Listados",
        "Consultas",
        "Informes",
        "Altas/Bajas/Modif."}; //Añadir Modificar o Quitar, Empleados, Proveedores y Productos.
    char userOptions[4][20] = {
        "Gestionar Tickets",
        "Listados",
        "Consultas",
        "Informes"};

    if(admin){MenuPrincipal::setOpciones(5,adminOptions);
    }else{MenuPrincipal::setOpciones(4,userOptions);}

}
bool MenuPrincipal::accion(){
    int resultado = MenuPrincipal::seleccionarOpcion();
    switch(resultado){
        case 0:manager->cambiarMenuActual(Menu::menuAnterior);break;//InicioSesion
        case 1:manager->cambiarMenuActual(1);break;//Tickets
        case 2:manager->cambiarMenuActual(2);break;//Listado
        case 3:manager->cambiarMenuActual(3);break;//Consulta
        case 4:manager->cambiarMenuActual(4);break;//Informe
        case 5:manager->cambiarMenuActual(5);break;//ABM
    }
    return true;
}

GestionTicket::GestionTicket(MenuManager& manager) : Menu(manager){
    GestionTicket::setID("     TICKETS      ", 0);
    char opciones[2][20] = {
        "Crear Tickets",
        "Anular Tickets"};
    GestionTicket::setOpciones(2,opciones);
}
bool GestionTicket::accion(){
    int resultado = GestionTicket::seleccionarOpcion();
    switch(resultado){
    case 0:manager->cambiarMenuActual(GestionTicket::menuAnterior);break;//MenuPrincipal
    case 1:manager->cambiarMenuActual(6);break;//CreacionTicket
    case 2:manager->cambiarMenuActual(7);break;//AnularTicket
    }
    return true;
}

MenuListados::MenuListados (MenuManager& manager) : Menu (manager) {
    MenuListados::setID("     LISTADOS     ",0);
    const char opciones[][20] = {
    "Productos",
    "Proveedores",
    "Tickets"
    };

    MenuListados::setOpciones(3,opciones);

}
bool MenuListados::accion() {
     int resultado = seleccionarOpcion();
    switch (resultado) {
        case 0:manager->cambiarMenuActual(MenuListados::menuAnterior);break;//MenuPrincipal
        case 1:manager->cambiarMenuActual(8);break;//ListadoProducto
        case 2:manager->cambiarMenuActual(9);break;//ListadoProveedor
        case 3:manager->cambiarMenuActual(10);break;//ListadoTicket
    }
    return true;
}

MenuConsultas::MenuConsultas (MenuManager& manager) : Menu (manager) {
    MenuConsultas::setID("     CONSULTAS    ",0);
    const char opciones[3][20] = {
    "Productos",
    "Proveedores",
    "Tickets"
    };

    MenuConsultas::setOpciones(3,opciones);
}
bool MenuConsultas::accion() {
     int resultado = seleccionarOpcion();
    switch (resultado) {
        case 0:manager->cambiarMenuActual(MenuConsultas::menuAnterior);break;//MenuPrincipal
        case 1:manager->cambiarMenuActual(11);break;//Cons. Prod
        case 2:manager->cambiarMenuActual(12);break;//Cons. Prov
        case 3:manager->cambiarMenuActual(13);break;//Cons. Tick
    }
    return true;
}

MenuInformes::MenuInformes(MenuManager& manager, bool admin) : Menu(manager){
    MenuInformes::setID("     INFORMES     ", 0);

    char adminOptions[4][20] = {
        "Fuera de Stock",
        "Recaudacion Dia",
        "Recaudacion Mes",
        "T.Anulados/Cerrados"};
    char userOptions[3][20] = {
        "Fuera de Stock",
        "Recaudacion Dia",
        "Recaudacion Mes"};
    if(admin){MenuInformes::setOpciones(4,adminOptions);
    }else{MenuInformes::setOpciones(3,userOptions);}

}
bool MenuInformes::accion(){
    int resultado = seleccionarOpcion();
    switch (resultado) {
        case 0:manager->cambiarMenuActual(MenuInformes::menuAnterior);break;//MenuPrincipal
        case 1:manager->cambiarMenuActual(14);break;//InformeStock
        case 2:manager->cambiarMenuActual(15);break;//InformeRecDia
        case 3:manager->cambiarMenuActual(16);break;//InformRecMes
        case 4:manager->cambiarMenuActual(17);break;//T.Anulados/Cerrados
    }
    return true;
}

ABM::ABM (MenuManager& manager) : Menu (manager) {
    ABM::setID(" ALTA/BAJA/MODIF. ",0);
    const char opciones[3][20] = {
    "Productos",
    "Proveedores",
    "Empleados"
    };

    ABM::setOpciones(3,opciones);

}
bool ABM::accion() {
    int resultado = seleccionarOpcion();
    switch (resultado) {
        case 0:manager->cambiarMenuActual(ABM::menuAnterior);break;//MenuPrincipal
        case 1:manager->cambiarMenuActual(18);break;//ABM Productos
        case 2:manager->cambiarMenuActual(19);break;//ABM Proveedores
        case 3:manager->cambiarMenuActual(20);break;//ABM Empleados
    }
    return true;

}
