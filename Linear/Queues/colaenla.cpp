#include <cassert>
#include "colaenla.hpp"


template <typename T> void Cola<T>::copiar(const <T>& C)
{
    if(C.inicio){   // C is not empty
        // Copy the first elto
        inicio = fin = new nodo(C.inicio->elto);
        //Copy the rest of elements until the end of the queue
        for(nodo *p = C.inicio->sig; p; p = p->sig){
            fin->sig = new nodo(p->elto);
            fin = fin->sig;
        }

    }
}

template <typename T> inline Cola<T>::Cola() : inicio(nullptr), fin(nullptr) {}

template <typename T> inline Cola<T>::Cola(const Cola<T>& C) :
    inicio(nullptr), fin(nullptr)
{
    copiar(C);
}

template <typename T> inline Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
    if(this != &C){
        this->~Cola();
        copiar(C);
    }
    return *this;
}

template <typename T> inline bool Cola<T>::vacia() const
{
    return (inicio == nullptr);
}

template <typename T> inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return inicio->elto;
}

template <typename T> inline void Cola<T>::pop()
{
    assert(!vacia());
    nodo* p = inicio;
    inicio = p->sig;
    if(!inicio) fin = nullptr;
    delete p;
}

template <typename T> inline void Cola<T>::push(const T& x)
{
    nodo* p = new nodo(x);
    if(inicio == nullptr)
        inicio = fin = p;
    else 
        fin = fin->sig = p;
}

template <typename T> Cola<T>::~Cola()
{
    nodo* p;
    while(inicio){
        p = inicio->sig;
        delete inicio;
        inicio = p;
    }
    fin = nullptr;
}
