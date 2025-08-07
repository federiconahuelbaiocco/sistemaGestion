#include<iostream>
  #include<cstdlib>
  #include<cstring>
 using namespace std;

 #include <cctype>
#include <limits>

#include "Persona.h"
#include "archivoProveedor.h"




const bool ACTIVOS=true;
const bool TODOS=false;


archivoProveedor::archivoProveedor(const char *_n,int _tamanioRegistro)

{
    strcpy(nombreArchivo,_n);
    tamanioRegistro=_tamanioRegistro;
}

archivoProveedor::~archivoProveedor()
{
    //dtor
}

bool archivoProveedor::GrabarRegistro(Proveedor &reg) {
    FILE *pProveedor; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO

    pProveedor = fopen(nombreArchivo,"ab");
    if (pProveedor == NULL) {   /// VERIFICO APERTURA
        return false;
    }

    int escribio = fwrite(&reg,tamanioRegistro,1,pProveedor); /// DEVUELVE EL NUMERO DE REGISTROS QUE GRABO, EN ESTE CASO 1
    fclose(pProveedor);  /// SIEMPRE CIERRO EL ARCHIVO

    return escribio;
 }

 bool archivoProveedor::ListarRegistros() {
    Proveedor reg;
    FILE *pProveedor; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO



    pProveedor = fopen(nombreArchivo,"rb");
    if (pProveedor == NULL) {   /// VERIFICO APERTURA
        return false;
    }
    while(fread(&reg,tamanioRegistro,1,pProveedor)==1) {
        reg.mostrar();
        cout<<endl;

    }
    fclose(pProveedor);  /// SIEMPRE CIERRO EL ARCHIVO

    return true;
 }

  int archivoProveedor::cantidadRegistros() {
        FILE *pProveedor; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO

        pProveedor = fopen(nombreArchivo,"rb");
        if (pProveedor == NULL) {   /// VERIFICO APERTURA
            return -1;
        }
       fseek(pProveedor,0,2);
       int cantBytes = ftell(pProveedor);
        fclose(pProveedor);  /// SIEMPRE CIERRO EL ARCHIVO

        return cantBytes/sizeof(Proveedor);
 }

 Proveedor archivoProveedor::leerRegistrosID(int posReg) {
        Proveedor reg;
        FILE *pProveedor; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO
        reg.setID(-1);

        pProveedor = fopen(nombreArchivo,"rb");
        if (pProveedor == NULL) {   /// VERIFICO APERTURA
            return reg;
        }
        fseek(pProveedor,sizeof(Proveedor)*posReg,0);
        fread(&reg,sizeof(Proveedor),1,pProveedor);


        fclose(pProveedor);  /// SIEMPRE CIERRO EL ARCHIVO

        return reg;
 }



 int archivoProveedor::buscarRegistro(int id, bool queHago){

        FILE *pProveedor;
        Proveedor reg;
        int pos=0;
        pProveedor= fopen(nombreArchivo, "rb");
        if(pProveedor==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        if(queHago==true){
           while(fread(&reg,tamanioRegistro,1,pProveedor)==1){
                if(reg.getID()==id &&reg.getEstado()){
                fclose(pProveedor);
                return pos;
                }
            pos++;
            }
        fclose(pProveedor);
        return -1;
        }
        else{
           while(fread(&reg,tamanioRegistro,1,pProveedor)==1){
                if(reg.getID()==id){
                fclose(pProveedor);
                return pos;
                }
            pos++;
            }
        fclose(pProveedor);
        return -1;
        }
    }

    bool archivoProveedor::modificarRegistro(Proveedor reg,int pos) {

        FILE *pProveedor; /// ESTABLECE CONEXION CON EL ARCHIVO FISICO


        pProveedor = fopen(nombreArchivo,"rb+");
        if (pProveedor == NULL) {   /// VERIFICO APERTURA
            return false;
        }
        fseek(pProveedor,sizeof(Proveedor)*pos,0);
        bool escribio = fwrite(&reg,sizeof(Proveedor),1,pProveedor);


        fclose(pProveedor);  /// SIEMPRE CIERRO EL ARCHIVO

        return escribio;
    }


    bool archivoProveedor::bajaRegistro() {
    Proveedor reg;
    archivoProveedor archiP;

    int id;

    cout<<"INGRESE EL ID DEL PROVEEDOR A DAR DE BAJA"<<endl;
    cin>>id;

    int pos = archiP.buscarRegistro(id,TODOS);
    if(pos==-1) {

        cout<<"NO HAY PROVEEDOR CON ESE ID"<<endl;
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

bool archivoProveedor::altaRegistro() {
    Proveedor reg;
    archivoProveedor archiP;

    int id;

    cout<<"INGRESE EL ID DEL PROVEEDOR A DAR DE ALTA"<<endl;
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

bool archivoProveedor::modificacionRegistro() {

    Proveedor reg;
    archivoProveedor archiP;

    int opc;
    int id;
    char proveedor[20];
    char telefono[11];
    int prodRel;
    bool modificar = true;


    cout<<"INGRESE EL ID DEL PROVEEDOR A MODIFICAR"<<endl;
    cin>>id;

    int pos = archiP.buscarRegistro(id,TODOS);
    if(pos==-1) {

        cout<<"NO HAY PROVEEDORES CON ESE ID"<<endl;
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
        cout<<"1.NOMBRE"<<endl;
        cout<<"2.CANTIDAD PRODUCTOS"<<endl;
        cout<<"3.TELEFONO"<<endl;
        cin>>opc;
        cin.ignore();

        switch(opc) {
            case 1:cout<<"INGRESE NOMBRE"<<endl;
                    cin.getline(proveedor,20);
                    mayusculas(proveedor);
                    reg.setNombre(proveedor);
                    if(archiP.modificarRegistro(reg,pos)) {
                      cout<<"NOMBRE MODIFICADO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    break;

            case 2:
                cout<<"INGRESE CANTIDAD PRODUCTOS RELACIONADOS"<<endl;
                    cin >> prodRel;
                    reg.setCantidadProductos(prodRel);
                    if(archiP.modificarRegistro(reg,pos)) {
                      cout<<"CANTIDAD CON EXITO" <<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    break;
            case 3:
                cout<<"INGRESE TELEFONO"<<endl;
                    cin.getline(telefono,11);
                    reg.setTelefono(telefono);
                    if(archiP.modificarRegistro(reg,pos)) {
                      cout<<"TELEFONO MODIFICADO CON EXITO"<<endl;
                    } else {
                        cout<<"NO SE PUDO MODIFICAR"<<endl;
                    }
                    break;
            case 0: modificar=false;
                    break;

            default: cout<<"OPCION INCORRECTA"<<endl;
                    system("pause");
                    system("cls");
        }

        }

    }

