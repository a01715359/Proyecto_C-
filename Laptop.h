#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <string>   
#include "Electronico.h"
#include <sstream>

class Laptop: public Electronico{
    private:
        std::string procesador;
        int ram;

    public:
        Laptop(): 
            Electronico(), procesador(""), ram(0){};
        Laptop(std::string nom, float pre, std::string mar, std::string pro, float tam, int r, std::string cond, int cant): 
            Electronico(nom, pre, mar, tam, cond, cant), procesador(pro), ram(r){}

    std::string getProcesador();
    int getRam();

    std::string mostrarInfo();

};

std::string Laptop::getProcesador(){
return procesador;
}

int Laptop::getRam(){
return ram;
}

std::string Laptop::mostrarInfo(){
std::stringstream info;
info << "Nombre: " << nombre << std::endl;
info << "Precio: $" << precio << std::endl;
info << "Marca: " << marca << std::endl;
info << "Procesador: " << procesador << std::endl;
info << "Size: " << tamano << " pulgadas" << std::endl;
info << "RAM: " << ram << " GB" << std::endl;
info << "Condicion: " << condicion << std::endl;
info << "Cantidad disponible: " << cantidadDisponible << std::endl;
info << "Valor total en stock: $" << calcularValorStock() << std::endl;
    return info.str();
}
#endif
