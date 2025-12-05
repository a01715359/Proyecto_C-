#ifndef TELEVISOR_H
#define TELEVISOR_H

#include <iostream>
#include <sstream>
#include <string>

#include "Electronico.h"

/*
 * Clase Televisor
 * Representa un producto electrónico del tipo televisor, heredando de la clase Electronico.
 *
 * Agrega atributos específicos de un televisor, como tipo de pantalla y si es Smart TV.
 * Permite obtener información detallada del producto y mostrarla de manera legible.
 */

class Televisor : public Electronico {
   private:
    std::string tipoPantalla;   // Tipo de pantalla del televisor (LED, OLED, LCD, etc.)
    std::string smartTV;        // Indica si el televisor es Smart TV ("Sí"/"No")

   public:
    /**
     * Constructor por default.
     *
     * Inicializa todos los atributos heredados y propios con valores vacíos o por defecto.
     *
     * @param
     * @return Objeto Televisor con valores por defecto.
     */
    Televisor() : Electronico(), tipoPantalla(""), smartTV("No") {}

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Televisor con valores específicos.
     *
     * @param nom Nombre del televisor.
     * @param pre Precio unitario.
     * @param mar Marca del televisor.
     * @param pan Tipo de pantalla (LED, OLED, LCD, etc.).
     * @param tam Tamaño en pulgadas.
     * @param tv Indica si es Smart TV ("Sí"/"No").
     * @param cond Condición del producto.
     * @param cant Cantidad disponible en inventario.
     * @return Objeto Televisor con valores asignados.
     */
    Televisor(std::string nom, float pre, std::string mar, std::string pan,
              float tam, std::string tv, std::string cond, int cant)
        : Electronico(nom, pre, mar, tam, cond, cant),
          tipoPantalla(pan),
          smartTV(tv) {}

    // Métodos getter

    /**
     * Obtiene el tipo de pantalla del televisor.
     *
     * @param
     * @return Tipo de pantalla.
     */
    std::string getTipoPantalla();

    /**
     * Indica si el televisor es Smart TV.
     *
     * @param
     * @return "Sí" si es Smart TV, "No" en caso contrario.
     */
    std::string getSmartTV();

    /**
     * Genera una cadena con toda la información del televisor.
     *
     * Incluye atributos heredados y propios, además del valor total del stock.
     *
     * @param
     * @return Cadena con información detallada del televisor.
     */
    std::string mostrarInfo();
};

// Implementaciones de los métodos

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
