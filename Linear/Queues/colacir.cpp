#include <cassert>
#include "colacir.hpp"


template <typename T> Cola<T>::Cola(size_t TamaMax) :
    elementos(new T[TamaMax]) :
        elementos(new T[TamaMax+1]),    // +1 to detect if the queue is full
        Lmax(TamaMax +1),
        inicio(0),
        fin(TamaMax)
{}

template <typename T> Cola<T>::Cola(const Cola<T>& C)  :
    elementos(new T[C.Lmax]),
    Lmax(C.Lmax),
    inicio(C.inicio),
    fin(C.fin)
{
    for(size_t i = inicio; i != (fin+1) % Lmax; i=(i+1) % Lmax)
        elementos[i] = C.elementos[i];
}

template <typename T> Cola<T>& Cola<T>::operator =(const Cola<T>& C)
{
    if(this !=  &C){    // Check self-assignment
        // Delete the vector and create a new one if needed
        if(Lmax != C.Lmax){
            delete[] elementos;
            Lmax = C.Lmax;
            elementos = new T[Lmax];
        }
        inicio = C.inicio;
        fin = C.fin;
        // Copy elements
        for(size_t i = inicio; i!= (fin+1)%Lmax; i=(i+1)%Lmax)
            elementos[i] = C.elementos[i];
    }
    return *this;
}

template <typename T> inline bool Cola<T>::vacia() const
{
    return (inicio == (fin+1) % Lmax);
}

template <typename T> inline bool Cola<T>::llena() const
{
    return (inicio == (fin+2) % Lmax);
}

template <typename T> inline const T& Cola<T>::frente() const
{
    assert(!vacia());
    return elementos[inicio];
}

template <typename T> inline void Cola<T>::pop()
{
    assert(!vacia());
    inicio = (inicio+1) % Lmax;
}

template <typename T> inline void Cola<T>::push(const T& x)
{
    assert(!llena());
    fin = (fin+1) % Lmax;
    elementos[fin] = x;
}

template <typename T> inline Cola<T>::~Cola()
{
    delete[] elementos;
}