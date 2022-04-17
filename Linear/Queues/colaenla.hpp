#ifndef COLA_ENLA_HPP
#define COLA_ENLA_HPP

template <typename T> class Cola{
    public:
        Cola();     //Constructor
        Cola(const Cola<T>& C);     // Copy constructor
        Cola<T>& operator =(const Cola<T>& C); // = operator overload
        bool vacia() const;
        const T& frente() const;
        void pop();
        void push(const T& x);
        ~Cola(); //Deconstructor
    private:
        struct nodo{
            T elto;
            nodo* sig;
            nodo(const T& e, nodo* p = nullptr): elto(e), sig(p) {}
        };
        
        nodo *inicio, *fin; // front and rear of the queue

        void copiar(const Cola<T>& C);
};

#endif // COLA_ENLA_HPP