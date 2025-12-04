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
    int cantidadLaptops;
    int cantidadSmartphones;
    int cantidadTelevisores;

    public:
    Inventario(): cantidadLaptops(0), cantidadSmartphones(0), cantidadTelevisores(0){}

    int getCantidadLaptops();
    int getCantidadSmartphones();
    int getCantidadTelevisores();

    void agregarLaptop(Laptop& laptop);
    void agregarSmartphone(Smartphone& smartphone);
    void agregarTelevisor(Televisor& televisor);
    void modificarLaptop(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad);
    void modificarSmartphone(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad);
    void modificarTelevisor(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad);
    std::string mostrarInventario();
};

int Inventario::getCantidadLaptops(){
        return cantidadLaptops;
    }
    int Inventario::getCantidadSmartphones(){
        return cantidadSmartphones;
    }
    int Inventario::getCantidadTelevisores(){
        return cantidadTelevisores;
    }

    void Inventario::agregarLaptop(Laptop& laptop){
        if (cantidadLaptops < 1000) {
            laptops[cantidadLaptops] = laptop;
            cantidadLaptops++;
        } else {
            std::cout << "No se puede agregar más laptops: inventario lleno.\n";
        }
    }

    void Inventario::agregarSmartphone(Smartphone& smartphone){
        if (cantidadSmartphones < 1000) {
            smartphones[cantidadSmartphones] = smartphone;
            cantidadSmartphones++;
        } else {
            std::cout << "No se puede agregar más smartphones: inventario lleno.\n";
        }
    }

    void Inventario::agregarTelevisor(Televisor& televisor){
        if (cantidadTelevisores < 1000) {
            televisores[cantidadTelevisores] = televisor;
            cantidadTelevisores++;
        } else {
            std::cout << "No se puede agregar más televisores: inventario lleno.\n";
        }
    }

    void Inventario::modificarLaptop(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad){
        if (index >= 0 && index < cantidadLaptops){
            laptops[index].setPrecio(nuevoPrecio);
            laptops[index].setCondicion(nuevaCondicion);
            laptops[index].setCantidadDisponible(nuevaCantidad);
        } else {
            std::cout << "Indice invalido para laptop.\n";
        }
    }

    void Inventario::modificarSmartphone(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad){
        if (index >= 0 && index < cantidadSmartphones){
            smartphones[index].setPrecio(nuevoPrecio);
            smartphones[index].setCondicion(nuevaCondicion);
            smartphones[index].setCantidadDisponible(nuevaCantidad);
        } else {
            std::cout << "Índice inválido para smartphone.\n";
        }
    }

    void Inventario::modificarTelevisor(int index, float nuevoPrecio, std::string nuevaCondicion, int nuevaCantidad){
        if (index >= 0 && index < cantidadTelevisores){
            televisores[index].setPrecio(nuevoPrecio);
            televisores[index].setCondicion(nuevaCondicion);
            televisores[index].setCantidadDisponible(nuevaCantidad);
        } else {
            std::cout << "Indice invalido para televisor.\n";
        }
    }

    std::string Inventario::mostrarInventario(){
        std::stringstream ss;
        ss << "=== Laptops ===\n";
        for(int i = 0; i < cantidadLaptops; i++){
            ss << laptops[i].mostrarInfo();
        }
        ss << "=== Smartphones ===\n";
        for(int i = 0; i < cantidadSmartphones; i++){
            ss << smartphones[i].mostrarInfo();
        }
        ss << "=== Televisores ===\n";
        for(int i = 0; i < cantidadTelevisores; i++){
            ss << televisores[i].mostrarInfo();
        }
        return ss.str();
    }

#endif
