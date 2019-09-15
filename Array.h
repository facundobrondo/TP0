#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>

using namespace std;

template <class T>
class Array{

	size_t size;
	T *ptr;

public:

	//Builder

	Array();
	Array(const size_t);
	Array(const Array<T> &); 
	~Array();

	//Status

	size_t getSize();
	bool isEmpty(); 

	//Operators

	Array<T> & operator= (const Array<T> &);
	bool operator== (const Array<T> &);
	T & operator[](size_t);
	Array<T> & operator+= (Array<T> &);
	Array<T> & operator+= (T &);

	//IO

	template <class U>
	friend ostream & operator<< (ostream &, const Array<U> &);

};

#endif