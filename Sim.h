#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <string>
#include <sstream>

class Sim{
    private:
        std::string numero;
        std::string operador;
        std::string tipo;
        bool activo;

    public:
        Sim(): 
            numero(""), operador(""), tipo(""), activo(false){};
        Sim(std::string numSim, std::string operSim, std::string tipSim, bool actSim): 
            numero(numSim), operador(operSim), tipo(tipSim), activo(actSim){}

    std::string getNumero();
    std::string getOperador();
    std::string getTipo();
    bool getActivo();

    void setActivo(bool actSim);
    std::string mostrarInfo();
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

void Sim::setActivo(bool actSim){
    activo = actSim;
}

std::string Sim::mostrarInfo(){
    std::stringstream info;
    info << "Número: " << numero << std::endl;
    info << "Operador: " << operador << std::endl;
    info << "Tipo: " << tipo << std::endl;
    info << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl;
    return info.str();
}

#endif
