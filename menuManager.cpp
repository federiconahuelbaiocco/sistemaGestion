#include<iostream>

#include "menu.h"

using namespace std;

/// ESTO DEFINE AL INICIO DE SESION COMO PRIMER MENU

MenuManager::MenuManager(){
    MenuManager::empleado = new Empleado();
    MenuManager::menuActual = -1;
    MenuManager::inicial = new InicioSesion(*this);
}

/// FIN PRIMER MENU

MenuManager::~MenuManager(){
    delete[] menus;
}

Empleado* MenuManager::getUsuario(){return MenuManager::empleado;}

void MenuManager::setUsuario(Empleado* empleado){MenuManager::empleado = empleado;}
void MenuManager::cambiarMenuActual(int indice){MenuManager::menuActual = indice;system("cls");}
void MenuManager::cargarMenus(){
    MenuManager::menus[0] = new MenuPrincipal(*this, MenuManager::empleado->esAdmin());
    MenuManager::menus[1] = new GestionTicket(*this);
    MenuManager::menus[2] = new MenuListados(*this);
    MenuManager::menus[3] = new MenuConsultas(*this);
    MenuManager::menus[4] = new MenuInformes(*this, MenuManager::empleado->esAdmin());
    MenuManager::menus[5] = new ABM(*this);
    MenuManager::menus[6] = new CreadorTicket(*this);
    MenuManager::menus[7] = new AnuladorTicket(*this);
    MenuManager::menus[8] = new ListadosProductos(*this);
    MenuManager::menus[9] = new ListadosProveedor(*this);
    MenuManager::menus[10] = new ListadosTicket(*this);
    MenuManager::menus[11] = new ConsultasProductos(*this);
    MenuManager::menus[12] = new ConsultaProveedor(*this);
    MenuManager::menus[13] = new ConsultaTicket(*this);
    MenuManager::menus[14] = new InformeStock(*this);
    MenuManager::menus[15] = new InformeRecDia(*this);
    MenuManager::menus[16] = new InformeRecMes(*this);
    MenuManager::menus[17] = new InformeTicketAC(*this);
    MenuManager::menus[18] = new ABMProductos(*this);
    MenuManager::menus[19] = new ABMProveedores(*this);
    MenuManager::menus[20] = new ABMEmpleados(*this);
}
void MenuManager::bucle(){
    while(MenuManager::buclePrincipal){
        if(MenuManager::menuActual == -1){
            MenuManager::inicial->accion();
        }else{
            MenuManager::menus[menuActual]->accion();
        }
    }
}



