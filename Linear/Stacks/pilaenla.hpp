#ifndef PILA_ENLA_HPP
#define PILA_ENLA_HPP

#include <cassert>

template <typename T> class Pila{
    public:
        Pila(); 
        Pila(const Pila<T>& P); //copy constructor
        Pila<T>& operator =(const Pila<T>& P);
        bool vacia() const;
        const T& tope() const;
        void pop();
        void push(const T& x);
        ~Pila(); 
    private:
        	struct nodo{
                T elto;
                nodo* sig;
                nodoU(const T& e, nodo* p=nullptr): elto(e), sig(p) {}
            };
        nodo* tope_;

        void copiar(const Pila<T>& P);
};

#endif //PILA_ENLA_HPP