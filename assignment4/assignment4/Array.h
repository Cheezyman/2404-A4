#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept> // For std::out_of_range

template <typename T>
class Array {
private:
    T *elements;
    int numElements;
    static const int MAX_ARR = 256;  // Define a constant for maximum array size

public:
    // Constructor
    Array() : elements(new T[MAX_ARR]), numElements(0) {}

    // Destructor
    ~Array() {
        delete[] elements;
    }

    // Add an element to the array
    void add(const T& item) {
        if (numElements >= MAX_ARR) {
            throw std::runtime_error("Array is full");
        }
        elements[numElements++] = item;
    }

    // Clear the array
    void clear() {
        delete[] elements;
        elements = new T[MAX_ARR];
        numElements = 0;
    }

    // Get element at a specific index
    T& operator[](int index) {
        if (index < 0 || index >= numElements) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Get element at a specific index (const version)
    const T& operator[](int index) const {
        if (index < 0 || index >= numElements) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Get the current number of elements
    int getSize() const {
        return numElements;
    }
};

#endif // ARRAY_H
