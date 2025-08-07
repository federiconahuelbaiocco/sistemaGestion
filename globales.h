#ifndef GLOBALES_H_INCLUDED
#define GLOBALES_H_INCLUDED

#include "Persona.h"
#include "Producto.h"

void copiarCharArray(char destino[], const char origen[]);

Empleado* comprobarUsuario(const Empleado& emp);
bool registrarUsuario(const Empleado& emp);
bool listarUsuarios();

#endif // GLOBALES_H_INCLUDED
