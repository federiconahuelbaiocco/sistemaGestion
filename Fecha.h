#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio, horas, minutos, segundos;
public:
    Fecha(int d = 0, int m = 0, int a = 0, int horas = 0, int minutos = 0, int segundos = 0);

    void cargar();
    void mostrar();

    void setActual();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void setHoras(int horas);
    void setMinutos(int minutos);
    void setSegundos(int segundos);

    const int getDia();
    const int getMes();
    const int getAnio();
    const int getHoras();
    const int getMinutos();
    const int getSegundos();
};

#endif // FECHA_H_INCLUDED
