#ifndef TRABAJADOR_H_INCLUDED
#define TRABAJADOR_H_INCLUDED
#include <string.h>
class Trabajador{
    private:
        int id;
        string nombre;
        string apellido;
        float sueldoMensual;
        float dIsss;
        float dAfp;
        float dIsr;
        float totalDescuento;
        float totalPagar;
        void calcular(){
            ///Haciendo los calculo una vez se conozca el sm
            this -> dIsss = 0;
            this -> dAfp = 0;
            this -> dIsr = 0;
            this -> totalDescuento =0;
            //uso de operador ternario, " condicion " ? "si se cumple" : "si no se cumple"
            this -> dIsss = (this -> sueldoMensual <= 1000) ? this -> sueldoMensual * 0.03 : 30;
            this -> dAfp = (this -> sueldoMensual <= 7500) ? this -> sueldoMensual * 0.0725 : 543.75;

            float antesISR = this -> sueldoMensual - (this -> dIsss + this -> dAfp);

            if(antesISR <= 472){
                this -> dIsr = 0;
            }else if(antesISR <= 895.24){
                this -> dIsr = ((this -> sueldoMensual - 472) * 0.10) + 17.67;
            }else if(antesISR <= 2038.10){
                this -> dIsr = ((this -> sueldoMensual - 895.24) * 0.20) + 60;
            }else if(antesISR >= 2038.11){
                this -> dIsr = ((this -> sueldoMensual - 2038.10) * 0.30) + 288.57;
            }

            this -> totalDescuento = this -> dIsss + this -> dAfp + this -> dIsr;

            this -> totalPagar = this -> sueldoMensual - this -> totalDescuento;
        }
    public:
        Trabajador(int id, string n, string a, float sm){
            this -> id = id;
            this -> nombre = n;
            this -> apellido = a;
            this -> sueldoMensual = sm;
            this -> dIsr = 0;
            this -> dAfp = 0;
            this -> dIsss = 0;
            this -> totalDescuento = 0;
            this -> totalPagar = 0;
            this -> calcular();
        }
        int getId(){
            return this->id;
        }
        string getNombre(){
            return this->nombre;
        }
        string getApellido(){
            return this->apellido;
        }
        float getSueldoMensual(){
            return this->sueldoMensual;
        }
        float getDescuentoIsss(){
            return this->dIsss;
        }
        float getDescuentoAfp(){
            return this->dAfp;
        }
        float getDescuentoIsr(){
            return this->dIsr;
        }
        float getTotalDescuentos(){
            return this->totalDescuento;
        }
        float getTotalPagar(){
            return this->totalPagar;
        }
};
#endif // TRABAJADOR_H_INCLUDED
