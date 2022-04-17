#ifndef COLA_CIR_HPP
#define COLA_CIR_HPP

template <typename T> class Cola{
    public:
        explicit Cola(size_t TamaMax);
        Cola(const Cola<T>& C);
        Cola<T>& operator =(const Cola<T>& C);
        bool vacia() const;
        bool llena() const;
        void pop();
        void push(const T& x);
        ~Cola();
    private:
        T *elementos;
        size_t Lmax;
        size_t inicio, fin; //front and rear of the queue
};

#endif //COLA_CIR_HPP