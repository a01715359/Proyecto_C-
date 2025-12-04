#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include <string>
#include "Electronico.h"
#include "Sim.h"
#include <sstream>

class Smartphone: public Electronico{
    private:
        int memoria;
        Sim sim;

    public:
    Smartphone(): 
        Electronico(), memoria(0), sim() {};
    Smartphone(std::string nom, float pre, std::string mar, int mem, float tam, std::string cond, int cant, 
                std::string numSim, std::string operSim, std::string tipSim,  bool actSim):
        Electronico(nom, pre, mar, tam, cond, cant), memoria(mem), sim(numSim, operSim, tipSim, actSim) {}

    int getMemoria();
    Sim getSim();
    void setSim(Sim &s);

    std::string mostrarInfo();
};

int Smartphone::getMemoria() {
    return memoria;
}

Sim Smartphone::getSim() {
    return sim;
}

void Smartphone::setSim(Sim &s) {
    sim = s;
}

std::string Smartphone::mostrarInfo() {
    std::stringstream info;
    info << "Nombre: " << nombre << std::endl;
    info << "Precio: $" << precio << std::endl;
    info << "Marca: " << marca << std::endl;
    info << "Memoria: " << memoria << " GB" << std::endl;
    info << "SIM: \n" << sim.mostrarInfo();
    info << "Condicion: " << condicion << std::endl;
    info << "Size: " << tamano << " pulgadas" << std::endl;
    info << "Cantidad disponible: " << cantidadDisponible << std::endl;
    info << "Valor total en stock: $" << calcularValorStock() << std::endl;
    return info.str();
}
#endif
