#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <sstream>
#include "Laptop.h"
#include "Smartphone.h"
#include "Televisor.h"


class Inventario{
    private:
    Laptop laptops[1000];
    Smartphone smartphones[1000];
    Televisor televisores[1000];
    int cantidad_laptops;
    int cantidad_smartphones;
    int cantidad_televisores;

    public:
    Inventario(): cantidad_laptops(0), cantidad_smartphones(0), cantidad_televisores(0){}

    int getCantidad_laptops(){
        return cantidad_laptops;
    }
    int getCantidad_smartphones(){
        return cantidad_smartphones;
    }
    int getCantidad_televisores(){
        return cantidad_televisores;
    }

    void agregarLaptop(Laptop& laptop);
    void agregarSmartphone(Smartphone& smartphone);
    void agregarTelevisor(Televisor& televisor);
    void modificarLaptop(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad);
    void modificarSmartphone(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad);
    void modificarTelevisor(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad);
    std::string mostrarInventario();
};

    void Inventario:: agregarLaptop(Laptop& laptop){
        if (cantidad_laptops < 1000) {
            laptops[cantidad_laptops] = laptop;
            cantidad_laptops++;
        } else {
            std::cout << "No se puede agregar más laptops: inventario lleno.\n";
        }
    }

    void Inventario::agregarSmartphone(Smartphone& smartphone){
        if (cantidad_smartphones < 1000) {
            smartphones[cantidad_smartphones] = smartphone;
            cantidad_smartphones++;
        } else {
            std::cout << "No se puede agregar más smartphones: inventario lleno.\n";
        }
    }

    void Inventario::agregarTelevisor(Televisor& televisor){
        if (cantidad_televisores < 1000) {
            televisores[cantidad_televisores] = televisor;
            cantidad_televisores++;
        } else {
            std::cout << "No se puede agregar más televisores: inventario lleno.\n";
        }
    }

    

    void Inventario::modificarLaptop(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad){
        if (index >= 0 && index < cantidad_laptops){
            laptops[index].setPrecio(nuevo_precio);
            laptops[index].setCondicion(nueva_condicion);
            laptops[index].setCantidad_disponible(nueva_cantidad);
        } else {
            std::cout << "Índice inválido para laptop.\n";
        }
    }

    void Inventario::modificarSmartphone(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad){
        if (index >= 0 && index < cantidad_smartphones){
            smartphones[index].setPrecio(nuevo_precio);
            smartphones[index].setCondicion(nueva_condicion);
            smartphones[index].setCantidad_disponible(nueva_cantidad);
        } else {
            std::cout << "Índice inválido para smartphone.\n";
        }
    }

    void Inventario::modificarTelevisor(int index, float nuevo_precio, std::string nueva_condicion, int nueva_cantidad){
        if (index >= 0 && index < cantidad_televisores){
            televisores[index].setPrecio(nuevo_precio);
            televisores[index].setCondicion(nueva_condicion);
            televisores[index].setCantidad_disponible(nueva_cantidad);
        } else {
            std::cout << "Índice inválido para televisor.\n";
        }
    }

    std::string Inventario::mostrarInventario(){
        std::stringstream ss;
        ss << "=== Laptops ===\n";
        for(int i = 0; i < cantidad_laptops; i++){
            ss << "[" << i << "]\n";
            ss << laptops[i].mostrar_info();
        }
        ss << "=== Smartphones ===\n";
        for(int i = 0; i < cantidad_smartphones; i++){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
            ss << "[" << i << "]\n";
            ss << smartphones[i].mostrar_info();
        }
        ss << "=== Televisores ===\n";
        for(int i = 0; i < cantidad_televisores; i++){
            ss << "[" << i << "]\n";
            ss << televisores[i].mostrar_info();
        }
        return ss.str();
    }

#endif
