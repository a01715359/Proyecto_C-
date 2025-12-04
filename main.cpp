#include <iostream>
#include <string>
#include <limits>

#include "Smartphone.h"
#include "Laptop.h"
#include "Televisor.h"
#include "Inventario.h"

int getInt(int minVal){
    int number;
    while (true) {
        if (std::cin >> number && number >= minVal) {
            return number;
        }
        std::cout << "Entrada invalida, intenta otra vez.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

float getFloat(float minVal){
  float number;
  while (true) {
      if (std::cin >> number && number >= minVal) {
          return number;
      }
      std::cout << "Entrada inválida, intenta otra vez." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');
  }
}

std::string validarTipoSim(std::string dato){
    while (dato != "Nano" && dato != "Micro" 
        && dato != "nano" && dato != "micro"
        && dato != "NANO" && dato != "MICRO"){
        std::cout << "Valor invalido. Ingrese (Nano/Micro): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

std::string validarCondicion(std::string dato){
    while (dato != "Nuevo" && dato != "Usado" && dato != "Reacondicionado" 
        && dato != "nuevo" && dato != "usado" && dato != "reacondicionado"
        && dato != "NUEVO" && dato != "USADO" && dato != "REACONDICIONADO"){
        std::cout << "Valor invalido. Ingrese (Nuevo/Usado/Reacondicionado): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

std::string validarProducto(std::string dato){
    while (dato != "Celular" && dato != "Laptop" && dato != "Televisor"
        && dato != "celular" && dato != "laptop" && dato != "televisor"
        && dato != "CELULAR" && dato != "LAPTOP" && dato != "TELEVISOR"){
        std::cout << "Valor invalido. Ingrese (Celular/Laptop/Televisor): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

int main(){
    Inventario inventario;
    std::string opcion = "0";

    while (opcion != "6"){
        std::cout << "\nSeleccione lo que desea hacer:\n";
        std::cout << "1: Agregar celular\n";
        std::cout << "2: Agregar laptop\n";
        std::cout << "3: Agregar televisor\n";
        std::cout << "4: Modificar datos\n";
        std::cout << "5: Ver inventario\n";
        std::cout << "6: Salir\n";
        std::cin >> opcion;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // ================ AGREGAR CELULAR =============
        if (opcion == "1"){
            std::string nombre, marca, condicion;
            int memoria, cantidadDisponible;
            float precio, tamano;
            std::string numSim, operSim, tipoSim;

            std::cout << "=== Agregar Celular ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Memoria (en GB): ";
            memoria = getInt(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Tamaño (en pulgadas): ";
            tamano = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validarCondicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidadDisponible = getInt(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Numero de SIM: ";
            std::getline(std::cin, numSim);

            std::cout << "Operador de SIM: ";
            std::getline(std::cin, operSim);

            std::cout << "Tipo de SIM: (Nano/Micro) ";
            std::getline(std::cin, tipoSim);
            tipoSim = validarTipoSim(tipoSim);

            int activoSimInput;
            std::cout << "¿Esta activa la SIM? (1: Sí, 0: No): ";
            activoSimInput = getInt(0);

            while (activoSimInput != 0 && activoSimInput != 1) {
                std::cout << "Valor invalido. Ingrese 1 (Si) o 0 (No): ";
                activoSimInput = getInt(0);
            }

            bool activoSim = (activoSimInput == 1);


            // Constructor: Smartphone
            Smartphone celular(nombre, precio, marca, memoria, tamano, condicion, cantidadDisponible,
                                 numSim, operSim, tipoSim, activoSim);
            inventario.agregarSmartphone(celular);
            std::cout << "\nSMARTPHONE AGREGADO:\n\n";
            std::cout << celular.mostrarInfo();
        }

        // ================ AGREGAR LAPTOP ==============
        else if (opcion == "2"){
            std::string nombre, marca, procesador, condicion;
            float precio, tamano;
            int ram, cantidadDisponible;

            std::cout << "=== Agregar Laptop ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Procesador: ";
            std::getline(std::cin, procesador);

            std::cout << "Tamaño (en pulgadas): ";
            tamano = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "RAM (en GB): ";
            ram = getInt(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validarCondicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidadDisponible = getInt(1);
            std::cin.ignore(1000, '\n');

            // Constructor: Laptop
            Laptop computadora(nombre, precio, marca, procesador, tamano, ram, condicion, cantidadDisponible);
            inventario.agregarLaptop(computadora);
            std::cout << "\nLAPTOP AGREGADA:\n\n";
            std::cout << computadora.mostrarInfo();
        }
        // ================ AGREGAR TELEVISOR ===========
        else if (opcion == "3"){
            std::string nombre, marca, tipoPantalla, smartTV, condicion;
            float precio, tamano;
            int cantidadDisponible;

            std::cout << "=== Agregar Televisor ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Tipo de pantalla: ";
            std::getline(std::cin, tipoPantalla);

            std::cout << "Tamaño (en pulgadas): ";
            tamano = getFloat(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "¿Es Smart TV? (Si/No): ";
            std::getline(std::cin, smartTV);
            while (smartTV != "si" && smartTV != "no"
                && smartTV != "Si" && smartTV != "No"
                && smartTV != "SI" && smartTV != "NO"){
                std::cout << "Valor invalido. Escriba si o no: ";
                std::getline(std::cin, smartTV);
            }

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validarCondicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidadDisponible = getInt(1);
            std::cin.ignore(1000, '\n');

            // Constructor: Televisor
            Televisor tv(nombre, precio, marca, tipoPantalla, tamano, smartTV, condicion, cantidadDisponible);
            inventario.agregarTelevisor(tv);
            std::cout << "\nTELEVISOR AGREGADO:\n\n";
            std::cout << tv.mostrarInfo();
        }
        // =================== MODIFICAR ===============
        else if (opcion == "4"){

            std::string modificar;
            std::cout << "Ingrese el producto a modificar (celular/laptop/televisor): ";
            std::getline(std::cin, modificar);
            modificar = validarProducto(modificar);

            std::string cond;
            float pre;
            int cant;

            if (modificar == "celular" || modificar == "Celular" || modificar == "CELULAR"){
                if (inventario.getCantidadSmartphones() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el índice del celular a modificar (0 - " << inventario.getCantidadSmartphones() - 1 << "): ";
                    int idx = getInt(0);

                    if (idx < 0 || idx >= inventario.getCantidadSmartphones()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validarCondicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = getFloat(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = getInt(1);
                        std::cin.ignore(1000, '\n');
                        
                        inventario.modificarSmartphone(idx, pre, cond, cant);
                    }
                }
                else{
                    std::cout << "No hay un celular agregado aun.\n";
                }
            }
            else if (modificar == "laptop" || modificar == "Laptop" || modificar == "LAPTOP"){
                if (inventario.getCantidadLaptops() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice de la laptop a modificar (0 - " << inventario.getCantidadLaptops() - 1 << "): ";
                    int idx = getInt(0);

                    if (idx < 0 || idx >= inventario.getCantidadLaptops()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validarCondicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = getFloat(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = getInt(1);
                        std::cin.ignore(1000, '\n');

                        inventario.modificarLaptop(idx, pre, cond, cant);
                    }
                }
                else{
                    std::cout << "No hay una laptop agregada aun.\n";
                }
            }
            else if (modificar == "televisor" || modificar == "Televisor" || modificar == "TELEVISOR"){
                if (inventario.getCantidadTelevisores() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice del televisor a modificar (0 - " << inventario.getCantidadTelevisores() - 1 << "): ";
                    int idx = getInt(0);
                    
                    if (idx < 0 || idx >= inventario.getCantidadTelevisores()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validarCondicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = getFloat(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = getInt(1);
                        std::cin.ignore(1000, '\n');

                        inventario.modificarTelevisor(idx, pre, cond, cant);
                    }
                }
                else{
                    std::cout << "No hay un televisor agregado aun.\n";
                }
            }
        }
        else if (opcion == "5"){
        std::cout << inventario.mostrarInventario();
        }

        else if (opcion == "6"){
            std::cout << "Saliendo del programa.\n";
        }
        else{
            std::cout << "Opcion invalida. Intente nuevamente.\n";
        }  
    } 
    return 0;
}
