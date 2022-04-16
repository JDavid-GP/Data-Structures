#ifndef PILA_VEC1_HPP
#define PILA_VEC1_HPP

class Pila{
    public:
        typedef int tElemento;
        explicit Pila(unsigned TamaMax);
        Pila(const Pila& P);                // Copy constructor
        Pila& operator =(const Pila& P);
        bool vacia() const;
        bool llena() const;
        const tElemento& tope() const;
        void pop();
        void push(const tElemento& x);
        ~Pila();
    private:
        tElemento *elementos;
        unsigned Lmax;              // Vector size
        unsigned n_eltos;           // Stack size
};

#endif //PILA_VEC1_HPP

