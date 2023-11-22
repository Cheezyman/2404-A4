#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

class Array {

	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		Array& add(const string&);
		Array& remove(const string&);
		const string& get(int index) const;
		int getSize() const;
		bool isFull() const;
	
	
	private:
		int numElements;
		string* elements;
	
};

Array::Array(){
	elements = new string[MAX_ARR];
	numElements = 0;
}

Array::~Array(){
	delete [] elements;
}

Array& Array::add(const string& s){
	if (numElements >= MAX_ARR)   return *this;
  	elements[numElements++] = s;
	return *this;
}


Array& Array::remove(const string& s){
	int index = 0;
	while (index < numElements){
		if (s == elements[index]){
			--numElements;
			break;
		}
		++index;
	}

	while (index < numElements){
		elements[index] = elements[index + 1];
		++index;
	}
	return *this;
}

int Array::getSize() const{
	return numElements;
}

bool Array::isFull() const {
	return numElements >= MAX_ARR;
}

const string& Array::get(int index) const{
	if (index < 0 || index >= numElements) {
		cerr<<"Array index out of bounds"<<endl;
		exit(1);
	}
	return elements[index];
}


#endif