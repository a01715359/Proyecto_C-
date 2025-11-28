#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>   
#include "Electronico.h"

class Laptop: public Electronico{
    private:
        std::string procesador;
        int ram;

    public:
        Laptop(): Electronico(), procesador(""), ram(0){};
        Laptop(std::string nom, float pre, std::string mar, std::string pro, float tam, int r, std::string cond, int cant): Electronico(nom, pre, mar, tam, cond, cant), procesador(pro), ram(r){}

    std::string getProcesador();
    int getRam();

    void mostrar_info();

};

        std::string Laptop::getProcesador(){
            return procesador;
        }

        int Laptop::getRam(){
            return ram;
        }

        void Laptop::mostrar_info(){
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nProcesador: " << procesador
                      << "\nTamaño: " << tamano << " pulgadas"
                      << "\nRAM: " << ram << " GB"
                      << "\nCondición: " << condicion
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock() 
                      << "\n\n";
        }

#endif
