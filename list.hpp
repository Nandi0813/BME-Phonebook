//
// Created by Dukát Nándor on 2023. 05. 07..
//

#ifndef PROJECT_LIST_HPP
#define PROJECT_LIST_HPP

#include <iostream>
#include "memtrace.h"

template<class T>
class List
{
private:
    int size;
    T* data;
public:
    List() : size(0)
    {
        data = new T[size];
    }

    int getSize() const
    {
        return this->size;
    }

    bool add(T t)
    {
        try
        {
            T *temp = new T[size + 1];
            for (int i = 0; i < size; i++)
                temp[i] = data[i];

            delete[] data;
            data = temp;

            data[size++] = t;

            return true;
        }
        catch(std::bad_alloc&) {
            return false;
        }
    }

    bool remove(T t)
    {
        if (t == nullptr)
            return false;

        for (int i = 0; i < size; i++)
        {
            if (data[i] == t)
            {
                try
                {
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

                    return true;
                }
                catch(std::bad_alloc&) {
                    return false;
                }
            }
        }

        return false;
    }

    T& operator[](int i)
    {
        return data[i];
    }
    T& operator[](int i) const
    {
        return data[i];
    }

    virtual ~List()
    {
        for (int i = 0; i < size; i++)
            delete data[i];
        delete[] data;
    }
};


#endif //PROJECT_LIST_HPP