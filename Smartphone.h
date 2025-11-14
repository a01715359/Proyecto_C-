#include <iostream>
#include <string>

class Smartphone{

    private:
        std::string nombre;
        float precio;
        std:: string marca;
        int memoria;
        float tamano;
        std:: string condicion;
        int cantidad_disponible;

    public:
    Smartphone(): nombre(""), precio(0.0), marca(""), memoria(0), tamano(0), condicion(""), cantidad_disponible(0){};
    Smartphone(std::string nom, float pre, std:: string mar, int mem, float tam, std:: string cond, int cant = 0): 
    nombre(nom), precio(pre), marca(mar), memoria(mem), tamano(tam), condicion(cond), cantidad_disponible(cant){}

        std::string getNombre();
        float getPrecio();
        int getMemoria();
        std:: string getMarca();
        float getTamano();
        std:: string getCondicion();
        int getCantidad_disponible();

        void setPrecio(float );
        void setCondicion(std::string );
        void setCantidad_disponible(int );

        void mostrar_info();
        float calcular_valor_stock();
};

        std::string Smartphone::getNombre(){
            return nombre;
        }

        float Smartphone::getPrecio(){
            return precio;
        }

        std:: string Smartphone::getMarca(){
            return marca;
        }

        int Smartphone::getMemoria(){
            return memoria;
        }

        std:: string Smartphone::getCondicion(){
            return condicion;
        }

        int Smartphone::getCantidad_disponible(){
            return cantidad_disponible;
        }

        void Smartphone::setPrecio(float pre){
            precio = pre;
        }

        void Smartphone::setCondicion(std::string cond){
            condicion = cond;
        }

        void Smartphone::setCantidad_disponible(int cant){
            cantidad_disponible = cant;
        }

        float Smartphone::calcular_valor_stock(){
            return precio * cantidad_disponible;
        }
        void Smartphone::mostrar_info(){
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nMemoria: " << memoria << " GB"
                      << "\nCondición: " << condicion
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock()
                      << "\n\n";
        }
