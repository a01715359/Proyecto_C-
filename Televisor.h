#ifndef TELEVISOR_H
#define TELEVISOR_H

#include <iostream>
#include <string>
#include "Electronico.h"

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

        void mostrar_info() const;
};

        std::string Televisor::getTipo_pantalla(){
            return tipo_pantalla;
        }

        std::string Televisor::getSmartTV(){
            return smartTV;
        }

        void Televisor::mostrar_info() const {
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nTipo de pantalla: " << tipo_pantalla
                      << "\nTamaño: " << tamano << " pulgadas"
                      << "\nEs Smart TV: " << smartTV
                      << "\nCondición: " << condicion
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock()
                      << "\n\n";
        }

#endif
