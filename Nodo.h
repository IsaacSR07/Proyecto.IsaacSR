#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class Nodo {
public:
	T dato;
	Nodo<T>* sig;
	Nodo(const T&);
};

template <class T>
Nodo<T>::Nodo(const T& d) {
	dato = d;
	sig = NULL;
}

#endif
