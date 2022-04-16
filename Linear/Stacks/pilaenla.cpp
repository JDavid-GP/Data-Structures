#include <cassert>

#include "pilaenla.hpp"

template <typename T> void Pila<T>::copiar(const Pila<T>& P)
{
    if(!P.vacia()){
        tope_ = new nodo(P.tope());
        nodo* p = tope_;
        nodo* q = P.tope_->sig;
        while(q){
            p->sig= new nodo(q->elto);
            p = p->sig;
            q = q->sig;
        }
    }
}

template <typename T> inline Pila<T>::Pila() : tope_(nullptr) {}

template <typename T> Pila<T>::Pila(const Pila<T>& P): tope_(nullptr)
{
    copiar(P);
}

template <typename T> Pila<T>& Pila<T>::operator =(const Pila<T>& P)
{
    if(this != &P){
        this->~Pila();
        copiar(P);
    }
    return *this;
}

template <typename T> inline bool Pila<T>::vacia() const
{ return (tope_ == nullptr);}

template <typename T> inline const T& Pila<T>::tope() const
{
    assert(!vacia());
    return tope_->elto;
}

template <typename T> inline void Pila<T>::pop()
{
    assert(!vacia());
    nodo* p = tope_;
    tope_ = p->sig;
    delete p;
}

template <typename T> inline void Pila<T>::push(const T& x)
{
    tope_ = new nodo(x, tope_);
}

template <typename T> Pila<T>::~Pila()
{
    nodo* p;
    while(tope_){
        p = tope_->sig;
        delete tope_;
        tope_ = p;
    }
}