#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>

using namespace std;

#define MEMSIZE 10

template <class T>
class Array{

    size_t size;
    size_t availableMem;
    T *ptr;

public:

    //Builder
    Array();
    Array(const size_t);
    Array(const Array<T> &);
    ~Array();

    //Status
    size_t getSize()const;
    bool isEmpty()const;
    Array<T> evenIndex();
    Array<T> oddIndex();

    //Modifiers
    void empty();
    void reSize(size_t);

    //Operators
    Array<T> & operator=(const Array<T> &);
    bool operator==(const Array<T> &);
    T & operator[](size_t);
    Array<T> & operator+=(Array<T> &);
    Array<T> & operator+=(T &);

    template<class U>
    friend Array<U> operator*(const Array<U> &, const double);

    //IO
    template <class U>
    friend ostream & operator<< (ostream &, Array<U> &);

    template <class U>
    friend istream & operator>> (istream &, Array<U> &);

};

template <class T>
Array<T> operator*(const Array<T> &data, const double k){

	Array<T> aux = data;

	for(size_t i = 0; i < aux.getSize(); i++){

		aux[i] *= k;

	}

	return aux;

}

//Builders
template <class T>
Array<T>::Array(){
	ptr = NULL;
	size = 0;
	availableMem = 0;
}

template <class T>
Array<T>::Array(const size_t newSize){
	size = newSize;
	availableMem = size;
	ptr = new T[size];
}

template <class T>
Array<T>::Array(const Array<T> & init){

	size = init.size;
	availableMem = size;

	if (!size)
		ptr = NULL;

	else{

		ptr = new T[size];

		for(size_t i = 0; i < size; i++)
			ptr[i] = init.ptr[i];

	}

}

template <class T>
Array<T>::~Array(){
	if(ptr)
		delete []ptr;
}

//Status
template <class T>
Array<T> Array<T>::evenIndex(){

	Array<T> aux;

	for(size_t i = 0; i < size; i += 2)
		aux += ptr[i];

	return aux;

}

template <class T>
Array<T> Array<T>::oddIndex(){

	Array<T> aux;

	for(size_t i = 1; i < size; i += 2)
		aux += ptr[i];

	return aux;

}

template <class T>
size_t Array<T>::getSize()const{
	return size;
}

template <class T>
bool Array<T>::isEmpty()const{

	if (!ptr)
		return true;

	return false;

}

//Modifiers
template <class T>
void Array<T>::reSize(size_t newSize){

	T *aux = new T[newSize];

	for(size_t i = 0; i < newSize; i++)
		if(i < size)
			aux[i] = ptr[i];

	delete []ptr;
	ptr = aux;
	size = newSize;
	availableMem = newSize;

}

template <class T>
void Array<T>::empty(){

	if(ptr){
		delete []ptr;
		ptr = NULL;
		size = 0;
		availableMem = size;
	}

}

//Operators
template <class T>
Array<T> & Array<T>::operator=(const Array<T> & right){

	if(&right != this){

		if(size != right.size){

			T *aux = new T[right.size];

			delete []ptr;

			size = right.size;
			availableMem = size;

			ptr = aux;

		}

		for (size_t i = 0; i < size; i++)
			ptr[i] = right.ptr[i];

		return *this;

	}

	return *this;

}

template <class T>
bool Array<T>::operator==(const Array<T> &right){

	if(size != right.size)
		return false;

	else
		for(size_t i = 0; i < size ; i++)
			if (ptr[i] != right.ptr[i])
				return false;

	return true;

}

template <class T>
Array<T> & Array<T>::operator+=(Array<T> & data){

	size_t newSize = size + data.getSize();

	T *ref = new T[newSize];

	for(size_t i = 0; i < size; i++)
		ref[i] = ptr[i];

	for(size_t i = size; i < newSize; i++)
		ref[i] = data.ptr[i - size];

	if(ptr)
		delete []ptr;

	size = newSize;
	availableMem = size;
	ptr = ref;

	return *this;

}

template <class T>
Array<T> & Array<T>::operator+=(T & element){

	if(availableMem == size){

		availableMem += MEMSIZE;
		T *ref = new T[availableMem];

		for(size_t i = 0; i < size; i++)
			ref[i] = ptr[i];

		if(ptr)
			delete []ptr;

		ptr = ref;

	}

	size++;

	ptr[size - 1] = element;

	return *this;

}


template <class T>
T & Array<T>::operator[](size_t index){
	return ptr[index];
}

//IO
template <class T>
istream & operator>>(istream & is, Array<T> & data){

	T element;

	while(is >> element){

		if (!is.fail())
			data += element;

		else{
			is.clear(ios::badbit);
			return is;
		}

	}

	return is;
}

template <class T>
ostream & operator<<(ostream & os, Array<T> & data){

	if (data.isEmpty())
		return os << "Empty Array";

	for (size_t i = 0; i < data.getSize(); i++)
		i != data.getSize() - 1 ? os << data[i] << ' ' : os << data[i];

	return os;

}

#endif
