#ifndef LAPTOP_H
#define LAPTOP_H

#include <iostream>
#include <sstream>
#include <string>

#include "Electronico.h"

/*
 * Clase Laptop
 * Representa un producto electrónico del tipo laptop, heredando de la clase Electronico.
 *
 * Agrega atributos específicos de una laptop, como procesador y memoria RAM.
 * Permite obtener información detallada del producto y mostrarla de manera legible.
 */

class Laptop : public Electronico {
   private:
    std::string procesador;   // Tipo de procesador de la laptop
    int ram;                  // Memoria RAM en GB

   public:
    /**
     * Constructor por default.
     *
     * Inicializa todos los atributos heredados y propios con valores vacíos o cero.
     *
     * @param
     * @return Objeto Laptop con valores por defecto.
     */
    Laptop() : Electronico(), procesador(""), ram(0) {};

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Laptop con valores específicos.
     *
     * @param nom Nombre de la laptop.
     * @param pre Precio unitario.
     * @param mar Marca de la laptop.
     * @param pro Tipo de procesador.
     * @param tam Tamaño en pulgadas.
     * @param r Memoria RAM en GB.
     * @param cond Condición del producto.
     * @param cant Cantidad disponible en inventario.
     * @return Objeto Laptop con valores asignados.
     */
    Laptop(std::string nom, float pre, std::string mar, std::string pro,
           float tam, int r, std::string cond, int cant)
        : Electronico(nom, pre, mar, tam, cond, cant),
          procesador(pro),
          ram(r) {}

    // Métodos getter

    /**
     * Obtiene el tipo de procesador de la laptop.
     *
     * @param
     * @return Procesador.
     */
    std::string getProcesador();

    /**
     * Obtiene la memoria RAM de la laptop en GB.
     *
     * @param
     * @return Memoria RAM en GB.
     */
    int getRam();

    /**
     * Genera una cadena con toda la información de la laptop.
     *
     * Incluye atributos heredados y propios, además del valor total del stock.
     *
     * @param
     * @return Cadena con información detallada de la laptop.
     */
    std::string mostrarInfo();
};

// Implementaciones de los métodos

std::string Laptop::getProcesador() {
    return procesador;
}

int Laptop::getRam() {
    return ram;
}

std::string Laptop::mostrarInfo() {
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
