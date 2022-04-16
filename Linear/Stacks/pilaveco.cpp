#include <cassert>

#include "pilaveco.hpp"

Pila::Pila() : n_eltos(0)
{}

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
