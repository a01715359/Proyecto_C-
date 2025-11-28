#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <iostream>
#include <string>
#include "Electronico.h"
#include "Sim.h"

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

    void mostrar_info();
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

        void Smartphone::mostrar_info() {
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nMemoria: " << memoria << " GB"
                      << "\nSIM: \n" 
                      << "\n - " << sim.getNumero() << " (" << sim.getOperador() << ")"
                      << "\n - " << sim.getTipo() << " (" << (sim.getActivo() ? "Activo" : "Inactivo") << ")"
                      << "\nCondición: " << condicion
                      << "\nTamaño: " << tamano << " pulgadas"
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock() 
                      << "\n\n";
        }
#endif
