#include <iostream>
#include <string>

#include "Smartphone.h"
#include "Laptop.h"
#include "Televisor.h"
#include "Inventario.h"

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
        std::cout << "4: Modificar algún dato\n";
        std::cout << "Cualquier otro botón: Salir\n";
        std::cin >> opcion;
        std::cin.ignore(1000, '\n'); 

        if (opcion == "1") {
            std::string nombre, marca, condicion;
            int memoria, cantidad_disponible;
            float precio, tamano;
            std::string num_sim, oper_sim, tipo_sim;

            std::cout << "=== Agregar Celular ===\n\n";

            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            std::cin >> precio;
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Memoria (en GB): ";
            std::cin >> memoria;  

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;
            std::cin.ignore(1000, '\n');

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;
            std::cin.ignore(1000, '\n'); 

            std::cout << "Número de SIM: ";
            std::getline(std::cin, num_sim);

            std::cout << "Operador de SIM: ";
            std::getline(std::cin, oper_sim);

            std::cout << "Tipo de SIM: ";
            std::getline(std::cin, tipo_sim);

            std::cout << "¿Está activa la SIM? (1: Sí, 0: No): ";
            int activo_sim_input;
            std::cin >> activo_sim_input;
            bool activo_sim;
            if (activo_sim_input == 1) {
                activo_sim = true;
            } else if (activo_sim_input == 0) {
                activo_sim = false;
            } else {
                std::cout << "Valor inválido. Se establecerá como Inactivo.\n";
                activo_sim = false;
            }
            std::cin.ignore(1000, '\n');

            // Constructor: Smartphone
            celular = Smartphone(nombre, precio, marca, memoria, tamano, condicion, cantidad_disponible, 
                                num_sim, oper_sim, tipo_sim, activo_sim);
            tiene_celular = true;
            inventario.agregarSmartphone(celular);
            index_cel = inventario.getCantidad_smartphones() - 1;
            celular.mostrar_info();

        } else if (opcion == "2") {
            std::string nombre, marca, procesador, condicion;
            float precio, tamano;
            int ram, cantidad_disponible;

            std::cout << "=== Agregar Laptop ===\n\n";
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            std::cin >> precio;
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Procesador: ";
            std::getline(std::cin, procesador);

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;

            std::cout << "RAM (en GB): ";
            std::cin >> ram;
            std::cin.ignore(1000, '\n');

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;
            std::cin.ignore(1000, '\n'); 

            // Constructor: Laptop
            computadora = Laptop(nombre, precio, marca, procesador, tamano, ram, condicion, cantidad_disponible);
            tiene_computadora = true;
            inventario.agregarLaptop(computadora);
            index_lap = inventario.getCantidad_laptops() - 1;
            computadora.mostrar_info();

        } else if (opcion == "3") {
            std::string nombre, marca, tipo_pantalla, smartTV, condicion;
            float precio, tamano;
            int cantidad_disponible;

            std::cout << "=== Agregar Televisor ===\n\n";
            std::cout << "Nombre: ";
            std::getline(std::cin, nombre);

            std::cout << "Precio: ";
            std::cin >> precio;
            std::cin.ignore(1000, '\n');

            std::cout << "Marca: ";
            std::getline(std::cin, marca);

            std::cout << "Tipo de pantalla: ";
            std::getline(std::cin, tipo_pantalla);

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;
            std::cin.ignore(1000, '\n');

            std::cout << "¿Es Smart TV? (Sí/No): ";
            std::getline(std::cin, smartTV);

            while (smartTV != "si" && smartTV != "sí" && smartTV != "no") {
                std::cout << "Valor inválido. Escriba si o no: ";
                std::getline(std::cin, smartTV);
            }

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::getline(std::cin, condicion);

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;
            std::cin.ignore(1000, '\n');

            // Constructor: Televisor
            tv = Televisor(nombre, precio, marca, tipo_pantalla, tamano, smartTV, condicion, cantidad_disponible);
            tiene_tv = true;
            inventario.agregarTelevisor(tv);
            index_tv = inventario.getCantidad_televisores() - 1;
            tv.mostrar_info();

        } else if (opcion == "4") {
            std::string modificar;
            std::cout << "Ingrese el producto a modificar (celular/laptop/televisor): ";
            std::cin >> modificar;
            std::cin.ignore(1000, '\n');

            std::string cond;
            float pre;
            int cant;

            if (modificar == "celular") {
                if (tiene_celular == true) {
                    inventario.mostrarInventario();
                    std::cout << "Ingrese el índice del celular a modificar (0 - " << inventario.getCantidad_smartphones()-1 << "): ";
                    int idx;
                    std::cin >> idx;
                    std::cin.ignore(1000, '\n');
                    if (idx < 0 || idx >= inventario.getCantidad_smartphones()){
                        std::cout << "Índice inválido. Operación cancelada.\n";
                    } else {
                        index_cel = idx;
                        std::cout << "Ingrese la nueva condición: ";
                        std::cin >> cond;
                        std::cout << "Ingrese el nuevo precio: ";
                        std::cin >> pre;
                        std::cout << "Ingrese la nueva cantidad disponible: ";
                        std::cin >> cant;
                        inventario.modificarSmartphone(index_cel, pre, cond, cant);
                        inventario.mostrarInventario();
                    }
                } else {
                    std::cout << "No hay un celular agregado aun.\n";
                }

            } else if (modificar == "laptop") {
                if (tiene_computadora == true) {
                    inventario.mostrarInventario();
                    std::cout << "Ingrese el índice de la laptop a modificar (0 - " << inventario.getCantidad_laptops()-1 << "): ";
                    int idx_l;
                    std::cin >> idx_l;
                    std::cin.ignore(1000, '\n');
                    if (idx_l < 0 || idx_l >= inventario.getCantidad_laptops()){
                        std::cout << "Índice inválido. Operación cancelada.\n";
                    } else {
                        index_lap = idx_l;
                        std::cout << "Ingrese la nueva condición: ";
                        std::cin >> cond;
                        std::cout << "Ingrese el nuevo precio: ";
                        std::cin >> pre;
                        std::cout << "Ingrese la nueva cantidad disponible: ";
                        std::cin >> cant;

                        inventario.modificarLaptop(index_lap, pre, cond, cant);
                        inventario.mostrarInventario();
                    }

                } else {
                    std::cout << "No hay una laptop agregada aun.\n";
                }

            } else if (modificar == "televisor") {
                if (tiene_tv == true) {
                    inventario.mostrarInventario();
                    std::cout << "Ingrese el índice del televisor a modificar (0 - " << inventario.getCantidad_televisores()-1 << "): ";
                    int idx_t;
                    std::cin >> idx_t;
                    std::cin.ignore(1000, '\n');
                    if (idx_t < 0 || idx_t >= inventario.getCantidad_televisores()){
                        std::cout << "Índice inválido. Operación cancelada.\n";
                    } else {
                        index_tv = idx_t;
                        std::cout << "Ingrese la nueva condición: ";
                        std::cin >> cond;
                        std::cout << "Ingrese el nuevo precio: ";
                        std::cin >> pre;
                        std::cout << "Ingrese la nueva cantidad disponible: ";
                        std::cin >> cant;

                        inventario.modificarTelevisor(index_tv, pre, cond, cant);
                        inventario.mostrarInventario();
                    }

                } else {
                    std::cout << "No hay un televisor agregado aun.\n";
                }
            }            

        } else {
            inventario.mostrarInventario();
            std::cout << "Saliendo del programa.\n";
            menu = false;
        }
    }
    return 0;
}
