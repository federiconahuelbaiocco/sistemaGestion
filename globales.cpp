#include<iostream>
#include <cstring>
#include <cstdio>

#include "Globales.h"
#include "Persona.h"


using namespace std;

void copiarCharArray(char destino[], const char origen[]){
    int tamanio = strlen(origen);
    strncpy(destino, origen, tamanio);
    destino[tamanio] = '\0';
}

Empleado* comprobarUsuario(const Empleado& empleado){

    Empleado* emp = new Empleado;
    FILE* eFile = fopen("lista_empleados.dat", "rb");
    if(eFile == NULL){
        delete emp;
        return nullptr;
    }

    while(fread(emp, sizeof(Empleado), 1, eFile) == 1){
        if(strcmp(emp->getUsuario(), empleado.getUsuario()) == 0){
            fclose(eFile);
            return emp;
        }
    }
    fclose(eFile);
    delete emp;
    return nullptr;
}

bool registrarUsuario(const Empleado& emp){
    if(comprobarUsuario(emp) != nullptr){
        return false;
    }
    FILE* eFile = fopen("lista_empleados.dat", "ab");
    if(eFile == NULL) return false;

    bool realizado = fwrite(&emp, sizeof(Empleado), 1, eFile);
    fclose(eFile);

    return realizado;
}

bool listarUsuarios(){
    Empleado emp;
    int tamanio = sizeof(emp);
    FILE* eFile = fopen("lista_empleados.dat", "rb");
    if (eFile == NULL) return false;
    while (fread(&emp, tamanio, 1, eFile) == 1) {
        cout << "ID: " << emp.getID() << "\nNombre: " << emp.getNombre() << "\n";  // getNombre() debe ser const
        cout << "Admin: " << (emp.esAdmin() ? "Si" : "No") << "\n";               // esAdmin() debe ser const
        cout << "Tickets cerrados: " << emp.getTicketsCerrados() << "\n";         // getTicketsCreados() debe ser const
        cout << "Tickets anulados: " << emp.getTicketsAnulados() << "\n";         // getTicketsAnulados() debe ser const
        cout << "Usuario: " << emp.getUsuario() << "\n";         // getTicketsCreados() debe ser const
        cout << "Contrasenia: " << emp.getContrasenia() << "\n";         // getTicketsAnulados() debe ser const
        cout << sizeof(Empleado) << endl;
        cout << sizeof(eFile) << endl;
        cout << "-----------------------------------" << endl;
    }
    fclose(eFile);
    return true;
}

