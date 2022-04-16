#include <cassert>
#include "pilavec.hpp"


template <typename tElemento> inline Pila<tElemento>::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    n_eltos(0)
{}

template <typename tElemento> Pila<tElemento>::Pila(const Pila<tElemento>& P):
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    n_eltos(P.n_eltos)
{
    for(unsigned i=0; i<n_eltos; ++i)
        elementos[i] = P.elementos[i];
}

template <typename tElemento> Pila<tElemento>& Pila<tElemento>::operator =(const Pila<tElemento>& P)
{
    if(this != &P){
        if(Lmax != P.Lmax){
            delete[] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        n_eltos = P.n_eltos;

        for(unsigned i=0; i<n_eltos; ++i)
            elementos[i] = P.elementos[i];
    }
    return *this;
}

template <typename tElemento>
inline bool Pila<tElemento>::vacia() const
{
    return (n_eltos == 0);
}

template <typename tElemento> inline bool Pila<tElemento>::llena() const
{
    return (n_eltos == Lmax);
}

template <typename tElemento> inline const tElemento& Pila<tElemento>::tope() const
{
    assert(!vacia());
    return elementos[n_eltos-1];
}

template <typename tElemento> inline void Pila<tElemento>::pop()
{
    assert(!vacia());
    --n_eltos;
}

template <typename tElemento> inline void Pila<tElemento>::push(const tElemento& x)
{
    assert(!llena());
    elementos[n_eltos] = x;
    ++n_eltos;
}

template <typename tElemento> inline Pila<tElemento>::~Pila()
{
     delete [] elementos;
}