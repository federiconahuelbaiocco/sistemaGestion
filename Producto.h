#ifndef PRODUCTO_H
#define PRODUCTO_H


void mayusculas(char* cad);

float solicitarPrecio();
int solicitarStock();



class Producto
{
    public:
        Producto();
         ~Producto();
          void cargar();
          void mostrar();
          int getID();
          const char* getName () const;
          char* getMarca();
          char* getProveedor();
          float getPrecioCompra();
          float getPrecioVenta();
          int getStock();
          bool getEstado();
          void setID(int _id);
          void setName(char _nombre[] );
          void setMarca(char _marca[] );
          void setProveedor(char[]);
          void setPrecioCompra(float _precioCompra);
          void setPrecioVenta(float _precioVenta);
          void setStock(int _stock);
          float calcularGanancia();
          void setEstado(bool _estado);
          bool operator<(const Producto& otro) const;


    protected:

    private:
        int id;
        char nombre[20];
        char marca[20];
        char proveedor[20];
        float precioCompra;
        float precioVenta;
        int stock;
        bool estado;
};









#endif // PRODUCTO_H
