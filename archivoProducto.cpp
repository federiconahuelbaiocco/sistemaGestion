#include<iostream>
  #include<cstdlib>
  #include<cstring>
 using namespace std;

 #include <cctype>
#include <limits>

#include "Producto.h"
#include "archivoProducto.h"




const bool ACTIVOS=true;
const bool TODOS=false;


archivoProducto::archivoProducto(const char *_n,int _tamanioRegistro)

{
    strcpy(nombreArchivo,_n);
    tamanioRegistro=_tamanioRegistro;
}

archivoProducto::~archivoProducto()
{
    //dtor
}

bool archivoProducto::GrabarRegistro(Producto &reg) {
    FILE *pProducto; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO

    pProducto = fopen(nombreArchivo,"ab");
    if (pProducto == NULL) {   /// VERIFICO APERTURA
        return false;
    }

    int escribio = fwrite(&reg,tamanioRegistro,1,pProducto); /// DEVUELVE EL NUMERO DE REGISTROS QUE GRABO, EN ESTE CASO 1
    fclose(pProducto);  /// SIEMPRE CIERRO EL ARCHIVO

    return escribio;
 }

 bool archivoProducto::ListarRegistros() {
    Producto reg;
    FILE *pProducto; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO



    pProducto = fopen(nombreArchivo,"rb");
    if (pProducto == NULL) {   /// VERIFICO APERTURA
        return false;
    }
    while(fread(&reg,tamanioRegistro,1,pProducto)==1) {
        reg.mostrar();
        cout<<endl;

    }
    fclose(pProducto);  /// SIEMPRE CIERRO EL ARCHIVO

    return true;
 }

  int archivoProducto::cantidadRegistros() {
        FILE *pProducto; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO

        pProducto = fopen(nombreArchivo,"rb");
        if (pProducto == NULL) {   /// VERIFICO APERTURA
            return -1;
        }
       fseek(pProducto,0,2);
       int cantBytes = ftell(pProducto);
        fclose(pProducto);  /// SIEMPRE CIERRO EL ARCHIVO

        return cantBytes/sizeof(Producto);
 }

 Producto archivoProducto::leerRegistrosID(int posReg) {
        Producto reg;
        FILE *pProducto; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO
        reg.setID(-1);

        pProducto = fopen(nombreArchivo,"rb");
        if (pProducto == NULL) {   /// VERIFICO APERTURA
            return reg;
        }
        fseek(pProducto,sizeof(Producto)*posReg,0);
        fread(&reg,sizeof(Producto),1,pProducto);


        fclose(pProducto);  /// SIEMPRE CIERRO EL ARCHIVO

        return reg;
 }



 int archivoProducto::buscarRegistro(int id, bool queHago){

        FILE *pProducto;
        Producto reg;
        int pos=0;
        pProducto= fopen(nombreArchivo, "rb");
        if(pProducto==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        if(queHago==true){
           while(fread(&reg,tamanioRegistro,1,pProducto)==1){
                if(reg.getID()==id &&reg.getEstado()){
                fclose(pProducto);
                return pos;
                }
            pos++;
            }
        fclose(pProducto);
        return -1;
        }
        else{
           while(fread(&reg,tamanioRegistro,1,pProducto)==1){
                if(reg.getID()==id){
                fclose(pProducto);
                return pos;
                }
            pos++;
            }
        fclose(pProducto);
        return -1;
        }
    }

    bool archivoProducto::modificarRegistro(Producto reg,int pos) {

        FILE *pProducto; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO


        pProducto = fopen(nombreArchivo,"rb+");
        if (pProducto == NULL) {   /// VERIFICO APERTURA
            return false;
        }
        fseek(pProducto,sizeof(Producto)*pos,0);
        bool escribio = fwrite(&reg,sizeof(Producto),1,pProducto);


        fclose(pProducto);  /// SIEMPRE CIERRO EL ARCHIVO

        return escribio;
    }


    bool archivoProducto::bajaRegistro() {
    Producto reg;
    archivoProducto archiP;

    int id;

    cout<<"INGRESE EL ID DEL PRODUCTO A DAR DE BAJA"<<endl;
    cin>>id;

    int pos = archiP.buscarRegistro(id,TODOS);
    if(pos==-1) {

        cout<<"NO HAY PRODUCTOS CON ESE ID"<<endl;
        return false;
    }


    reg = archiP.leerRegistrosID(pos);

    if(reg.getEstado()==false) {
        cout<<"EL REGISTRO YA ESTA DE BAJA"<<endl;
        return true;
    } else {
        reg.setEstado(false);
        if(archiP.modificarRegistro(reg,pos)) {
        cout<<"SE DIO DE BAJA EL REGISTRO"<<endl;
        return true;
    }
    }

    return false;

}

bool archivoProducto::altaRegistro() {
    Producto reg;
    archivoProducto archiP;

    int id;

    cout<<"INGRESE EL ID DEL PRODUCTO A DAR DE ALTA"<<endl;
    cin>>id;

    int pos = archiP.buscarRegistro(id,TODOS);
    if(pos==-1) {

        cout<<"NO HAY PRODUCTOS CON ESE ID"<<endl;
        return false;
    }


    reg = archiP.leerRegistrosID(pos);

    if(reg.getEstado()==true) {
        cout<<"EL REGISTRO YA ESTA DE ALTA"<<endl;
        return true;
    } else {
        reg.setEstado(true);
        if(archiP.modificarRegistro(reg,pos)) {
        cout<<"SE DIO DE ALTA EL REGISTRO"<<endl;
        return true;
    }
    }

    return false;

}

bool archivoProducto::modificacionRegistro() {

    Producto reg;
    archivoProducto archiP;

    int id;
    int opc;
    float precioCompra,precioVenta;
    int stock;
    char proveedor[20];
    bool modificar = true;


    cout<<"INGRESE EL ID DEL PRODUCTO A MODIFICAR"<<endl;
    cin>>id;



    int pos = archiP.buscarRegistro(id,TODOS);
    if(pos==-1) {

        cout<<"NO HAY PRODUCTOS CON ESE ID"<<endl;
        return false;
    }



    reg = archiP.leerRegistrosID(pos);

     if(reg.getEstado()==false) {

        cout<<"EL REGISTRO ESTA DADO DE BAJA, NO PUEDE MODIFICARSE"<<endl;
        return false;
    }


        while(modificar) {
         cout<<"ID SELECCIONADO: ";
         cout<<reg.getID()<<endl;
        cout<<"QUE DESEA MODIFICAR?"<<endl;
        cout<<"1.PRECIO COMPRA"<<endl;
        cout<<"2.PRECIO VENTA"<<endl;
        cout<<"3 STOCK"<<endl;
        cout<<"4. PROVEEDOR"<<endl;
        cout<<"0. TERMINAR MODIFICACIONES"<<endl;
        cin>>opc;
        cin.ignore();

        switch(opc) {
            case 1:cout<<"INGRESE NUEVO PRECIO COMPRA"<<endl;
                    precioCompra = solicitarPrecio();
                    reg.setPrecioCompra(precioCompra);
                    if (archiP.modificarRegistro(reg,pos)) {
                       cout<<"PRECIO COMPRA MODIFICACO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }

                    system("pause");
                    system("cls");
                break;

            case 2:
                cout<<"INGRESE NUEVO PRECIO VENTA"<<endl;
                    precioVenta = solicitarPrecio();
                    reg.setPrecioVenta(precioVenta);
                     if (archiP.modificarRegistro(reg,pos)) {
                       cout<<"PRECIO VENTA MODIFICADO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    system("pause");
                    system("cls");

                break;
            case 3: cout<<"INGRESE STOCK"<<endl;
                    stock = solicitarStock();
                    reg.setStock(stock);
                     if (archiP.modificarRegistro(reg,pos)) {
                       cout<<"STOCK MODIFICADO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    system("pause");
                    system("cls");
                break;
            case 4: cout<<"INGRESE NUEVO PROVEEDOR"<<endl;
                    cin.getline(proveedor,20);
                    mayusculas(proveedor);
                    reg.setProveedor(proveedor);
                    if(archiP.modificarRegistro(reg,pos)) {
                      cout<<"STOCK MODIFICADO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    system("pause");
                    system("cls");
                    break;

            case 0: modificar=false;
                    break;

            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                    system("cls");
        }

        }

    }

