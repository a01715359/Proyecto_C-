#ifndef TELEVISOR_H
#define TELEVISOR_H

#include <iostream>
#include <string>
#include "Electronico.h"
#include <sstream>
#include <limits>

class Televisor: public Electronico{
    private:
        std::string tipo_pantalla;
        std::string smartTV;

    public:
        Televisor(): Electronico(), tipo_pantalla(""), smartTV("No"){}
        Televisor(std::string nom, float pre, std::string mar, std::string pan, float tam, std::string tv, std::string cond, int cant)
        : Electronico(nom, pre, mar, tam, cond, cant), tipo_pantalla(pan), smartTV(tv) {}

        std::string getTipo_pantalla();
        std::string getSmartTV();
        std::string mostrar_info();
};

        std::string Televisor::getTipo_pantalla(){
            return tipo_pantalla;
        }

        std::string Televisor::getSmartTV(){
            return smartTV;
        }

        std::string Televisor::mostrar_info(){
            std::stringstream info;
            info << "Nombre: " << nombre << std::endl;
            info << "Precio: $" << precio << std::endl;
            info << "Marca: " << marca << std::endl;
            info << "Tipo de pantalla: " << tipo_pantalla << std::endl;
            info << "Tamaño: " << tamano << " pulgadas" << std::endl;
            info << "Es Smart TV: " << smartTV << std::endl;
            info << "Condición: " << condicion << std::endl;
            info << "Cantidad disponible: " << cantidad_disponible << std::endl;
            info << "Valor total en stock: $" << calcular_valor_stock() << std::endl;
            return info.str();
        }
#endif
