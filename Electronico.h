#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <iostream>
#include <sstream>
#include <string>

class Electronico {
   protected:
    std::string nombre;
    float precio;
    std::string marca;
    float tamano;
    std::string condicion;
    int cantidadDisponible;

   public:
    Electronico()
        : nombre(""),
          precio(0.0),
          marca(""),
          tamano(0.0),
          condicion(""),
          cantidadDisponible(0) {};
    Electronico(std::string nom, float pre, std::string mar, float tam,
                std::string cond, int cant)
        : nombre(nom),
          precio(pre),
          marca(mar),
          tamano(tam),
          condicion(cond),
          cantidadDisponible(cant) {}

    std::string getNombre();
    float getPrecio();
    std::string getMarca();
    float getTamano();
    std::string getCondicion();
    int getCantidadDisponible();

    void setPrecio(float);
    void setCondicion(std::string);
    void setCantidadDisponible(int);

    float calcularValorStock();
    std::string mostrarInfo();
};

std::string Electronico::getNombre() {
    return nombre;
}

float Electronico::getPrecio() {
    return precio;
}

std::string Electronico::getMarca() {
    return marca;
}

float Electronico::getTamano() {
    return tamano;
}
std::string Electronico::getCondicion() {
    return condicion;
}
int Electronico::getCantidadDisponible() {
    return cantidadDisponible;
}
void Electronico::setPrecio(float pre) {
    precio = pre;
}
void Electronico::setCondicion(std::string cond) {
    condicion = cond;
}
void Electronico::setCantidadDisponible(int cant) {
    cantidadDisponible = cant;
}
float Electronico::calcularValorStock() {
    return precio * cantidadDisponible;
}
std::string Electronico::mostrarInfo() {
    std::stringstream info;
    info << "Nombre: " << nombre << std::endl;
    info << "Precio: $" << precio << std::endl;
    info << "Marca: " << marca << std::endl;
    info << "Size: " << tamano << " pulgadas" << std::endl;
    info << "Condicion: " << condicion << std::endl;
    info << "Cantidad disponible: " << cantidadDisponible << std::endl;
    info << "Valor total del stock: $" << calcularValorStock() << std::endl;
    return info.str();
}

#endif
