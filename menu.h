#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Persona.h"
#include "Producto.h"

class Menu; //Para que MenuManager visibilice la clase

class MenuManager{
    Menu* inicial;
    Menu* menus[21];
    Empleado* empleado;
        // Realizar un array copia, añadir ahi el nuevo producto, y reemplazar el viejo.
        // Tener un array secundario, que guarde los productos durante la sesion.
    int menuActual = 0;
public:
    bool buclePrincipal = true;

    MenuManager();
    ~MenuManager();

    Empleado* getUsuario();

    void setUsuario(Empleado* empleado);
    void cargarMenus();
    void cambiarMenuActual(int indice);
    void bucle();
};
class Menu{
protected:
    char titulo[20];
    char** opciones;
    MenuManager* manager;
public:
    int cantidadOpciones;
    int menuAnterior;

    Menu(MenuManager& mngr) : manager(&mngr) {};

    ~Menu();

    void setID(const char title[], const int menuAnterior);
    void setOpciones(const int cantidadOpciones, const char opciones[][20]);
    bool estaEnRango(const int indice);
    bool virtual accion();
    void mostrarTitulo();
    void mostrarOpciones();
    void mostrarMenu();
    int seleccionarOpcion();
};

class InicioSesion : public Menu{
public:
    InicioSesion(MenuManager& mngr);
    bool accion() override;
};
class MenuPrincipal : public Menu{
public:
    MenuPrincipal(MenuManager& mngr, bool admin);
    bool accion() override;
};
class GestionTicket : public Menu{
public:
    GestionTicket(MenuManager& mngr);
    bool accion() override;
};
class MenuListados : public Menu {
public:
    MenuListados(MenuManager& manager);
    bool accion() override;
};
class MenuConsultas : public Menu {
public:
    MenuConsultas(MenuManager& manager);
    bool accion() override;
};
class MenuInformes : public Menu {
public:
    MenuInformes(MenuManager& manager, bool admin);
    bool accion() override;
};
class ABM : public Menu {
public:
    ABM(MenuManager& manager);
    bool accion() override;
};

class CreadorTicket : public Menu{
public:
    CreadorTicket(MenuManager& mngr);
    bool accion() override;
};
class AnuladorTicket : public Menu{
public:
    AnuladorTicket(MenuManager& mngr);
    bool accion() override;
};

class ListadosProductos : public Menu {
public:
    ListadosProductos(MenuManager& manager);
    bool accion() override;
};
class ListadosProveedor : public Menu {
public:
    ListadosProveedor(MenuManager& manager);
    bool accion() override;
};
class ListadosTicket : public Menu {
public:
    ListadosTicket(MenuManager& manager);
    bool accion() override;
};

class ConsultasProductos : public Menu {
public:
    ConsultasProductos(MenuManager& manager);
    bool accion() override;
};
class ConsultaProveedor : public Menu {
public:
    ConsultaProveedor(MenuManager& manager);
    bool accion() override;
};
class ConsultaTicket : public Menu {
public:
    ConsultaTicket(MenuManager& manager);
    bool accion() override;
};

class InformeStock : public Menu {
public:
    InformeStock(MenuManager& manager);
    bool accion() override;
};
class InformeRecDia : public Menu {
public:
    InformeRecDia(MenuManager& manager);
    bool accion() override;
};
class InformeRecMes : public Menu {
public:
    InformeRecMes(MenuManager& manager);
    bool accion() override;
};
class InformeTicketAC : public Menu {
public:
    InformeTicketAC(MenuManager& manager);
    bool accion() override;
};

class ABMProductos : public Menu {
public:
    ABMProductos(MenuManager& manager);
    bool accion() override;

};
class ABMProveedores : public Menu {
public:
    ABMProveedores(MenuManager& manager);
    bool accion() override;

};
class ABMEmpleados : public Menu {
public:
    ABMEmpleados(MenuManager& manager);
    bool accion() override;

};

#endif // MENU_H_INCLUDED
