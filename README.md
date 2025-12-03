# TecMarket
### Contexto
Una empresa lanzó una página web para vender productos tecnológicos. Para tener todo en orden y listo para mostrar en la plataforma, los empleados deben registrar los productos disponibles.

En este programa, el usuario es un empleado de la empresa y debe ingresar la información de los productos que se van a vender. Existen varias clases de productos: celulares, laptops y televisores. Si algún dato cambia, como el precio, el estado del producto o la cantidad disponible, esta información se puede actualizar antes de que el artículo sea publicado en la tienda en línea.

Además, el sistema cuenta con un inventario que permite organizar todos los productos en un solo lugar. Esto facilita buscarlos, modificar su información y prepararlos para la venta. Es importante tener en cuenta que los productos pueden existir dentro o fuera del inventario. Agregar un producto al inventario simplemente lo registra, y quitarlo no significa que el producto desaparezca del almacén. Incluso si el inventario fuera eliminado, los productos seguirían existiendo, ya que no dependen directamente de él.

Por otro lado, la relación entre los celulares y las tarjetas SIM funciona de manera distinta. En este sistema, una tarjeta SIM no puede existir si no está asociada a un celular. Cada SIM va ligada a un teléfono y se gestiona junto con él. Por esa razón, si se elimina un celular del sistema, también se eliminan las tarjetas SIM que tenga asociadas, ya que no tienen utilidad por sí solas.


### UML
![uml]("./Diagrama de clases.png")

### Instrucciones
Descarga los archivos y corre el programa en la terminal. 
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos
Añade la información del artículo que desees, sin embargo, recuerda asegurarte de ingresar de forma correcta el tipo de dato. 

Compilar con: ´g++ main.cpp -o main´
Correr en linux: ´main.out´
Correr en Windows: ´.\/main.exe´
