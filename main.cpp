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
        std::cout << "Entrada inválida, intenta otra vez.\n";
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
    bool menu = true;

    Smartphone celular;
    Laptop computadora;
    Televisor tv;

    bool tiene_celular = false;
    bool tiene_computadora = false;
    bool tiene_tv = false;

    int index_cel = 0;
    int index_lap = 0;
    int index_tv = 0;

    Inventario inventario;

    while (menu == true){
        std::string opcion;
        std::cout << "\nSeleccione lo que desea hacer:\n";
        std::cout << "1: Agregar celular\n";
        std::cout << "2: Agregar laptop\n";
        std::cout << "3: Agregar televisor\n";
        std::cout << "4: Modificar datos\n";
        std::cout << "5: Ver inventario\n";
        std::cout << "6: Salir\n";
        std::cin >> opcion;
        std::cin.ignore(1000, '\n');

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

            std::cout << "¿Esta activa la SIM? (1: Sí, 0: No): ";
            int activo_sim_input;
            std::cin >> activo_sim_input;
            std::cin.ignore(1000, '\n');

            bool activo_sim;
            if (activo_sim_input == 1){
                activo_sim = true;
            }
            else if (activo_sim_input == 0){
                activo_sim = false;
            }
            else{
                std::cout << "Valor invalido. Se establecera como Inactivo.\n";
                activo_sim = false;
            }

            // Constructor: Smartphone
            celular = Smartphone(nombre, precio, marca, memoria, tamano, condicion, cantidad_disponible,
                                 num_sim, oper_sim, tipo_sim, activo_sim);
            tiene_celular = true;
            inventario.agregarSmartphone(celular);
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
            computadora = Laptop(nombre, precio, marca, procesador, tamano, ram, condicion, cantidad_disponible);
            tiene_computadora = true;
            inventario.agregarLaptop(computadora);
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
                std::cout << "Valor inválido. Escriba si o no: ";
                std::getline(std::cin, smartTV);
            }

            std::cout << "Condicion (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);
            condicion = validar_condicion(condicion);

            std::cout << "Cantidad disponible: ";
            cantidad_disponible = get_int(1);
            std::cin.ignore(1000, '\n');

            // Constructor: Televisor
            tv = Televisor(nombre, precio, marca, tipo_pantalla, tamano, smartTV, condicion, cantidad_disponible);
            tiene_tv = true;
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
                if (tiene_celular == true){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el índice del celular a modificar (0 - " << inventario.getCantidad_smartphones() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');

                    if (idx < 0 || idx >= inventario.getCantidad_smartphones()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        index_cel = idx;
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
                        std::cin.ignore(1000, '\n');
                        
                        inventario.modificarSmartphone(index_cel, pre, cond, cant);
                        std::cout << inventario.mostrarInventario();
                    }
                }
                else{
                    std::cout << "No hay un celular agregado aun.\n";
                }
            }
            else if (modificar == "laptop" || modificar == "Laptop" || modificar == "LAPTOP"){
                if (tiene_computadora == true){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice de la laptop a modificar (0 - " << inventario.getCantidad_laptops() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');

                    if (idx < 0 || idx >= inventario.getCantidad_laptops()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        index_lap = idx;
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
                        std::cin.ignore(1000, '\n');

                        inventario.modificarLaptop(index_lap, pre, cond, cant);
                        std::cout << inventario.mostrarInventario();
                    }
                }
                else{
                    std::cout << "No hay una laptop agregada aun.\n";
                }
            }
            else if (modificar == "televisor" || modificar == "Televisor" || modificar == "TELEVISOR"){
                if (tiene_tv == true){
                    std::cout << inventario.mostrarInventario();
                    std::cout << "Ingrese el indice del televisor a modificar (0 - " << inventario.getCantidad_televisores() - 1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');
                    if (idx < 0 || idx >= inventario.getCantidad_televisores()){
                        std::cout << "Indice invalido. Operacion cancelada.\n";
                    }
                    else{
                        index_tv = idx;
                        std::cout << "Ingrese la nueva condicion: ";
                        std::getline(std::cin, cond);
                        cond = validar_condicion(cond);
                        std::cout << "Nuevo precio: ";
                        pre = get_float(1.0);
                        std::cin.ignore(1000, '\n');
                        std::cout << "Nueva cantidad: ";
                        cant = get_int(1);
                        std::cin.ignore(1000, '\n');

                        inventario.modificarTelevisor(index_tv, pre, cond, cant);
                        std::cout << inventario.mostrarInventario();
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
            menu = false;
        }
        else{
            std::cout << "Opcion invalida. Intente nuevamente.\n";
        }  
    } 
    return 0;
}
