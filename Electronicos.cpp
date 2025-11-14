#include <iostream>
#include <string>
#include "Smartphone.h"
#include "Laptop.h"
#include "Televisor.h"

int main(){
    bool menu = true;
    Smartphone celular;
    Laptop computadora;
    Televisor tv;
    bool tiene_celular = false;
    bool tiene_computadora = false;
    bool tiene_tv = false;

    while (menu == true){
        std::string opcion;
        std::cout << "Seleccione lo que desea hacer:\n";
        std::cout << "1: Agregar celular\n";
        std::cout << "2: Agregar laptop\n";
        std::cout << "3: Agregar televisor\n";
        std::cout << "4: Modificar algún dato\n";
        std::cout << "Cualquier otro botón: Salir\n";
        std::cin >> opcion;

        if (opcion == "1") {
            std::string nombre, marca, condicion;
            int memoria, cantidad_disponible;
            float precio, tamano;

            std::cout << "=== Agregar Celular ===\n\n";
            
            std::cout << "Nombre: ";
            std::cin >> nombre;

            std::cout << "Marca: ";
            std::cin >> marca;

            std::cout << "Memoria (en GB): ";
            std::cin >> memoria;  

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::cin >> condicion;

            std::cout << "Precio:\n";
            std::cin >> precio;

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;

            celular = Smartphone(nombre, precio, marca, memoria, tamano, condicion, cantidad_disponible);
            tiene_celular = true;
            celular.mostrar_info();

        } else if (opcion == "2") {
            std::string nombre, marca, procesador, condicion;
            float precio, tamano;
            int ram, cantidad_disponible;
            std::cout << "=== Agregar Laptop ===\n\n";
            std::cout << "Nombre: ";
            std::cin >> nombre;

            std::cout << "Marca: ";
            std::cin >> marca;

            std::cout << "Procesador: ";
            std::cin >> procesador;

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::cin >> condicion;

            std::cout << "RAM (en GB): ";
            std::cin >> ram;

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;

            std::cout << "Precio:\n";
            std::cin >> precio;

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;

            computadora = Laptop(nombre, precio, marca, procesador, tamano, ram, condicion, cantidad_disponible);
            tiene_computadora = true;
            computadora.mostrar_info();

        } else if (opcion == "3") {
            std::string nombre, marca, tipo_pantalla, smartTV, condicion;
            float precio, tamano;
            int cantidad_disponible;
            std::cout << "=== Agregar Televisor ===\n\n";
            std::cout << "Nombre: ";
            std::cin >> nombre;

            std::cout << "Marca: ";
            std::cin >> marca;

            std::cout << "Tipo de pantalla: ";
            std::cin >> tipo_pantalla;

            std::cout << "¿Es Smart TV? (Sí/No): ";
            std::cin >> smartTV;

            std::cout << "Condición (Nuevo/Usado/Reacondicionado): ";
            std::cin >> condicion;

            std::cout << "Tamaño (en pulgadas): ";
            std::cin >> tamano;

            std::cout << "Precio:\n";
            std::cin >> precio;

            std::cout << "Cantidad disponible: ";
            std::cin >> cantidad_disponible;

            tv = Televisor(nombre, precio, marca, tipo_pantalla, tamano, smartTV, condicion, cantidad_disponible);
            tiene_tv = true;
            tv.mostrar_info();

        } else if (opcion == "4") {
            std::string modificar;
            std::cout << "Ingrese el producto a modificar: ";
            std::cin >> modificar;
            if (modificar == "celular") {
                if (tiene_celular == true) {
                    std::string cond;
                    float pre;
                    std::cout << "Ingrese la nueva condición: ";
                    std::cin >> cond;
                    std::cout << "Ingrese el nuevo precio: ";
                    std::cin >> pre;
                    int cant;
                    std::cout << "Ingrese la nueva cantidad disponible: ";
                    std::cin >> cant;
                    celular.setCondicion(cond);
                    celular.setPrecio(pre);
                    celular.setCantidad_disponible(cant);
                    celular.mostrar_info();
                } else {
                    std::cout << "No hay un celular agregado aun.\n";
                }

            } else if (modificar == "laptop") {
                if (tiene_computadora == true) {
                    std::string cond;
                    float pre;
                    std::cout << "Ingrese la nueva condición: ";
                    std::cin >> cond;
                    std::cout << "Ingrese el nuevo precio: ";
                    std::cin >> pre;
                    computadora.setCondicion(cond);
                    computadora.setPrecio(pre);
                    computadora.mostrar_info();
                } else {
                    std::cout << "No hay una laptop agregada aun.\n";
                }

            } else if (modificar == "televisor") {
                if (tiene_tv == true) {
                    std::string cond;
                    float pre;
                    std::cout << "Ingrese la nueva condición: ";
                    std::cin >> cond;
                    std::cout << "Ingrese el nuevo precio: ";
                    std::cin >> pre;
                    tv.setCondicion(cond);
                    tv.setPrecio(pre);
                    tv.mostrar_info();
                } else {
                    std::cout << "No hay un televisor agregado aun.\n";
                }
            }            

        } else {
            std::cout << "Saliendo del programa.\n";
            menu = false;
        }
    }
    return 0;
}
