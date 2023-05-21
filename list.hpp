//
// Created by Dukát Nándor on 2023. 05. 07..
//

#ifndef PROJECT_LIST_HPP
#define PROJECT_LIST_HPP

#include <iostream>
#include "memtrace.h"

template<class T, typename E = std::out_of_range>
class List
{
private:
    int size; // A lista mérete
    T* data; // T osztályok pointerei
public:
    // Iterátor típusdefiníció
    using iterator = T*;

    // Kezdő iterátor
    iterator begin() const {
        return data;
    }

    // Végző iterátor
    iterator end() const {
        return data + size;
    }
    /*
     * Default konstruktor
     * size: alapértelmezett 0 érték
     * lefoglalja a tömbböt
     */
    List() : size(0) {
        data = new T[size];
    }

    /*
     * @return tömbnek a mérete
     */
    int getSize() const {
        return this->size;
    }

    /*
     * Függvény hozzáad egy objektumot a tömb végéhez.
     * @param t - T objektum pointere
     */
    void add(T t)
    {
        try {
            T *temp = new T[size + 1];
            for (int i = 0; i < size; i++)
                temp[i] = data[i];

            delete[] data;
            data = temp;

            data[size++] = t;
        }
        catch(std::bad_alloc&) {
            throw "Nem sikerült a memória foglalás.";
        }
    }

    /*
     * Függvény töröl egy megadott objektumot a tömbből.
     * @param t - T objektum pointere
     */
    void remove(T t)
    {
        if (t == nullptr) return;

        for (int i = 0; i < size; i++)
        {
            if (data[i] == t)
            {
                try {
                    T *temp = new T[size - 1];

                    int count = 0;
                    for (int j = 0; j < size; j++)
                    {
                        if (j == i) continue;
                        temp[count++] = data[j];
                    }

                    delete[] data;
                    delete t;

                    data = temp;
                    size--;
                }
                catch(std::bad_alloc&) {
                    throw "Nem sikerült a memória foglalás.";
                }
            }
        }
    }

    /*
     * Indexelő operátor
     * @param i - Tömb indexe
     * @return T& - Tömb i-edik eleme.
     */
    T& operator[](int i)
    {
        if (i < 0 || i >= size)
            throw E("Indexelési hiba!");

        return data[i];
    }

    /*
     * Indexelő operátor
     * @param i - Tömb indexe
     * @return T& - Tömb i-edik eleme.
     */
    T& operator[](int i) const
    {
        if (i < 0 || i >= size)
            throw E("Indexelési hiba!");

        return data[i];
    }

    /*
     * Destruktor
     * Törli a lista minden objektumát és a pointer tömböt.
     */
    virtual ~List()
    {
        for (int i = 0; i < size; i++)
            delete data[i];
        delete[] data;
    }
};

#endif //PROJECT_LIST_HPP