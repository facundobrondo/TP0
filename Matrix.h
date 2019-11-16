#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

#include <iostream>
#include "Array.h"  

using namespace std;

template <class T>
class Matrix{

	Array<Array<T>> M;

	size_t rows;
	size_t cols;

public:

	//Builder
	Matrix();
	Matrix(const size_t, const size_t);
	Matrix(const Matrix<T> &);
	~Matrix();

	//Status
	size_t getRows() const;
	size_t getCols() const;
	bool isEmpty() const;

	//Modifiers
	void empty();
	void reSize(size_t, size_t);

	//Operators
	bool operator==(const Matrix<T> &);
	Array<T> & operator[](size_t);

	//IO
	template <class U>
	friend ostream & operator<< (ostream &, Matrix<U> &);

	template <class U>
	friend istream & operator>> (istream &, Matrix<U> &);

};

//Builder

template <class T>
Matrix<T>::Matrix(){

	rows = 0;
	cols = 0;

}

template <class T>
Matrix<T>::Matrix(const size_t nRows, const size_t nCols){

	(*this).reSize(nRows, nCols);

}

template <class T>
Matrix<T>::Matrix(const Matrix<T> & right){

	rows = right.rows;
	cols = right.cols;

	for(size_t i = 0; i < rows; i++)
		M[i] = right.M[i];

}

template<class T>
Matrix<T>::~Matrix(){
}

//Status

template<class T>
size_t Matrix<T>::getRows()const{
	return rows;
}

template<class T>
size_t Matrix<T>::getCols()const{
	return cols;
}

template<class T>
bool Matrix<T>::isEmpty()const{	

	if(!rows && !cols)
		return true;

	return false;

}

template<class T>
void Matrix<T>::empty(){

	for(size_t i = 0; i < rows; i++)
		M[i].empty();

	rows = 0;
	cols = 0;

}

//Operators

template<class T>
bool Matrix<T>::operator==(const Matrix<T> & right){

	if(this == &right)
		return true;

	if(rows == right.rows && cols == right.cols)

		for(size_t i = 0; i < rows; i++)
			if(M[i] != right.M[i])
				return false;

	return true;

}

template<class T>
Array<T> & Matrix<T>::operator[](size_t index){

	return M[index];

}

template <class T>
ostream & operator<< (ostream & os, Matrix<T> & data){

	if(data.isEmpty())
		os << "Empty Matrix";

	for(size_t i = 0; i < data.rows; i++)
		i == data.rows - 1 ? os << '|' << (data.M)[i] << '|' : os << '|' << (data.M)[i] << '|' << endl;	

	return os;

}

template <class T>
istream & operator>> (istream & is, Matrix<T> & data){

	for(size_t i = 0; i < data.rows; i++)
		is >> data[i];

	return is;

	//REVISAR LA CANTIDAD DE COLUMNAS, MODIFICAR OPERATOR>> DE ARRAY

}

template<class T>
void Matrix<T>::reSize(size_t nRows, size_t nCols){

	M.reSize(nRows);

	for(size_t i = 0; i < nRows; i++){
		M[i].reSize(nCols);
	}

	rows = nRows;
	cols = nCols;

}



#endif