#ifndef TELEVISOR_H
#define TELEVISOR_H

#include <iostream>
#include <sstream>
#include <string>

#include "Electronico.h"

class Televisor : public Electronico {
   private:
    std::string tipoPantalla;
    std::string smartTV;

   public:
    Televisor() : Electronico(), tipoPantalla(""), smartTV("No") {}
    Televisor(std::string nom, float pre, std::string mar, std::string pan,
              float tam, std::string tv, std::string cond, int cant)
        : Electronico(nom, pre, mar, tam, cond, cant),
          tipoPantalla(pan),
          smartTV(tv) {}

    std::string getTipoPantalla();
    std::string getSmartTV();
    std::string mostrarInfo();
};

std::string Televisor::getTipoPantalla() {
    return tipoPantalla;
}

std::string Televisor::getSmartTV() {
    return smartTV;
}

std::string Televisor::mostrarInfo() {
    std::stringstream info;
    info << "Nombre: " << nombre << std::endl;
    info << "Precio: $" << precio << std::endl;
    info << "Marca: " << marca << std::endl;
    info << "Tipo de pantalla: " << tipoPantalla << std::endl;
    info << "Size: " << tamano << " pulgadas" << std::endl;
    info << "Es Smart TV: " << smartTV << std::endl;
    info << "Condicion: " << condicion << std::endl;
    info << "Cantidad disponible: " << cantidadDisponible << std::endl;
    info << "Valor total en stock: $" << calcularValorStock() << std::endl;
    return info.str();
}
#endif
