#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <iostream>
#include <string>

class Electronico{
    protected:
        std::string nombre;
        float precio;
        std::string marca;
        float tamano;
        std::string condicion;
        int cantidad_disponible;

    public:
        Electronico(): nombre(""), precio(0.0), marca(""), tamano(0.0), condicion(""), cantidad_disponible(0){};
        Electronico(std::string nom, float pre, std::string mar, float tam, std::string cond, int cant): 
        nombre(nom), precio(pre), marca(mar), tamano(tam), condicion(cond), cantidad_disponible(cant){}
        
        std::string getNombre();
        float getPrecio();
        std::string getMarca();
        float getTamano();
        std::string getCondicion();
        int getCantidad_disponible();

        void setPrecio(float);
        void setCondicion(std::string);
        void setCantidad_disponible(int);

    float calcular_valor_stock();
    void mostrar_info();
};

        std::string Electronico::getNombre(){
            return nombre;
        }

        float Electronico::getPrecio(){
            return precio;
        }

        std::string Electronico::getMarca(){
            return marca;
        }

        float Electronico::getTamano(){
            return tamano;
        }
        std::string Electronico::getCondicion(){
            return condicion;
        }
        int Electronico::getCantidad_disponible(){
            return cantidad_disponible;
        }
        void Electronico::setPrecio(float pre){
            precio = pre;
        }
        void Electronico::setCondicion(std::string cond){
            condicion = cond;
        }
        void Electronico::setCantidad_disponible(int cant){
            cantidad_disponible = cant;
        }
        float Electronico::calcular_valor_stock(){
            return precio * cantidad_disponible;
        }
        void Electronico::mostrar_info(){
            std::cout << "Nombre: " << nombre << std::endl;
            std::cout << "Precio: $" << precio << std::endl;
            std::cout << "Marca: " << marca << std::endl;
            std::cout << "Tamaño: " << tamano << " pulgadas" << std::endl;
            std::cout << "Condición: " << condicion << std::endl;
            std::cout << "Cantidad disponible: " << cantidad_disponible << std::endl;
            std::cout << "Valor total del stock: $" << calcular_valor_stock() << std::endl;
        }

#endif
