# TecMarket
### Contexto
Una empresa lanzó una página web para vender productos tecnológicos. Para tener todo en orden y listo para mostrar en la plataforma, los empleados deben registrar los productos disponibles.

En este programa, el usuario es un empleado de la empresa y debe ingresar la información de los productos que se van a vender. Existen varias clases de productos: celulares, laptops y televisores. Si algún dato cambia, como el precio, el estado del producto o la cantidad disponible, esta información se puede actualizar antes de que el artículo sea publicado en la tienda en línea.

Además, el sistema cuenta con un inventario que permite organizar todos los productos en un solo lugar. Esto facilita buscarlos, modificar su información y prepararlos para la venta. Es importante tener en cuenta que los productos pueden existir dentro o fuera del inventario. Agregar un producto al inventario simplemente lo registra, y quitarlo no significa que el producto desaparezca del almacén. Incluso si el inventario fuera eliminado, los productos seguirían existiendo, ya que no dependen directamente de él.

Por otro lado, la relación entre los celulares y las tarjetas SIM funciona de manera distinta. En este sistema, una tarjeta SIM no puede existir si no está asociada a un celular. Cada SIM va ligada a un teléfono y se gestiona junto con él. Por esa razón, si se elimina un celular del sistema, también se eliminan las tarjetas SIM que tenga asociadas, ya que no tienen utilidad por sí solas.


### UML


### Instrucciones
Descarga los archivos y corre el programa en la terminal. <img width="4216" height="3429" alt="Diagrama de clases" src="https://github.com/user-attachments/assets/276b2e72-590c-4425-bf2c-6b70724a6cc8" />

El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos
Añade la información del artículo que desees, sin embargo, recuerda asegurarte de ingresar de forma correcta el tipo de dato. 

Compilar con: ´g++ main.cpp -o main´
Correr en linux: ´main.out´
Correr en Windows: ´.\/main.exe´

### Correcciones
para este programa se relizaron las siguientes correcciones:

1 Se arregló el estilo en las clases de Electronico.h, Inventario.h, Laptop.h, Televisor.h, SIM.h, Smartphone.h y en el main.cpp.

2 Se validaron inputs en ciertas entradas para asegurarme de que el usuario ingrese el tipo de dato que se espera y que el programa no falle.

3 Se corrigió la herencia en la clase de Smartphone.h para que el programa pudiera correr de forma adecuada.

4 Antes en el menú solo estaba la opción de ver inventario cuando el usuario deseara salir del programa, ahora están separados en dos opciones distintas para que el usuario pueda ver el inventario en caso de que todavía no quiera salir. Al mismo tiempo, está la opción de salir del programa en caso de que el usuario no desea ver el inventario.
