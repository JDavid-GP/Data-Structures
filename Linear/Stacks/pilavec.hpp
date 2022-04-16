#ifndef PILA_VEC_HPP 
#define PILA_VEC_HPP
#include <cassert>

template <typename tElemento> class Pila{
    public:
        explicit Pila(unsigned TamaMax);
        Pila(const Pila& P);
        Pila& operator =(const Pila& P);
        bool vacia() const;
        bool llena() const;
        const tElemento& tope() const;
        void pop();
        void push(const tElemento& x);
        ~Pila();
    private:
        tElemento *elementos;
        unsigned Lmax;
        unsigned n_eltos;
};

#endif PILA_VEC_HPP