#include "Array.h"

template <class T>
ostream & operator<<(ostream & os, Array<T> & data){

	if(data.isEmpty())
		return os << "NULL pointer";

	for(size_t i = 0; i < data.getSize(); i++)
		i != data.getSize() - 1 ? os << data[i] << ',' : os << data[i] ;

	os << endl;

	return os;

}

template <class T>
Array<T> & Array<T>::operator+= (Array<T> & data){

	size_t newSize = size + data.getSize();

	T *ref = new T[newSize];

	for(size_t i = 0; i < size; i++)
		ref[i] = ptr[i];

	for(size_t i = size; i < newSize; i++)
		ref[i] = data.ptr[i - size];

	if(ptr)
		delete []ptr;

	size = newSize;
	ptr = ref;

	return *this;

}

template <class T>
Array<T> & Array<T>::operator+= (T & element){

	size++;

	T *ref = new T[size];

	for(size_t i = 0; i < size - 1; i++)
		ref[i] = ptr[i];

	ref[size - 1] = element;

	if(ptr)
		delete []ptr;

	ptr = ref;

	return *this;


}

template <class T>
bool Array<T>::isEmpty(){

	if(!ptr)
		return true;

	return false;

}

template <class T>
Array<T>::Array(){

	ptr = NULL;
	size = 0;

}

template <class T>
Array<T>::Array(const size_t newSize){

	size = newSize;
	ptr = new T[size];

}

template <class T>
Array<T>::Array(const Array<T> & init){

	size = init.size;

	if(!size)
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

template <class T>
size_t Array<T>::getSize(){

	return size;

}

template <class T>
Array<T> & Array<T>::operator= (const Array<T> & right){

	if(&right != this){

		if(size != right.size){

			T *aux;

			aux = new T[right.size];

			delete []ptr;

			size = right.size;

			ptr = aux;

		}

		for(size_t i = 0; i < size; i++)
			ptr[i] = right.ptr[i];

		return *this;
		
	}

	return *this;

}

template <class T>
bool Array<T>::operator== (const Array<T> &right){

	if(size != right.size)
		return false;

	else
		for(size_t i = 0; i < size ; i++){

			if(ptr[i] != right.ptr[i])
				return false;

		}

	return true;

}

template <class T>
T & Array<T>::operator[](size_t index){

	return ptr[index];

}