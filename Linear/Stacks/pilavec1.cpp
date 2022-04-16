#include <cassert>

#include "pilavec1.hpp"

// Constructor

Pila::Pila(unsigned TamaMax) :
    elementos(new tElemento[TamaMax]),
    Lmax(TamaMax),
    n_eltos(0)
{}

// Copy Constructor

Pila::Pila(const Pila& P) :
    elementos(new tElemento[P.Lmax]),
    Lmax(P.Lmax),
    n_eltos(P.n_eltos)
{
    for (unsigned i = 0; i < n_eltos; ++i)
        elementos[i] = P.elementos[i];
}

Pila& Pila::operator =(const Pila& P)
{
    if(this != &P){
        if(Lmax != P.Lmax){
            delete [] elementos;
            Lmax = P.Lmax;
            elementos = new tElemento[Lmax];
        }
        n_eltos = P.n_eltos;

        for(unsigned i = 0; i < n_eltos; ++i)
            elementos[i] = P.elementos[i];
    }
    return *this;
}

bool Pila::vacia() const
{
    return (n_eltos == 0);
}

bool Pila::llena() const
{
    return (n_eltos == Lmax);
}

const Pila::tElemento& Pila::tope() const
{
    assert(!vacia());
    return elementos[n_eltos-1];
}

void Pila::pop()
{
    assert(!vacia());
    --n_eltos;
}

void Pila::push(const tElemento& x)
{
    assert(!llena());
    elementos[n_eltos] = x;
    ++n_eltos;
}

Pila::~Pila()
{
    delete[] elementos;
}