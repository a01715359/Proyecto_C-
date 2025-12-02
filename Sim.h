#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class Sim{
    private:
        std::string numero;
        std::string operador;
        std::string tipo;
        bool activo;

    public:
        Sim(): numero(""), operador(""), tipo(""), activo(false){};
        Sim(std::string num_sim, std::string oper_sim, std::string tip_sim, bool act_sim): numero(num_sim), operador(oper_sim), tipo(tip_sim), activo(act_sim){}

    std::string getNumero();
    std::string getOperador();
    std::string getTipo();
    bool getActivo();

    void setActivo(bool act_sim);
    std::string mostrar_info();
};

std::string Sim::getNumero(){
    return numero;
}

std::string Sim::getOperador(){
    return operador;
}

std::string Sim::getTipo(){
    return tipo;
}

bool Sim::getActivo(){
    return activo;
}

void Sim::setActivo(bool act_sim){
    activo = act_sim;
}

std::string Sim::mostrar_info(){
    std::stringstream info;
    info << "Número: " << numero << std::endl;
    info << "Operador: " << operador << std::endl;
    info << "Tipo: " << tipo << std::endl;
    info << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl;
    return info.str();
}

#endif
