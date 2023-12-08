#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <typename T>
class Array {

	template <typename Y>
	friend ostream& operator<<(ostream& ost, const Array<Y>& arr);

	private:
		int numElements;
		T* elements;

	public:
		Array();
		~Array();
		T& operator[](int index);
		const T& operator[](int index) const;
		const T& get(int index) const;
		T& get(int index);
		Array<T>& operator+=(T t);
		Array<T>& operator-=(T t);
		int getSize() const;
		bool isFull() const;
		void add(T);
		void remove(T);
		void clear();
};

template <typename T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	numElements = 0;
}

template <typename T>
Array<T>::~Array(){
	delete [] elements;
	elements = nullptr;
}

template <typename T>
T& Array<T>::operator[](int index) {
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


template <typename T>
void Array<T>::add(T t){
	if (numElements >= MAX_ARR) return;
	elements[numElements++] = t;
}

template <typename T>
Array<T>& Array<T>::operator+=(T t){
	add(t);
	return *this;
}

template <typename T>
void Array<T>::remove(T t){
	int index = 0;
	while (index < numElements){
		if (t == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
}

template <typename T>
Array<T>& Array<T>::operator-=(T t){
	remove(t);
	return *this;
}

template <typename T>
int Array<T>::getSize() const{
	return numElements;
}

template <typename T>
bool Array<T>::isFull() const {
	return numElements >= MAX_ARR;
}

// Const version of get
template <typename T>
const T& Array<T>::get(int index) const {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

// Non-const version of get
template <typename T>
T& Array<T>::get(int index) {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
void Array<T>::clear(){
	for(int i = 0; i < numElements; ++i){
		elements[i] = nullptr;
	}
	numElements = 0;
}

#endif