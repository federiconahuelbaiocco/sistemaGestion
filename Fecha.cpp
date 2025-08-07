#include<iostream>
#include <ctime>

#include "Fecha.h"

using namespace std;

Fecha::Fecha(int dia, int mes, int anio, int horas, int minutos, int segundos){
    Fecha::setDia(dia);
    Fecha::setMes(mes);
    Fecha::setAnio(anio);
    Fecha::setHoras(horas);
    Fecha::setMinutos(minutos);
    Fecha::setSegundos(segundos);
}
void Fecha::cargar(){
    bool cargando = true;
    int d, me, a, h, mi, s;

    while(cargando){
        std::cout << "Ingrese el dia: ";
        std::cin >> d;
        if(d >= 1 && d <= 31){
            Fecha::dia = d;
            cargando = false;
            continue;
        }
        std::cout << "Valor inválido. Intente denuevo." << std::endl;
    }
    cargando = true;
    while(cargando){
        std::cout << "Ingrese el mes: ";
        std::cin >> me;
        if(me >= 1 && me <= 12){
            Fecha::mes = me;
            cargando = false;
            continue;
        }
        std::cout << "Valor inválido. Intente denuevo." << std::endl;
    }
    cargando = true;
    while(cargando){
        std::cout << "Ingrese el anio: ";
        std::cin >> a;
        if(a >= 1950 && a <= 2024){
            Fecha::anio = a;
            cargando = false;
            continue;
        }
        std::cout << "Valor inválido. Intente denuevo." << std::endl;
    }
}
void Fecha::mostrar(){
    cout << Fecha::dia << "/" << Fecha::mes << "/" << Fecha::anio << " - " << Fecha::horas << ":" << Fecha::minutos << ":" << Fecha::segundos << endl;
}

void Fecha::setActual(){
    time_t tiempoActual = time(nullptr);
    tm* tiempoLocal = localtime(&tiempoActual);
    Fecha::setDia(tiempoLocal->tm_mday);
    Fecha::setMes(tiempoLocal->tm_mon+1);
    Fecha::setAnio(tiempoLocal->tm_year+1900);
    Fecha::setHoras(tiempoLocal->tm_hour);
    Fecha::setMinutos(tiempoLocal->tm_min);
    Fecha::setSegundos(tiempoLocal->tm_sec);
}

void Fecha::setDia(const int dia){Fecha::dia = dia;}
void Fecha::setMes(const int mes){Fecha::mes = mes;}
void Fecha::setAnio(const int anio){Fecha::anio = anio;}
void Fecha::setHoras(const int horas){Fecha::horas = horas;}
void Fecha::setMinutos(const int minutos){Fecha::minutos = minutos;}
void Fecha::setSegundos(const int segundos){Fecha::segundos = segundos;}
const int Fecha::getDia(){return Fecha::dia;}
const int Fecha::getMes(){return Fecha::mes;}
const int Fecha::getAnio(){return Fecha::anio;}
const int Fecha::getHoras(){return Fecha::horas;}
const int Fecha::getMinutos(){return Fecha::minutos;}
const int Fecha::getSegundos(){return Fecha::segundos;}
