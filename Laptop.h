#include <iostream>
#include <string>   

class Laptop{
    private:
        std::string nombre;
        float precio;
        std:: string marca;
        std:: string procesador;
        float tamano;
        int ram;
        std:: string condicion;
        int cantidad_disponible;

    public:
        Laptop(): nombre(""), precio(0.0), marca(""), procesador(""), tamano(0), ram(0), condicion(""), cantidad_disponible(0){};
        Laptop(std::string nom, float pre, std:: string mar, std:: string pro, float tam, int r, std:: string cond, int cant): 
            nombre(nom), precio(pre),  marca(mar), procesador(pro), tamano(tam), ram(r), condicion(cond), cantidad_disponible(cant){}

        std::string getNombre();
        float getPrecio();
        std:: string getMarca();
        std:: string getProcesador();
        float getTamano();
        int getRam();
        std:: string getCondicion();
        int getCantidad_disponible();

        void setPrecio(float );
        void setCantidad_disponible(int );
        void setCondicion(std::string );

        void mostrar_info();
        float calcular_valor_stock();
};


        std::string Laptop::getNombre(){
            return nombre;
        }

        float Laptop::getPrecio(){
            return precio;
        }

        std:: string Laptop::getMarca(){
            return marca;
        }

        std:: string Laptop::getProcesador(){
            return procesador;
        }

        float Laptop::getTamano(){
            return tamano;
        }

        int Laptop::getRam(){
            return ram;
        }

        std:: string Laptop::getCondicion(){
            return condicion;
        }

        int Laptop::getCantidad_disponible(){
            return cantidad_disponible;
        }

        void Laptop::setPrecio(float pre){
            precio = pre;
        }

        void Laptop::setCondicion(std::string cond){
            condicion = cond;
        }

        void Laptop::setCantidad_disponible(int cant){
            cantidad_disponible = cant;
        }

        float Laptop::calcular_valor_stock(){
            return precio * cantidad_disponible;
        }

        void Laptop::mostrar_info(){
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nProcesador: " << procesador
                      << "\nTamaño: " << tamano << " pulgadas"
                      << "\nRAM: " << ram << " GB"
                      << "\nCondición: " << condicion
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock()
                      << "\n\n";
}

