#include<iostream>
#include<cstring>
#include<cstdio>

#include "Globales.h"
#include "menu.h"

using namespace std;

Menu::~Menu(){
    for(int i = 0; i < cantidadOpciones; i++){delete[] opciones[i];}
    delete[] opciones;
}
void Menu::setID(const char titulo[], const int menuAnterior){
    copiarCharArray(Menu::titulo, titulo);
    Menu::menuAnterior = menuAnterior;
}
void Menu::setOpciones(const int cantidadOpciones, const char opciones[][20]){
    Menu::cantidadOpciones = cantidadOpciones;
    Menu::opciones = new char*[cantidadOpciones];
    for(int i = 0; i < cantidadOpciones; i++){
        Menu::opciones[i] = new char[20]{};
        copiarCharArray(Menu::opciones[i], opciones[i]);
    }
}
bool Menu::estaEnRango(int indice){return (Menu::cantidadOpciones >= indice);}
bool Menu::accion(){}
void Menu::mostrarTitulo(){
    std::cout << "+--------------------+------------------+--------------------+" << std::endl;
    std::cout << "||||||||||||||||||||||";
    std::cout << Menu::titulo;
    std::cout << "||||||||||||||||||||||" << std::endl;
    std::cout << "+--------------------+------------------+--------------------+" << std::endl;
    std::cout << "|                                                            |" << std::endl;
}
void Menu::mostrarOpciones(){
    for(int i = 0; i < cantidadOpciones; i++){
        int tamanio = strlen(opciones[i]);
        char line[62] = {};
        line[0] = '|';
        line[1] = ' ';
        line[2] = (char)((i+1) + '0');
        line[3] = ' ';
        line[4] = '-';
        line[5] = ' ';
        strncpy(&line[6], opciones[i], tamanio);
        for(int j = 6+tamanio; j < 61; j++){
            line[j] = ' ';
        }
        line[61] = '|';
        std::cout << line << std::endl;
    }
    std::cout << "| 0 - Regresar                                               |" << std::endl;
    std::cout << "|                                                            |" << std::endl;
    std::cout << "+--------------------+------------------+--------------------+" << std::endl;
}
int Menu::seleccionarOpcion(){
    int seleccionada = -1;
    while(seleccionada < 0 || seleccionada > Menu::cantidadOpciones){
        system("cls");
        Menu::mostrarTitulo();
        Menu::mostrarOpciones();
        std::cout << std::endl;
        if(seleccionada != -1){std::cout << "Opcion incorrecta" << std::endl;}
        std::cout << std::endl;
        std::cout << "Seleccionar Opcion: ";
        std::cin >> seleccionada;
    }
    return seleccionada;
}



