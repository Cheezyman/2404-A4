#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cstdlib>
#include "defs.h"

template <typename T>
class Array
{
private:
    T *elements;
    int numElements;

public:
    // Constructor
    Array()
    {
        elements = new T[MAX_ARR];
        numElements = 0;
    }

    // Destructor
    ~Array()
    {
        delete[] elements;
    }

    // Overload += for adding elements
    Array &operator+=(const T &item)
    {
        if (numElements >= MAX_ARR)
            return *this;
        elements[numElements++] = item;
        return *this;
    }

    // Overload -= for removing elements
    Array &operator-=(const T &item)
    {
        int index = 0;
        while (index < numElements)
        {
            if (item == elements[index])
            {
                --numElements;
                break;
            }
            ++index;
        }

        while (index < numElements)
        {
            elements[index] = elements[index + 1];
            ++index;
        }
        return *this;
    }

    // Overload [] operator (non-const version)
    T &operator[](int index)
    {
        if (index < 0 || index >= numElements)
        {
            std::cerr << "Array index out of bounds" << std::endl;
            exit(1);
        }
        return elements[index];
    }

    // Overload [] operator (const version)
    const T &operator[](int index) const
    {
        if (index < 0 || index >= numElements)
        {
            std::cerr << "Array index out of bounds" << std::endl;
            exit(1);
        }
        return elements[index];
    }

    // Get the current size of the array
    int getSize() const
    {
        return numElements;
    }

    // Check if the array is full
    bool isFull() const
    {
        return numElements >= MAX_ARR;
    }
};

#endif // ARRAY_H
