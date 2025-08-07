  #include<iostream>
  #include<cstdlib>
  #include<cstring>
 using namespace std;

#include "Listados.h"
#include "Producto.h"
#include "Persona.h"
#include "archivoProveedor.h"
#include "archivoProducto.h"


void ordenar(Producto *p, int tam, int opcion) {
    int i, j, posmin;
    Producto auxi;

    for (i = 0; i < tam - 1; i++) {
        posmin = i;  // Inicializa la posición del mínimo en cada paso del ciclo exterior
        for (j = i + 1; j < tam; j++) {

            // Dependiendo de la opción, comparamos por nombre, marca o proveedor
            if (opcion == 1) {  // Comparar por nombre
                if (strcmp(p[j].getName(), p[posmin].getName()) < 0) {
                    posmin = j;
                }
            }
            else if (opcion == 2) {  // Comparar por marca
                if (strcmp(p[j].getMarca(), p[posmin].getMarca()) < 0) {
                    posmin = j;
                }
            }
            else if (opcion == 3) {  // Comparar por proveedor
                if (strcmp(p[j].getProveedor(), p[posmin].getProveedor()) < 0) {
                    posmin = j;
                }
            } else if (opcion==4) {
                if(p[j].getStock() < p[posmin].getStock()) {
                    posmin = j;
                }
            } else if (opcion==5) {
                if(p[j].getPrecioVenta() < p[posmin].getPrecioVenta()) {
                    posmin=j;
                }
            }
        }

        // Intercambiar si es necesario (cuando posmin ha cambiado)
        if (posmin != i) {
            auxi = p[i];
            p[i] = p[posmin];
            p[posmin] = auxi;
        }
    }
}

void Listados::ordenGeneralProductos(int opcion) {

archivoProducto ArchiP;

    Producto reg;

    Producto *p;

    int contadorBajas =0;

    int cantidadRegistros = ArchiP.cantidadRegistros();  /// CANTIDAD TOTAL DE REGISTROS EN ARCHIVO



    for(int i=0;i<cantidadRegistros;i++) {



        reg = ArchiP.leerRegistrosID(i);

        if(reg.getEstado()==false) {
            contadorBajas++;
        }

    }

    int tamanioArray = cantidadRegistros - contadorBajas; /// CANTIDAD REAL DE REGISTROS EN ARCHIVO (SIN ESTAR DE BAJA)




    if(cantidadRegistros==0) {
            cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;

        return;
    }

    p = new Producto[tamanioArray];  /// LO CREO DEL TAMAÑO REAL

    if(p==NULL) {
        cout<<"NO SE PUDO ASIGNAR MEMORIA"<<endl;
        return;
    }

    int j = 0; /// INDICE AUXILIAR PARA EVITAR VACIOS

    for(int i=0;i<cantidadRegistros;i++) {

        reg = ArchiP.leerRegistrosID(i);

        if(reg.getEstado()==true) {
            p[j] = reg;
            j++;
        }

    }



    ordenar(p,tamanioArray,opcion);



    for(int i=0;i<tamanioArray;i++) {



        p[i].mostrar();

        cout<<endl;
    }






   delete []p;


}


      void Listados::ordenadoNombre() {

        ordenGeneralProductos(1);

        }

        void Listados::ordenadoMarca() {

            ordenGeneralProductos(2);

        }
        void Listados::ordenadoProveedor() {
            ordenGeneralProductos(3);


        }

        void Listados::ordenadoStock() {
            ordenGeneralProductos(4);
        }

        void Listados::ordenadoPrecio() {
            ordenGeneralProductos(5);
        }

        ///////////////////////////////////////////////////
void ordenarProveedores(Proveedor *p, int tam, int opcion) {
    int i, j, posmin;
    Proveedor auxi;

    for (i = 0; i < tam - 1; i++) {
        posmin = i;  // Inicializa la posición del mínimo en cada paso del ciclo exterior
        for (j = i + 1; j < tam; j++) {

            // Dependiendo de la opción, comparamos por nombre, marca o proveedor
            if (opcion == 1) {  // Comparar por nombre
                if (strcmp(p[j].getNombre(), p[posmin].getNombre()) < 0) {
                    posmin = j;
                }
            }
            else if (opcion == 2) {
                if(p[j].getCantidadProductos() < p[posmin].getCantidadProductos()) {
                    posmin = j;
                }
            }
        }

        // Intercambiar si es necesario (cuando posmin ha cambiado)
        if (posmin != i) {
            auxi = p[i];
            p[i] = p[posmin];
            p[posmin] = auxi;
        }
    }
}

void Listados::ordenGeneralProveedor(int opcion) {

archivoProveedor ArchiP;

    Proveedor reg;

    Proveedor *p;

    int contadorBajas =0;

    int cantidadRegistros = ArchiP.cantidadRegistros();  /// CANTIDAD TOTAL DE REGISTROS EN ARCHIVO

    for(int i=0;i<cantidadRegistros;i++) {

        reg = ArchiP.leerRegistrosID(i);

        if(reg.getEstado()==false) {
            contadorBajas++;
        }
    }

    int tamanioArray = cantidadRegistros - contadorBajas; /// CANTIDAD REAL DE REGISTROS EN ARCHIVO (SIN ESTAR DE BAJA)

    if(cantidadRegistros==0) {
            cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
        return;
    }

    p = new Proveedor[tamanioArray];  /// LO CREO DEL TAMAÑO REAL

    if(p==NULL) {
        cout<<"NO SE PUDO ASIGNAR MEMORIA"<<endl;
        return;
    }

    int j = 0; /// INDICE AUXILIAR PARA EVITAR VACIOS

    for(int i=0;i<cantidadRegistros;i++) {

        reg = ArchiP.leerRegistrosID(i);

        if(reg.getEstado()==true) {
            p[j] = reg;
            j++;
        }

    }
    ordenarProveedores(p,tamanioArray,opcion);

    for(int i=0;i<tamanioArray;i++) {

        p[i].mostrar();

        cout<<endl;
    }

   delete []p;

}

void Listados::ordenadoNombreProveedor() {

        ordenGeneralProveedor(1);

}


void Listados::ordenadoCantidad() {

            ordenGeneralProveedor(2);

}
