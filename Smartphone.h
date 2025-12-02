#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include <string>
#include "Electronico.h"
#include "Sim.h"
#include <sstream>
#include <limits>

class Smartphone: public Electronico{
    private:
        int memoria;
        Sim sim;

    public:
    Smartphone(): Electronico(), memoria(0), sim() {};
    Smartphone(std::string nom, float pre, std::string mar, int mem, float tam, std::string cond, int cant, std::string num_sim, std::string oper_sim, std::string tip_sim,  bool act_sim)
    : Electronico(nom, pre, mar, tam, cond, cant), memoria(mem), sim(num_sim, oper_sim, tip_sim, act_sim) {}

    int getMemoria();
    Sim getSim();
    void setSim(Sim &s);

    std::string mostrar_info();
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

        std::string Smartphone::mostrar_info() {
            std::stringstream info;
            info << "Nombre: " << nombre << std::endl;
            info << "Precio: $" << precio << std::endl;
            info << "Marca: " << marca << std::endl;
            info << "Memoria: " << memoria << " GB" << std::endl;
            info << "SIM: \n" << sim.mostrar_info();
            info << " - " << sim.getNumero() << " (" << sim.getOperador() << ")" << std::endl;
            info << " - " << sim.getTipo() << " (" << (sim.getActivo() ? "Activo" : "Inactivo") << ")" << std::endl;
            info << "Condición: " << condicion << std::endl;
            info << "Tamaño: " << tamano << " pulgadas" << std::endl;
            info << "Cantidad disponible: " << cantidad_disponible << std::endl;
            info << "Valor total en stock: $" << calcular_valor_stock() << std::endl;
                return info.str();
        }

#endif
