#ifndef COLA_VEC_HPP
#define COLA_VEC_HPP

template <typename T> class Cola{
    public:
        explicit Cola(size_t TamaMax);
        Cola(const Cola<T>& C);      // Copy constructor
        Cola<T>& operator =(const Cola<T>& C);
        bool vacia() const;
        bool llena() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~Cola();
    private:
        T *elementos;   
        size_t Lmax;    
        size_t n_eltos; // Size of queue
};