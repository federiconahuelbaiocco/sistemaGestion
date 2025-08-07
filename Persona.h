#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "Fecha.h"
#include "Producto.h"

class Persona{
protected:
    int id;
    char nombre[20] = {};
public:
    Fecha fechaNacimiento;

    int getID() const;
    const char* getNombre() const;
    void setID(int id);
    void setNombre(const char* nombre);
    void Cargar();
    void Mostrar();
};

class Empleado : public Persona{
private:
    char usuario[20] = {};
    char contrasenia[20] = {};
    bool admin;
    int ticketCerrados;
    int ticketAnulados;
public:

    Empleado();
    Empleado(Empleado* empleado);
    const char* getUsuario() const;
    const char* getContrasenia() const;
    bool esAdmin() const;
    int getTicketsCerrados() const;
    int getTicketsAnulados() const;

    void setUsuario(const char* usuario);
    void setContrasenia(const char* contrasenia);
    void setAdmin(bool admin);
    void setTicketsCerrados(int tickets);
    void setTicketsAnulados(int tickets);
};

class Proveedor : public Persona{
private:
    int cantidadProductos;
    char telefono[11];
    bool estado;
public:
    Proveedor();

    int getCantidadProductos() const;
    void setCantidadProductos(int cantidad);
    void setTelefono(char* telefono);
    char* getTelefono();
    void cargar();
    void mostrar();
    bool getEstado();
    void setEstado(bool estado);
};

#endif // PERSONA_H_INCLUDED
