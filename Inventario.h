#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <sstream>
#include <string>

#include "Laptop.h"
#include "Smartphone.h"
#include "Televisor.h"

/*
 * Clase Inventario
 * Maneja colecciones de productos electrónicos: Laptops, Smartphones y Televisores.
 *
 * Permite agregar, modificar y consultar los productos del inventario,
 * así como mostrar toda la información de manera organizada.
 */

class Inventario {
   private:
    Laptop laptops[1000];              // Arreglo de objetos Laptop
    Smartphone smartphones[1000];      // Arreglo de objetos Smartphone
    Televisor televisores[1000];       // Arreglo de objetos Televisor
    int cantidadLaptops;               // Número actual de laptops en inventario
    int cantidadSmartphones;           // Número actual de smartphones en inventario
    int cantidadTelevisores;           // Número actual de televisores en inventario

   public:
    /**
     * Constructor por default.
     *
     * Inicializa los contadores de cada tipo de producto en cero,
     * indicando un inventario vacío al crear el objeto.
     *
     * @param
     * @return Objeto Inventario con arreglos vacíos.
     */
    Inventario()
        : cantidadLaptops(0),
          cantidadSmartphones(0),
          cantidadTelevisores(0) {}

    // Métodos getter

    /**
     * Obtiene la cantidad de laptops en el inventario.
     *
     * @param
     * @return Número de laptops actualmente en inventario.
     */
    int getCantidadLaptops();

    /**
     * Obtiene la cantidad de smartphones en el inventario.
     *
     * @param
     * @return Número de smartphones actualmente en inventario.
     */
    int getCantidadSmartphones();

    /**
     * Obtiene la cantidad de televisores en el inventario.
     *
     * @param
     * @return Número de televisores actualmente en inventario.
     */
    int getCantidadTelevisores();

    // Métodos para agregar productos

    /**
     * Agrega una laptop al inventario si hay espacio disponible.
     *
     * @param laptop Objeto Laptop a agregar.
     * @return
     */
    void agregarLaptop(Laptop& laptop);

    /**
     * Agrega un smartphone al inventario si hay espacio disponible.
     *
     * @param smartphone Objeto Smartphone a agregar.
     * @return
     */
    void agregarSmartphone(Smartphone& smartphone);

    /**
     * Agrega un televisor al inventario si hay espacio disponible.
     *
     * @param televisor Objeto Televisor a agregar.
     * @return
     */
    void agregarTelevisor(Televisor& televisor);

    // Métodos para modificar productos

    /**
     * Modifica los atributos de una laptop existente en el inventario.
     *
     * @param index Índice de la laptop a modificar.
     * @param nuevoPrecio Nuevo precio de la laptop.
     * @param nuevaCondicion Nueva condición de la laptop.
     * @param nuevaCantidad Nueva cantidad disponible.
     * @return
     */
    void modificarLaptop(int index, float nuevoPrecio,
                         std::string nuevaCondicion, int nuevaCantidad);

    /**
     * Modifica los atributos de un smartphone existente en el inventario.
     *
     * @param index Índice del smartphone a modificar.
     * @param nuevoPrecio Nuevo precio del smartphone.
     * @param nuevaCondicion Nueva condición del smartphone.
     * @param nuevaCantidad Nueva cantidad disponible.
     * @return
     */
    void modificarSmartphone(int index, float nuevoPrecio,
                             std::string nuevaCondicion, int nuevaCantidad);

    /**
     * Modifica los atributos de un televisor existente en el inventario.
     *
     * @param index Índice del televisor a modificar.
     * @param nuevoPrecio Nuevo precio del televisor.
     * @param nuevaCondicion Nueva condición del televisor.
     * @param nuevaCantidad Nueva cantidad disponible.
     * @return
     */
    void modificarTelevisor(int index, float nuevoPrecio,
                            std::string nuevaCondicion, int nuevaCantidad);

    /**
     * Muestra toda la información del inventario en formato legible.
     *
     * Incluye laptops, smartphones y televisores, con todos sus
     * atributos y el valor total de stock de cada uno.
     *
     * @param
     * @return Cadena con la información completa del inventario.
     */
    std::string mostrarInventario();
};

// Implementaciones de los métodos

int Inventario::getCantidadLaptops() {
    return cantidadLaptops;
}

int Inventario::getCantidadSmartphones() {
    return cantidadSmartphones;
}

int Inventario::getCantidadTelevisores() {
    return cantidadTelevisores;
}

void Inventario::agregarLaptop(Laptop& laptop) {
    if (cantidadLaptops < 1000) {
        laptops[cantidadLaptops] = laptop;
        cantidadLaptops++;
    } else {
        std::cout << "No se puede agregar más laptops: inventario lleno.\n";
    }
}

void Inventario::agregarSmartphone(Smartphone& smartphone) {
    if (cantidadSmartphones < 1000) {
        smartphones[cantidadSmartphones] = smartphone;
        cantidadSmartphones++;
    } else {
        std::cout
            << "No se puede agregar más smartphones: inventario lleno.\n";
    }
}

void Inventario::agregarTelevisor(Televisor& televisor) {
    if (cantidadTelevisores < 1000) {
        televisores[cantidadTelevisores] = televisor;
        cantidadTelevisores++;
    } else {
        std::cout
            << "No se puede agregar más televisores: inventario lleno.\n";
    }
}

void Inventario::modificarLaptop(int index, float nuevoPrecio,
                                 std::string nuevaCondicion,
                                 int nuevaCantidad) {
    if (index >= 0 && index < cantidadLaptops) {
        laptops[index].setPrecio(nuevoPrecio);
        laptops[index].setCondicion(nuevaCondicion);
        laptops[index].setCantidadDisponible(nuevaCantidad);
    } else {
        std::cout << "Indice invalido para laptop.\n";
    }
}

void Inventario::modificarSmartphone(int index, float nuevoPrecio,
                                     std::string nuevaCondicion,
                                     int nuevaCantidad) {
    if (index >= 0 && index < cantidadSmartphones) {
        smartphones[index].setPrecio(nuevoPrecio);
        smartphones[index].setCondicion(nuevaCondicion);
        smartphones[index].setCantidadDisponible(nuevaCantidad);
    } else {
        std::cout << "Índice inválido para smartphone.\n";
    }
}

void Inventario::modificarTelevisor(int index, float nuevoPrecio,
                                    std::string nuevaCondicion,
                                    int nuevaCantidad) {
    if (index >= 0 && index < cantidadTelevisores) {
        televisores[index].setPrecio(nuevoPrecio);
        televisores[index].setCondicion(nuevaCondicion);
        televisores[index].setCantidadDisponible(nuevaCantidad);
    } else {
        std::cout << "Indice invalido para televisor.\n";
    }
}

std::string Inventario::mostrarInventario() {
    std::stringstream ss;
    ss << "=== Laptops ===\n";
    for (int i = 0; i < cantidadLaptops; i++) {
        ss << laptops[i].mostrarInfo();
    }
    ss << "=== Smartphones ===\n";
    for (int i = 0; i < cantidadSmartphones; i++) {
        ss << smartphones[i].mostrarInfo();
    }
    ss << "=== Televisores ===\n";
    for (int i = 0; i < cantidadTelevisores; i++) {
        ss << televisores[i].mostrarInfo();
    }
    return ss.str();
}

#endif
