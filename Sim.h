#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <sstream>
#include <string>

/*
 * Clase Sim
 * Representa una tarjeta SIM con información básica como número,
 * operador, tipo y estado de activación.
 *
 * Permite consultar y modificar el estado de la SIM, así como
 * generar información completa sobre sus atributos.
 */

class Sim {
   private:
    std::string numero;     // Número de la SIM
    std::string operador;   // Operador de la SIM
    std::string tipo;       // Tipo de SIM (prepago, pospago, etc.)
    bool activo;            // Estado de la SIM (true = activa, false = inactiva)

   public:
    /**
     * Constructor por default.
     *
     * Inicializa todos los atributos con valores vacíos o falso.
     *
     * @param
     * @return Objeto Sim con valores por defecto.
     */
    Sim() : numero(""), operador(""), tipo(""), activo(false) {};

    /**
     * Constructor con parámetros.
     *
     * Permite inicializar un objeto Sim con valores específicos.
     *
     * @param numSim Número de la SIM.
     * @param operSim Operador de la SIM.
     * @param tipSim Tipo de la SIM (prepago, pospago, etc.).
     * @param actSim Estado de activación (true = activo, false = inactivo).
     * @return Objeto Sim con valores asignados.
     */
    Sim(std::string numSim, std::string operSim, std::string tipSim,
        bool actSim)
        : numero(numSim), operador(operSim), tipo(tipSim), activo(actSim) {}

    // Métodos getter

    /**
     * Obtiene el número de la SIM.
     *
     * @param
     * @return Número de la SIM.
     */
    std::string getNumero();

    /**
     * Obtiene el operador de la SIM.
     *
     * @param
     * @return Operador de la SIM.
     */
    std::string getOperador();

    /**
     * Obtiene el tipo de la SIM (prepago, pospago, etc.).
     *
     * @param
     * @return Tipo de la SIM.
     */
    std::string getTipo();

    /**
     * Obtiene el estado de activación de la SIM.
     *
     * @param
     * @return true si la SIM está activa, false si está inactiva.
     */
    bool getActivo();

    // Métodos setter

    /**
     * Modifica el estado de activación de la SIM.
     *
     * @param actSim Nuevo estado (true = activo, false = inactivo).
     * @return
     */
    void setActivo(bool actSim);

    /**
     * Genera una cadena con toda la información de la SIM.
     *
     * Incluye número, operador, tipo y estado de activación.
     *
     * @param
     * @return Cadena con información detallada de la SIM.
     */
    std::string mostrarInfo();
};

// Implementaciones de los métodos

std::string Sim::getNumero() {
    return numero;
}

std::string Sim::getOperador() {
    return operador;
}

std::string Sim::getTipo() {
    return tipo;
}

bool Sim::getActivo() {
    return activo;
}

void Sim::setActivo(bool actSim) {
    activo = actSim;
}

std::string Sim::mostrarInfo() {
    std::stringstream info;
    info << "Número: " << numero << std::endl;
    info << "Operador: " << operador << std::endl;
    info << "Tipo: " << tipo << std::endl;
    info << "Estado: " << (activo ? "Activo" : "Inactivo") << std::endl;
    return info.str();
}

#endif
