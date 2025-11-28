#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <string>

class Sim{
    private:
        std::string numero;
        std::string operador;
        std::string tipo;
        bool activo;

    public:
        Sim(): numero(""), operador(""), tipo(""), activo(false){};
        Sim(std::string num_sim, std::string oper_sim, std::string tip_sim, bool act_sim): numero(num_sim), operador(oper_sim), tipo(tip_sim), activo(act_sim){}

        std::string getNumero() const;
        std::string getOperador() const;
        std::string getTipo() const;
        bool getActivo() const;

        void setActivo(bool act_sim);
        void mostrar_info() const;
};

std::string Sim::getNumero() const {
    return numero;
}

std::string Sim::getOperador() const {
    return operador;
}

std::string Sim::getTipo() const {
    return tipo;
}

bool Sim::getActivo() const {
    return activo;
}

void Sim::setActivo(bool act_sim) {
    activo = act_sim;
}

void Sim::mostrar_info() const {
    std::cout << "Número: " << numero << std::endl;
    std::cout << "Operador: " << operador << std::endl;
    std::cout << "Tipo: " << tipo << std::endl;
    std::cout << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl;
    std::cout << std::endl;
}

#endif
