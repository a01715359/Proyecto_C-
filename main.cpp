#include <iostream>
#include <string>
#include <limits>

#include "Smartphone.h"
#include "Laptop.h"
#include "Televisor.h"
#include "Inventario.h"

int get_int(int min_val){
    int number;
    while (true) {
        if (std::cin >> number && number >= min_val) {
            return number;
        }
        std::cout << "Entrada invalida, intenta otra vez.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

float get_float(float min_val){
  float number;
  while (true) {
      if (std::cin >> number && number >= min_val) {
          return number;
      }
      std::cout << "Entrada inválida, intenta otra vez." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n');
  }
}

std::string validar_tipo_sim(std::string dato){
    while (dato != "Nano" && dato != "Micro" 
        && dato != "nano" && dato != "micro"
        && dato != "NANO" && dato != "MICRO"){
        std::cout << "Valor invalido. Ingrese (Nano/Micro): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

std::string validar_condicion(std::string dato){
    while (dato != "Nuevo" && dato != "Usado" && dato != "Reacondicionado" 
        && dato != "nuevo" && dato != "usado" && dato != "reacondicionado"
        && dato != "NUEVO" && dato != "USADO" && dato != "REACONDICIONADO"){
        std::cout << "Valor invalido. Ingrese (Nuevo/Usado/Reacondicionado): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

std::string validar_producto(std::string dato){
    while (dato != "Celular" && dato != "Laptop" && dato != "Televisor"
        && dato != "celular" && dato != "laptop" && dato != "televisor"
        && dato != "CELULAR" && dato != "LAPTOP" && dato != "TELEVISOR"){
        std::cout << "Valor invalido. Ingrese (Celular/Laptop/Televisor): " << std::endl;
        std::getline(std::cin, dato);
    }
    return dato;
}

int main(){
    //bool menu = true;

    //Smartphone celular;
    //Laptop computadora;
    //Televisor tv;

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
            int memoria, cantidad_disponible;
            float precio, tamano;
            std::string num_sim, oper_sim, tipo_sim;

            std::cout << "=== Agregar Celular ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = get_float(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Memoria (en GB): ";
            memoria = get_int(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Tamaño (en pulgadas): ";
            tamano = get_float(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validar_condicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidad_disponible = get_int(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Numero de SIM: ";
            std::getline(std::cin, num_sim);

            std::cout << "Operador de SIM: ";
            std::getline(std::cin, oper_sim);

            std::cout << "Tipo de SIM: (Nano/Micro) ";
            std::getline(std::cin, tipo_sim);
            tipo_sim = validar_tipo_sim(tipo_sim);

            int activo_sim_input;
            std::cout << "¿Esta activa la SIM? (1: Sí, 0: No): ";
            activo_sim_input = get_int(0);

            while (activo_sim_input != 0 && activo_sim_input != 1) {
                std::cout << "Valor invalido. Ingrese 1 (Si) o 0 (No): ";
                activo_sim_input = get_int(0);
            }

            bool activo_sim = (activo_sim_input == 1);


            // Constructor: Smartphone
            Smartphone celular(nombre, precio, marca, memoria, tamano, condicion, cantidad_disponible,
                                 num_sim, oper_sim, tipo_sim, activo_sim);
            inventario.agregarSmartphone(celular);
            std::cout << "\nSmartphone agregado:\n";
            //index_cel = inventario.getCantidad_smartphones() - 1;
            std::cout << celular.mostrar_info();
        }

        // ================ AGREGAR LAPTOP ==============
        else if (opcion == "2"){
            std::string nombre, marca, procesador, condicion;
            float precio, tamano;
            int ram, cantidad_disponible;

            std::cout << "=== Agregar Laptop ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = get_float(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Procesador: ";
            std::getline(std::cin, procesador);

            std::cout << "Tamaño (en pulgadas): ";
            tamano = get_float(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "RAM (en GB): ";
            ram = get_int(1);
            std::cin.ignore(1000, '\n');

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validar_condicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidad_disponible = get_int(1);
            std::cin.ignore(1000, '\n');

            // Constructor: Laptop
            Laptop computadora(nombre, precio, marca, procesador, tamano, ram, condicion, cantidad_disponible);
            inventario.agregarLaptop(computadora);
            std::cout << "\nLaptop agregada:\n";
            //index_lap = inventario.getCantidad_laptops() - 1;
            std::cout << computadora.mostrar_info();
        }
        // ================ AGREGAR TELEVISOR ===========
        else if (opcion == "3"){
            std::string nombre, marca, tipo_pantalla, smartTV, condicion;
            float precio, tamano;
            int cantidad_disponible;

            std::cout << "=== Agregar Televisor ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            precio = get_float(1.0);
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Tipo de pantalla: ";
            std::getline(std::cin, tipo_pantalla);

            std::cout << "Tamaño (en pulgadas): ";
            tamano = get_float(1.0);
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
            condicion = validar_condicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidad_disponible = get_int(1);
            std::cin.ignore(1000, '\n');

            // Constructor: Televisor
            Televisor tv(nombre, precio, marca, tipo_pantalla, tamano, smartTV, condicion, cantidad_disponible);
            inventario.agregarTelevisor(tv);
            //index_tv = inventario.getCantidad_televisores() - 1;
            std::cout << tv.mostrar_info();
        }
        // =================== MODIFICAR ===============
        else if (opcion == "4"){

            std::string modificar;
            std::cout << "Ingrese el producto a modificar (celular/laptop/televisor): ";
            std::getline(std::cin, modificar);
            modificar = validar_producto(modificar);

            std::string cond;
            float pre;
            int cant;

            if (modificar == "celular" || modificar == "Celular" || modificar == "CELULAR"){
                if (inventario.getCantidad_smartphones() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el índice del celular a modificar (0 - " << inventario.getCantidad_smartphones() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');

                    if (idx < 0 || idx >= inventario.getCantidad_smartphones()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
                        std::cin.ignore(1000, '\n');
                        
                        inventario.modificarSmartphone(idx, pre, cond, cant);
                    }
                }
                else{
                    std::cout << "No hay un celular agregado aun.\n";
                }
            }
            else if (modificar == "laptop" || modificar == "Laptop" || modificar == "LAPTOP"){
                if (inventario.getCantidad_laptops() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice de la laptop a modificar (0 - " << inventario.getCantidad_laptops() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');

                    if (idx < 0 || idx >= inventario.getCantidad_laptops()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
                        std::cin.ignore(1000, '\n');

                        inventario.modificarLaptop(idx, pre, cond, cant);
                    }
                }
                else{
                    std::cout << "No hay una laptop agregada aun.\n";
                }
            }
            else if (modificar == "televisor" || modificar == "Televisor" || modificar == "TELEVISOR"){
                if (inventario.getCantidad_televisores() > 0){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice del televisor a modificar (0 - " << inventario.getCantidad_televisores() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');
                    if (idx < 0 || idx >= inventario.getCantidad_televisores()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
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
