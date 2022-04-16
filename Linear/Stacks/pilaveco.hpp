#ifndef PILA_VECO_HPP
#define PILA_VECO_HPP

class Pila{
    public:
        typedef int tElemento;
        Pila();
        bool vacia() const;
        bool llena() const;
        const tElemento& tope() const;
        void pop();
        void push(const tElemento& x);
    private:
        static const unsigned Lmax = 100; 
        tElemento elementos[Lmax];
        unsigned n_eltos;
};



#endif // Pila VECO_HPP