#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <iostream>
#include <sstream>
#include <string>

/*
 * Clase Electronico
 * Representa un producto electrónico con atributos esenciales como
 * nombre, precio, marca, tamaño, condición y cantidad disponible.
 *
 * Permite la consulta y modificación de atributos, así como el cálculo
 * del valor total del stock y la generación de información detallada
 * del producto.
 */

class Electronico {
   protected:
    std::string nombre;              // Nombre del producto electrónico
    float precio;                    // Precio unitario del producto
    std::string marca;               // Marca del producto
    float tamano;                    // Tamaño físico en pulgadas
    std::string condicion;           // Condición física o de uso del producto
    int cantidadDisponible;          // Cantidad disponible en inventario

   public:
    /**
     * Constructor por default.
     *
     * Inicializa todos los atributos con valores vacíos o cero,
     * creando un objeto Electronico con datos no definidos.
     *
     * @param
     * @return Objeto Electronico inicializado con valores por defecto.
     */
    Electronico()
        : nombre(""),
          precio(0.0),
          marca(""),
          tamano(0.0),
          condicion(""),
          cantidadDisponible(0) {};

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Electronico con valores específicos.
     *
     * @param nom Nombre del producto.
     * @param pre Precio unitario del producto.
     * @param mar Marca del electrónico.
     * @param tam Tamaño en pulgadas.
     * @param cond Condición del producto (nuevo, usado, etc.).
     * @param cant Cantidad disponible en inventario.
     * @return Objeto Electronico con valores asignados.
     */
    Electronico(std::string nom, float pre, std::string mar, float tam,
                std::string cond, int cant)
        : nombre(nom),
          precio(pre),
          marca(mar),
          tamano(tam),
          condicion(cond),
          cantidadDisponible(cant) {}

    // Métodos getter

    /**
     * Obtiene el nombre del producto electrónico.
     *
     * @param
     * @return Nombre del producto.
     */
    std::string getNombre();

    /**
     * Obtiene el precio del producto.
     *
     * @param
     * @return Precio unitario.
     */
    float getPrecio();

    /**
     * Obtiene la marca del producto.
     *
     * @param
     * @return Marca.
     */
    std::string getMarca();

    /**
     * Obtiene el tamaño físico del producto en pulgadas.
     *
     * @param
     * @return Tamaño en pulgadas.
     */
    float getTamano();

    /**
     * Obtiene la condición del producto (nuevo, usado, etc.).
     *
     * @param
     * @return Condición del producto.
     */
    std::string getCondicion();

    /**
     * Obtiene la cantidad disponible en inventario.
     *
     * @param
     * @return Cantidad disponible.
     */
    int getCantidadDisponible();

    // Métodos setter

    /**
     * Asigna un nuevo precio al producto.
     *
     * @param pre Nuevo precio del producto.
     * @return
     */
    void setPrecio(float pre);

    /**
     * Asigna una nueva condición al producto.
     *
     * @param cond Nueva condición del producto.
     * @return
     */
    void setCondicion(std::string cond);

    /**
     * Establece una nueva cantidad disponible en inventario.
     *
     * @param cant Nueva cantidad disponible.
     * @return
     */
    void setCantidadDisponible(int cant);

    /**
     * Calcula el valor total del stock del producto.
     *
     * Multiplica el precio unitario por la cantidad disponible.
     *
     * @param
     * @return Valor total del stock.
     */
    float calcularValorStock();

    /**
     * Genera una cadena con toda la información del producto.
     *
     * Incluye nombre, precio, marca, tamaño, condición, cantidad y
     * valor total de inventario en formato legible.
     *
     * @param
     * @return Cadena con información detallada del producto.
     */
    std::string mostrarInfo();
};

// Implementaciones de los métodos

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
