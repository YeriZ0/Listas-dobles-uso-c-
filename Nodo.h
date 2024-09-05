#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include "Trabajador.h"

class Nodo{
    private:
        Trabajador *Valor;
        Nodo *Siguiente;
        Nodo *Anterior;
    public:
        Nodo(Trabajador *v, Nodo *sig=NULL, Nodo *ant=NULL){
            this->Valor = v;
            this->Siguiente = sig;
            this->Anterior = ant;
        }
        friend class Lista;
};
#endif // NODO_H_INCLUDED
