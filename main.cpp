/*
 * Proyecto TecMarket
 * Rashell Aleck Jiménez Almánzar
 * A01715359
 * 04/12/2025
 */

#include <iostream> /**< Librería para entrada y salida estándar */
#include <limits>   /**< Librería para límites de tipo numérico */
#include <string>   /**< Librería para manejo de cadenas de texto */

#include "Inventario.h" /**< Incluye la definición de la clase Inventario */
#include "Laptop.h"     /**< Incluye la definición de la clase Laptop */
#include "Smartphone.h" /**< Incluye la definición de la clase Smartphone */
#include "Televisor.h"  /**< Incluye la definición de la clase Televisor */

/**
 * Función para leer un número entero desde la entrada estándar.
 *
 * Esta función asegura que el número ingresado sea mayor o igual a minVal.
 * Si la entrada no es válida, solicita nuevamente al usuario.
 *
 * @param minVal Valor mínimo permitido para la entrada.
 * @return Número entero ingresado por el usuario.
 */
int getInt(int minVal) {
    int number; /**< Variable para almacenar el número ingresado */
    while (true) {
        if (std::cin >> number &&
            number >= minVal) { /**< Verifica que la entrada sea válida */
            return number;      /**< Retorna el número ingresado */
        }
        std::cout
            << "Entrada invalida, intenta otra vez.\n"; /**< Mensaje de
                                                           error si la
                                                           entrada no es
                                                           válida */
        std::cin.clear(); /**< Limpia el estado de error de std::cin */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Ignora la entrada incorrecta */
    }
}

/**
 * Función para leer un número flotante desde la entrada estándar.
 *
 * Esta función asegura que el número ingresado sea mayor o igual a minVal.
 * Si la entrada no es válida, solicita nuevamente al usuario.
 *
 * @param minVal Valor mínimo permitido para la entrada.
 * @return Número flotante ingresado por el usuario.
 */
float getFloat(float minVal) {
    float number; /**< Variable para almacenar el número ingresado */
    while (true) {
        if (std::cin >> number &&
            number >= minVal) { /**< Verifica que la entrada sea válida */
            return number;      /**< Retorna el número ingresado */
        }
        std::cout << "Entrada inválida, intenta otra vez."
                  << std::endl; /**< Mensaje de error */
        std::cin.clear(); /**< Limpia el estado de error de std::cin */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Ignora la entrada incorrecta */
    }
}

/**
 * Función para validar el tipo de SIM ingresado por el usuario.
 *
 * Permite únicamente "Nano" o "Micro" en cualquier combinación de
 * mayúsculas/minúsculas. Repite la solicitud hasta que el dato ingresado
 * sea válido.
 *
 * @param dato Valor ingresado por el usuario.
 * @return Tipo de SIM validado.
 */
std::string validarTipoSim(std::string dato) {
    while (dato != "Nano" && dato != "Micro" && dato != "nano" &&
           dato != "micro" && dato != "NANO" && dato != "MICRO") {
        std::cout << "Valor invalido. Ingrese (Nano/Micro): "
                  << std::endl;       /**< Mensaje de error */
        std::getline(std::cin, dato); /**< Lectura de nuevo dato */
    }
    return dato; /**< Retorna el dato validado */
}

/**
 * Función para validar la condición de un producto ingresado por el
 * usuario.
 *
 * Solo permite "Nuevo", "Usado" o "Reacondicionado" (cualquier combinación
 * de mayúsculas/minúsculas). Repite la solicitud hasta que el dato sea
 * válido.
 *
 * @param dato Valor ingresado por el usuario.
 * @return Condición validada.
 */
std::string validarCondicion(std::string dato) {
    while (
        dato != "Nuevo" && dato != "Usado" && dato != "Reacondicionado" &&
        dato != "nuevo" && dato != "usado" && dato != "reacondicionado" &&
        dato != "NUEVO" && dato != "USADO" && dato != "REACONDICIONADO") {
        std::cout
            << "Valor invalido. Ingrese (Nuevo/Usado/Reacondicionado): "
            << std::endl;             /**< Mensaje de error */
        std::getline(std::cin, dato); /**< Lectura de nuevo dato */
    }
    return dato; /**< Retorna la condición validada */
}

/**
 * Función para validar el tipo de producto ingresado por el usuario.
 *
 * Solo permite "Celular", "Laptop" o "Televisor" (cualquier combinación de
 * mayúsculas/minúsculas). Repite la solicitud hasta que el dato sea válido.
 *
 * @param dato Valor ingresado por el usuario.
 * @return Producto validado.
 */
std::string validarProducto(std::string dato) {
    while (dato != "Celular" && dato != "Laptop" && dato != "Televisor" &&
           dato != "celular" && dato != "laptop" && dato != "televisor" &&
           dato != "CELULAR" && dato != "LAPTOP" && dato != "TELEVISOR") {
        std::cout << "Valor invalido. Ingrese (Celular/Laptop/Televisor): "
                  << std::endl;       /**< Mensaje de error */
        std::getline(std::cin, dato); /**< Lectura de nuevo dato */
    }
    return dato; /**< Retorna el producto validado */
}

/**
 * Función principal del programa.
 *
 * Permite al usuario agregar celulares, laptops o televisores al
 * inventario, modificar los datos de productos existentes y ver el
 * inventario completo.
 *
 * @return 0 si el programa finaliza correctamente.
 */
int main() {
    Inventario inventario; /**< Objeto que almacena todos los productos del
                              inventario */
    std::string opcion = "0"; /**< Variable para almacenar la opción
                                 seleccionada por el usuario */

    while (opcion != "6") { /**< Ciclo principal del menú, termina cuando el
                               usuario selecciona "6" */
        std::cout
            << "\nSeleccione lo que desea hacer:\n"; /**< Muestra las
                                                        opciones del menú */
        std::cout << "1: Agregar celular\n";         /**< Opción 1 */
        std::cout << "2: Agregar laptop\n";          /**< Opción 2 */
        std::cout << "3: Agregar televisor\n";       /**< Opción 3 */
        std::cout << "4: Modificar datos\n";         /**< Opción 4 */
        std::cout << "5: Ver inventario\n";          /**< Opción 5 */
        std::cout << "6: Salir\n";                   /**< Opción 6 */
        std::cin >> opcion; /**< Lectura de la opción ingresada */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Limpieza del buffer de entrada */

        // ================= AGREGAR CELULAR =================
        if (opcion == "1") {
            std::string nombre, marca,
                condicion; /**< Variables para almacenar atributos del
                              celular */
            int memoria, cantidadDisponible; /**< Variables para memoria y
                                                cantidad disponible */
            float precio, tamano; /**< Variables para precio y tamaño */
            std::string numSim, operSim,
                tipoSim; /**< Variables para información de la SIM */

            std::cout << "=== Agregar Celular ===\n\n"; /**< Título de la
                                                           sección */

            std::cout << "Nombre: "; /**< Solicita nombre del celular */
            std::getline(std::cin, nombre); /**< Lectura del nombre */

            std::cout << "Precio: "; /**< Solicita precio */
            precio = getFloat(1.0);  /**< Llama a la función para validar
                                        precio mínimo 1 */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "Marca: ";        /**< Solicita marca */
            std::getline(std::cin, marca); /**< Lectura de marca */

            std::cout << "Memoria (en GB): "; /**< Solicita memoria */
            memoria = getInt(1);         /**< Valida memoria mínima 1 GB */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "Tamaño (en pulgadas): "; /**< Solicita tamaño */
            tamano = getFloat(1.0); /**< Valida tamaño mínimo 1 pulgada */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout
                << "Condicion (Nuevo/Usado/Reacondicionado): "; /**<
                                                                   Solicita
                                                                   condición
                                                                 */
            std::getline(std::cin, condicion); /**< Lectura de condición */
            condicion =
                validarCondicion(condicion); /**< Validación de condición */

            std::cout << "Cantidad disponible: "; /**< Solicita cantidad
                                                     disponible */
            cantidadDisponible =
                getInt(1); /**< Validación de cantidad mínima 1 */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "Numero de SIM: "; /**< Solicita número de SIM */
            std::getline(std::cin,
                         numSim); /**< Lectura del número de SIM */

            std::cout
                << "Operador de SIM: "; /**< Solicita operador de SIM */
            std::getline(std::cin,
                         operSim); /**< Lectura del operador de SIM */

            std::cout << "Tipo de SIM: (Nano/Micro) "; /**< Solicita tipo de
                                                          SIM */
            std::getline(std::cin, tipoSim); /**< Lectura del tipo de SIM */
            tipoSim =
                validarTipoSim(tipoSim); /**< Validación del tipo de SIM */

            int activoSimInput; /**< Variable temporal para estado de SIM */
            std::cout
                << "¿Esta activa la SIM? (1: Sí, 0: No): "; /**< Solicita
                                                               estado de la
                                                               SIM */
            activoSimInput = getInt(0); /**< Validación de entrada */

            while (activoSimInput != 0 &&
                   activoSimInput != 1) { /**< Asegura que solo sea 0 o 1 */
                std::cout
                    << "Valor invalido. Ingrese 1 (Si) o 0 (No): "; /**<
                                                                       Mensaje
                                                                       de
                                                                       error
                                                                     */
                activoSimInput = getInt(0); /**< Relectura */
            }

            bool activoSim =
                (activoSimInput == 1); /**< Convierte a booleano */

            // Creación del objeto Smartphone con los datos ingresados
            Smartphone celular(nombre, precio, marca, memoria, tamano,
                               condicion, cantidadDisponible, numSim,
                               operSim, tipoSim, activoSim);
            inventario.agregarSmartphone(
                celular); /**< Agrega el celular al inventario */
            std::cout << "\nSMARTPHONE AGREGADO:\n\n"; /**< Mensaje de
                                                          confirmación */
            std::cout << celular.mostrarInfo(); /**< Muestra la información
                                                   completa del celular */
        }

        // ================= AGREGAR LAPTOP =================
        else if (opcion == "2") {
            std::string nombre, marca, procesador,
                condicion;        /**< Variables para atributos de laptop */
            float precio, tamano; /**< Variables para precio y tamaño */
            int ram, cantidadDisponible; /**< Variables para RAM y cantidad
                                            disponible */

            std::cout
                << "=== Agregar Laptop ===\n\n"; /**< Título de sección */

            std::cout << "Nombre: ";        /**< Solicita nombre */
            std::getline(std::cin, nombre); /**< Lectura del nombre */

            std::cout << "Precio: ";     /**< Solicita precio */
            precio = getFloat(1.0);      /**< Validación de precio mínimo */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "Marca: ";        /**< Solicita marca */
            std::getline(std::cin, marca); /**< Lectura de marca */

            std::cout << "Procesador: "; /**< Solicita procesador */
            std::getline(std::cin,
                         procesador); /**< Lectura de procesador */

            std::cout << "Tamaño (en pulgadas): "; /**< Solicita tamaño */
            tamano = getFloat(1.0);      /**< Validación de tamaño mínimo */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "RAM (en GB): "; /**< Solicita RAM */
            ram = getInt(1);              /**< Validación de RAM mínima */
            std::cin.ignore(1000, '\n');  /**< Limpieza de buffer */

            std::cout
                << "Condicion (Nuevo/Usado/Reacondicionado): "; /**<
                                                                   Solicita
                                                                   condición
                                                                 */
            std::getline(std::cin, condicion); /**< Lectura de condición */
            condicion =
                validarCondicion(condicion); /**< Validación de condición */

            std::cout << "Cantidad disponible: "; /**< Solicita cantidad */
            cantidadDisponible =
                getInt(1); /**< Validación de cantidad mínima */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            // Creación del objeto Laptop con los datos ingresados
            Laptop computadora(nombre, precio, marca, procesador, tamano,
                               ram, condicion, cantidadDisponible);
            inventario.agregarLaptop(
                computadora); /**< Agrega la laptop al inventario */
            std::cout
                << "\nLAPTOP AGREGADA:\n\n"; /**< Mensaje de confirmación */
            std::cout
                << computadora.mostrarInfo(); /**< Muestra información
                                                 completa de la laptop */
        }

        // ================= AGREGAR TELEVISOR =================
        else if (opcion == "3") {
            std::string nombre, marca, tipoPantalla, smartTV,
                condicion; /**< Variables para atributos del televisor */
            float precio, tamano;   /**< Variables para precio y tamaño */
            int cantidadDisponible; /**< Variable para cantidad disponible
                                     */

            std::cout << "=== Agregar Televisor ===\n\n"; /**< Título de
                                                             sección */

            std::cout << "Nombre: ";        /**< Solicita nombre */
            std::getline(std::cin, nombre); /**< Lectura de nombre */

            std::cout << "Precio: ";     /**< Solicita precio */
            precio = getFloat(1.0);      /**< Validación de precio mínimo */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "Marca: ";        /**< Solicita marca */
            std::getline(std::cin, marca); /**< Lectura de marca */

            std::cout
                << "Tipo de pantalla: "; /**< Solicita tipo de pantalla */
            std::getline(std::cin,
                         tipoPantalla); /**< Lectura de tipo de pantalla */

            std::cout << "Tamaño (en pulgadas): "; /**< Solicita tamaño */
            tamano = getFloat(1.0);      /**< Validación de tamaño mínimo */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            std::cout << "¿Es Smart TV? (Si/No): "; /**< Solicita si es
                                                       Smart TV */
            std::getline(std::cin, smartTV); /**< Lectura del valor */
            while (smartTV != "si" && smartTV != "no" && smartTV != "Si" &&
                   smartTV != "No" && smartTV != "SI" && smartTV != "NO") {
                std::cout
                    << "Valor invalido. Escriba si o no: "; /**< Mensaje de
                                                               error */
                std::getline(std::cin, smartTV); /**< Relectura */
            }

            std::cout
                << "Condicion (Nuevo/Usado/Reacondicionado): "; /**<
                                                                   Solicita
                                                                   condición
                                                                 */
            std::getline(std::cin, condicion); /**< Lectura de condición */
            condicion =
                validarCondicion(condicion); /**< Validación de condición */

            std::cout << "Cantidad disponible: "; /**< Solicita cantidad */
            cantidadDisponible =
                getInt(1); /**< Validación de cantidad mínima */
            std::cin.ignore(1000, '\n'); /**< Limpieza de buffer */

            // Creación del objeto Televisor con los datos ingresados
            Televisor tv(nombre, precio, marca, tipoPantalla, tamano,
                         smartTV, condicion, cantidadDisponible);
            inventario.agregarTelevisor(
                tv); /**< Agrega el televisor al inventario */
            std::cout << "\nTELEVISOR AGREGADO:\n\n"; /**< Mensaje de
                                                         confirmación */
            std::cout << tv.mostrarInfo(); /**< Muestra información completa
                                              del televisor */
        }

        // ================= MODIFICAR PRODUCTOS =================
        else if (opcion == "4") {
            std::string modificar; /**< Variable para almacenar el tipo de
                                      producto a modificar */
            std::cout
                << "Ingrese el producto a modificar "
                   "(celular/laptop/televisor): "; /**< Solicita producto */
            std::getline(std::cin, modificar); /**< Lectura de producto */
            modificar =
                validarProducto(modificar); /**< Validación del producto */

            std::string cond; /**< Nueva condición */
            float pre;        /**< Nuevo precio */
            int cant;         /**< Nueva cantidad */

            // Modificación de celular
            if (modificar == "celular" || modificar == "Celular" ||
                modificar == "CELULAR") {
                if (inventario.getCantidadSmartphones() >
                    0) { /**< Verifica que haya celulares en inventario */
                    std::cout
                        << inventario.mostrarInventario(); /**< Muestra
                                                              inventario */
                    std::cout
                        << "Ingrese el índice del celular a modificar (0 - "
                        << inventario.getCantidadSmartphones() - 1
                        << "): "; /**< Solicita índice */
                    int idx =
                        getInt(0); /**< Lectura y validación de índice */
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Limpieza de buffer */

                    if (idx < 0 ||
                        idx >=
                            inventario
                                .getCantidadSmartphones()) { /**< Verifica
                                                                índice
                                                                válido */
                        std::cout << "Indice invalido. Operacion "
                                     "cancelada.\n"; /**< Mensaje de error
                                                      */
                    } else {
                        std::cout
                            << "Ingrese la nueva condicion: "; /**< Solicita
                                                                  nueva
                                                                  condición
                                                                */
                        std::getline(std::cin,
                                     cond); /**< Lectura condición */
                        cond = validarCondicion(cond); /**< Validación */

                        std::cout << "Nuevo precio: "; /**< Solicita nuevo
                                                          precio */
                        pre = getFloat(1.0); /**< Validación de precio */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        std::cout << "Nueva cantidad: "; /**< Solicita nueva
                                                            cantidad */
                        cant = getInt(1); /**< Validación de cantidad */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        inventario.modificarSmartphone(
                            idx, pre, cond, cant); /**< Modifica celular */
                    }
                } else {
                    std::cout
                        << "No hay un celular agregado aun.\n"; /**< Mensaje
                                                                   si no hay
                                                                   celulares
                                                                 */
                }
            }
            // Modificación de laptop
            else if (modificar == "laptop" || modificar == "Laptop" ||
                     modificar == "LAPTOP") {
                if (inventario.getCantidadLaptops() >
                    0) { /**< Verifica que haya laptops */
                    std::cout
                        << inventario.mostrarInventario(); /**< Muestra
                                                              inventario */
                    std::cout << "Ingrese el indice de la laptop a "
                                 "modificar (0 - "
                              << inventario.getCantidadLaptops() - 1
                              << "): "; /**< Solicita índice */
                    int idx =
                        getInt(0); /**< Lectura y validación de índice */
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Limpieza de buffer */

                    if (idx < 0 ||
                        idx >=
                            inventario
                                .getCantidadLaptops()) { /**< Verifica
                                                            índice válido */
                        std::cout << "Indice invalido. Operacion "
                                     "cancelada.\n"; /**< Mensaje de error
                                                      */
                    } else {
                        std::cout
                            << "Ingrese la nueva condicion: "; /**< Solicita
                                                                  nueva
                                                                  condición
                                                                */
                        std::getline(std::cin,
                                     cond); /**< Lectura condición */
                        cond = validarCondicion(cond); /**< Validación */

                        std::cout << "Nuevo precio: "; /**< Solicita nuevo
                                                          precio */
                        pre = getFloat(1.0); /**< Validación de precio */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        std::cout << "Nueva cantidad: "; /**< Solicita nueva
                                                            cantidad */
                        cant = getInt(1); /**< Validación de cantidad */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        inventario.modificarLaptop(
                            idx, pre, cond, cant); /**< Modifica laptop */
                    }
                } else {
                    std::cout
                        << "No hay una laptop agregada aun.\n"; /**< Mensaje
                                                                   si no hay
                                                                   laptops
                                                                 */
                }
            }
            // Modificación de televisor
            else if (modificar == "televisor" || modificar == "Televisor" ||
                     modificar == "TELEVISOR") {
                if (inventario.getCantidadTelevisores() >
                    0) { /**< Verifica que haya televisores */
                    std::cout
                        << inventario.mostrarInventario(); /**< Muestra
                                                              inventario */
                    std::cout << "Ingrese el indice del televisor a "
                                 "modificar (0 - "
                              << inventario.getCantidadTelevisores() - 1
                              << "): "; /**< Solicita índice */
                    int idx =
                        getInt(0); /**< Lectura y validación de índice */
                    std::cin.ignore(
                        std::numeric_limits<std::streamsize>::max(),
                        '\n'); /**< Limpieza de buffer */

                    if (idx < 0 ||
                        idx >=
                            inventario
                                .getCantidadTelevisores()) { /**< Verifica
                                                                índice
                                                                válido */
                        std::cout << "Indice invalido. Operacion "
                                     "cancelada.\n"; /**< Mensaje de error
                                                      */
                    } else {
                        std::cout
                            << "Ingrese la nueva condicion: "; /**< Solicita
                                                                  nueva
                                                                  condición
                                                                */
                        std::getline(std::cin,
                                     cond); /**< Lectura condición */
                        cond = validarCondicion(cond); /**< Validación */

                        std::cout << "Nuevo precio: "; /**< Solicita nuevo
                                                          precio */
                        pre = getFloat(1.0); /**< Validación de precio */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        std::cout << "Nueva cantidad: "; /**< Solicita nueva
                                                            cantidad */
                        cant = getInt(1); /**< Validación de cantidad */
                        std::cin.ignore(1000,
                                        '\n'); /**< Limpieza de buffer */

                        inventario.modificarTelevisor(
                            idx, pre, cond,
                            cant); /**< Modifica televisor */
                    }
                } else {
                    std::cout
                        << "No hay un televisor agregado aun.\n"; /**<
                                                                     Mensaje
                                                                     si no
                                                                     hay
                                                                     tvs
                                                                   */
                }
            }
        }
        // ================= VER INVENTARIO =================
        else if (opcion == "5") {
            std::cout
                << inventario
                       .mostrarInventario(); /**< Muestra todos los
                                                productos del inventario */
        }
        // ================= SALIR =================
        else if (opcion == "6") {
            std::cout
                << "Saliendo del programa.\n"; /**< Mensaje de salida */
        }
        // ================= OPCIÓN INVÁLIDA =================
        else {
            std::cout
                << "Opcion invalida. Intente nuevamente.\n"; /**< Mensaje de
                                                                error */
        }
    }

    return 0; /**< Retorna 0 indicando que el programa finalizó
                 correctamente */
}
