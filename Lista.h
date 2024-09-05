#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Nodo.h"
class Lista{
    private:
        Nodo *elemento;
        bool ListaVacia(){
            ///SI DEVUELVE NULO ES PORQUE NO CONTIENE NADA "elemento"
            return (this -> elemento == NULL);
        }
        Nodo *Inicio(){
            Nodo *tmp = NULL;
            if (!this -> ListaVacia()){
                tmp = this -> elemento;
                while (tmp -> Anterior){
                    tmp = tmp -> Anterior;
                }
            }
            return tmp;
        }
        Nodo *Buscar(int id){
            bool encontrado = false;
            Nodo *tmp = this -> elemento;
            Nodo *retorno = NULL;
            while (tmp && !encontrado){
                if (tmp -> Valor -> getId() == id){
                    encontrado = true;
                    retorno = tmp;
                }else{
                    tmp = tmp -> Anterior;
                }
            }
            return retorno;
        }
    public:
        Lista(){
            this -> elemento = NULL;
        }
        ~Lista(){
            ///DESTRUCTOR VACÍO
        }
        void InsertarAlFinal(Trabajador *tb){
            Nodo *nuevo = new Nodo(tb);
            if (this->ListaVacia()){
                this->elemento = nuevo;
            }else{
                nuevo->Anterior = this->elemento; ///LE DECIMOS AL NUEVO NODO QUE APUNTE AL QUE SE CREÓ ANTES DE EL EN EL ANTERIOR
                this->elemento->Siguiente = nuevo; ///AL ACTUAL ELEMENTO FINAL LE DECIMOS QUE EN EL SIGUIENTE APUNTE AL NUEVO
                this->elemento = nuevo; ///ACTUALIZAMOS EL ELEMENTO MAS RECIENTE, QUE ES "NUEVO"
            }
        }
        void InsertarAlFinal(int id, string n, string a, float sm){
            Trabajador *tb = new Trabajador(id, n, a, sm);
            this->InsertarAlFinal(tb);
        }
        void InsertarAlInicio(Trabajador *tb){
            Nodo *nuevo = new Nodo(tb);
            if (this->ListaVacia()){
                this->elemento = nuevo;
            }
            else{
                Nodo *tmp = this->Inicio();
                nuevo->Siguiente = tmp;
                tmp->Anterior = nuevo;
            }
        }
        void InsertarAlInicio(int id, string n, string a, float sm){
            Trabajador *tb = new Trabajador(id, n, a, sm);
            this->InsertarAlInicio(tb);
        }
        void InsertarEnMedioAntes(Trabajador *tb, int id){
            Nodo *nuevo = new Nodo(tb);
            Nodo *tmp = this->Buscar(id);
            if (this->ListaVacia()){
                this->elemento = nuevo;
            }else if(tmp -> Anterior){
                if (tmp){
                    nuevo->Anterior = tmp->Anterior;
                    tmp->Anterior->Siguiente = nuevo;
                    tmp->Anterior = nuevo;
                    nuevo->Siguiente = tmp;
                }
            }else{
                ///EN CASO DE QUE NO PUEDA ESTAR ENTRE DOS NODOS, IRÁ AL INICIO
                this -> InsertarAlInicio(tb);
            }
        }
        void InsertarEnMedioAntes(int id, string n, string a, float sm){
            Trabajador *tb = new Trabajador(id, n, a, sm);
            this->InsertarEnMedioAntes(tb, 0);
        }
        void InsertarEnMedioDespues(Trabajador *tb, int id){
            Nodo *nuevo = new Nodo(tb);
            Nodo *tmp = this->Buscar(id);
            if (this->ListaVacia()){
                this->elemento = nuevo;
            }else if(tmp -> Siguiente){
                if (tmp){
                    nuevo->Anterior = tmp;
                    nuevo->Siguiente = tmp->Siguiente;
                    tmp->Siguiente->Anterior = nuevo;
                    tmp->Siguiente = nuevo;
                }
            }else{
                ///EN CASO DE QUE NO PUEDA ESTAR ENTRE DOS NODOS, IRÁ AL FINAL
                this -> InsertarAlFinal(tb);
            }
        }
        void InsertarEnMedioDespues(int id, string n, string a, float sm){
            Trabajador *tb = new Trabajador(id, n, a, sm);
            this -> InsertarEnMedioDespues(tb, 0);
        }
        void Mostrar(){
            Nodo *tmp = this -> Inicio();
            if (tmp){
                cout << "Id\tNombre\tApellido\tSueldo\tTotal\n";
                while (tmp){
                    cout << tmp->Valor->getId() << "\t";
                    cout << tmp->Valor->getNombre() << "\t";
                    cout << tmp->Valor->getApellido() << "\t";
                    cout << "\t" << tmp->Valor->getSueldoMensual() << "\t";
                    cout << tmp->Valor->getTotalPagar() << "\n";
                    tmp = tmp->Siguiente;
                }
                cout << "NULL\n";
            }
            else{
                cout << "La lista esta vacia\n";
            }
        }
        bool eliminarTrabajador(int idTra){
            bool resultado = false;
            Nodo *tmp = this -> Buscar(idTra);

            if(idTra == tmp -> Valor -> getId()){
                if(!tmp -> Anterior){
                    elemento = tmp -> Siguiente;
                    if(tmp -> Siguiente){
                        tmp -> Siguiente -> Anterior = NULL;
                    }
                }else if(!tmp -> Siguiente){
                    elemento = tmp -> Anterior;
                    tmp -> Anterior -> Siguiente = NULL;
                }else{
                    tmp -> Anterior -> Siguiente = tmp -> Siguiente;
                    tmp -> Siguiente -> Anterior = tmp -> Anterior;
                }

                delete tmp;
                resultado = true;
            }

        return resultado;
        }
        bool modificarTrabajador(Trabajador *tb, int idTra){
            bool resultado = false;
            Nodo *aux = this -> Buscar(idTra);
            Nodo *modTrabajadorNodo = NULL;
            Trabajador *modTrabajador;

            if(aux){
                string nom, ape;
                float sMen;

                nom = tb -> getNombre();
                ape = tb -> getApellido();
                sMen = tb -> getSueldoMensual();

                ///EN NUEVOS OBJETOS ASIGANAMOS LOS CAMBIOS
                modTrabajador = new Trabajador(idTra, nom, ape, sMen);
                modTrabajadorNodo = new Nodo(modTrabajador);

                ///TRANFERIMOS LA INFORMACION AL NODO ORIGINAL
                aux -> Valor = modTrabajadorNodo -> Valor;

                resultado = true;
            }

            return resultado;
        }
};
#endif // LISTA_H_INCLUDED
