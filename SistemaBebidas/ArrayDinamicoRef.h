#pragma once
#include "Nodo.h"
/*Clase ArrayDinamicoRef nos permite utilizar un array generico de referencias que almacena
las direcciones de memoria de sus Nodos
Es utilizado para almacenar los resultados de las consultas sql de los functores
*/
template<typename type>
class ArrayDinamicoRef {
private:
    Nodo<type>** Array;
    int longitud;
public:
    ArrayDinamicoRef() {
        Array = nullptr;
        longitud = 0;
    }
    ~ArrayDinamicoRef() {
        for (int i = 0; i < this->longitud; i++)
            delete Array[i];
        if (Array != nullptr)
            delete[] Array;
    }

    int getSize() {
        return this->longitud;
    }

    void insertarElemento(Nodo<type>* elemento) {
        Nodo<type>** aux = new Nodo<type>*[longitud + 1];
        for (int i = 0; i < this->longitud; i++) {
            aux[i] = Array[i];
        }
        aux[longitud] = elemento;
        if (Array != nullptr)
            delete[] Array;

        Array = aux;
        (this->longitud)++;
    }

    void eliminarElemento(int pos) {
        Nodo<type>** aux = new Nodo<type>*[longitud - 1];
        for (int i = 0; i < pos; i++) {
            aux[i] = Array[i];
        }
        for (int i = pos; i < this->longitud; i++) {
            aux[i] = Array[i + 1];
        }
        if (Array != nullptr)
            delete[] Array;

        Array = aux;
        (this->longitud)--;
    }

    Nodo<type>* getInPosicion(int pos) {
        return Array[pos];
    }

};
