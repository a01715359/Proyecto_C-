/*
 * Proyecto TecMarket
 * Rashell Aleck Jiménez Almánzar
 * A01715359
 * 04/12/2025
 */

/*
 * Clase Smartphone
 * Representa un teléfono inteligente con atributos adicionales
 * como memoria y una tarjeta SIM.
 *
 * Hereda de la clase Electronico y permite consultar y modificar
 * sus atributos, incluyendo la información de la SIM.
 */

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include <sstream>
#include <string>

#include "Electronico.h"
#include "Sim.h"

class Smartphone : public Electronico {
   private:
    int memoria;  ///< Capacidad de almacenamiento en GB
    Sim sim;      ///< Objeto Sim asociado al smartphone

   public:
    /**
     * Constructor por defecto.
     *
     * Inicializa todos los atributos con valores vacíos o cero,
     * y crea una SIM por defecto.
     *
     * @param
     * @return Objeto Smartphone inicializado con valores por defecto.
     */
    Smartphone() : Electronico(), memoria(0), sim() {};

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Smartphone con valores específicos.
     *
     * @param nom Nombre del smartphone.
     * @param pre Precio del smartphone.
     * @param mar Marca del smartphone.
     * @param mem Memoria en GB.
     * @param tam Tamaño en pulgadas.
     * @param cond Condición del smartphone (nuevo, usado, etc.).
     * @param cant Cantidad disponible en inventario.
     * @param numSim Número de la SIM.
     * @param operSim Operador de la SIM.
     * @param tipSim Tipo de SIM.
     * @param actSim Estado de activación de la SIM.
     * @return Objeto Smartphone con valores asignados.
     */
    Smartphone(std::string nom, float pre, std::string mar, int mem,
               float tam, std::string cond, int cant, std::string numSim,
               std::string operSim, std::string tipSim, bool actSim)
        : Electronico(nom, pre, mar, tam, cond, cant),
          memoria(mem),
          sim(numSim, operSim, tipSim, actSim) {}

    // Métodos getter

    /**
     * Obtiene la memoria del smartphone en GB.
     *
     * @param
     * @return Memoria en GB.
     */
    int getMemoria();

    /**
     * Obtiene la SIM asociada al smartphone.
     *
     * @param
     * @return Objeto Sim.
     */
    Sim getSim();

    /**
     * Genera una cadena con toda la información del smartphone.
     *
     * Incluye nombre, precio, marca, memoria, información de la SIM,
     * condición, tamaño, cantidad disponible y valor total en stock.
     *
     * @param
     * @return Cadena con información detallada del smartphone.
     */
    std::string mostrarInfo();
};

// Implementación de los métodos

int Smartphone::getMemoria() {
    return memoria;
}

Sim Smartphone::getSim() {
    return sim;
}

std::string Smartphone::mostrarInfo() {
    std::stringstream info;
    info << "Nombre: " << getNombre() << std::endl;
    info << "Precio: $" << getPrecio() << std::endl;
    info << "Marca: " << getMarca() << std::endl;
    info << "Memoria: " << getMemoria() << " GB" << std::endl;
    info << "SIM: \n" << getSim().mostrarInfo();
    info << "Condicion: " << getCondicion() << std::endl;
    info << "Size: " << getTamano() << " pulgadas" << std::endl;
    info << "Cantidad disponible: " << getCantidadDisponible() << std::endl;
    info << "Valor total en stock: $" << calcularValorStock() << std::endl;
    return info.str();
}

#endif
