#include <iostream>
#include <string>

class Televisor{
    private:
        std::string nombre;
        float precio;
        std:: string marca;
        std:: string tipo_pantalla;
        float tamano;
        std::string smartTV;
        std:: string condicion;
        int cantidad_disponible;

    public:
        Televisor(): nombre(""), precio(0.0), marca(""), tipo_pantalla(""), tamano(0.0), smartTV("No"), condicion(""), cantidad_disponible(0){};
        Televisor(std::string nom, float pre, std:: string mar, std:: string pan, float tam, std:: string tv, std:: string cond, int cant): 
            nombre(nom), precio(pre), marca(mar), tipo_pantalla(pan), tamano(tam), smartTV(tv), condicion(cond), cantidad_disponible(cant){}

        std::string getNombre();
        float getPrecio();
        std:: string getMarca();
        std:: string getTipo_pantalla();
        float getTamano();
        std:: string getSmartTV();
        std:: string getCondicion();
        int getCantidad_disponible();

        void setPrecio(float );
        void setCondicion(std::string );
        void setCantidad_disponible(int );

        void mostrar_info();
        float calcular_valor_stock();
};

        std::string Televisor::getNombre(){
            return nombre;
        }

        float Televisor::getPrecio(){
            return precio;
        }

        std:: string Televisor::getMarca(){
            return marca;
        }

        std:: string Televisor::getTipo_pantalla(){
            return tipo_pantalla;
        }

        float Televisor::getTamano(){
            return tamano;
        }

        std::string Televisor::getSmartTV(){
            return smartTV;
        }

        std:: string Televisor::getCondicion(){
            return condicion;
        }

        void Televisor::setPrecio(float pre){
            precio = pre;
        }

        int Televisor::getCantidad_disponible(){
            return cantidad_disponible;
        }

        void Televisor::setCondicion(std::string cond){
            condicion = cond;
        }

        void Televisor::setCantidad_disponible(int cant){
            cantidad_disponible = cant;
        }

        float Televisor::calcular_valor_stock(){
            return precio * cantidad_disponible;
        }

        void Televisor::mostrar_info(){
            std::cout << "Nombre: " << nombre
                      << "\nPrecio: $" << precio
                      << "\nMarca: " << marca
                      << "\nTipo de pantalla: " << tipo_pantalla
                      << "\nTamaño: " << tamano << " pulgadas"
                      << "\nEs Smart TV: " << smartTV
                      << "\nCondición: " << condicion
                      << "\nCantidad disponible: " << cantidad_disponible
                      << "\nValor total en stock: $" << calcular_valor_stock()
                      << "\n\n";
        }
        
