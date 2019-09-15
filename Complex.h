//Desarrollo del tipo de dato Complejo

#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED


#include <iostream>
#include <cmath>

using namespace std;

class Complex{

	double x, y;

public:

	//Builder

	Complex();
	Complex(const double);
	Complex(const double, const double);
	Complex(const Complex &);
	~Complex();

	//Status

	bool isZero() const;
	bool isReal() const;
	double Re() const;
	double Im() const;
	double absoluteValue() const;
	double absoluteValue2() const;
	Complex conjugate() const;
	Complex & conjugateThis();

	//Operators

	friend Complex operator+ (const Complex &, const Complex &);
	Complex & operator+= (Complex &);
	friend Complex operator- (const Complex &, const Complex &);
	Complex & operator-= (Complex &);
	friend Complex operator* (const Complex &, const Complex &);
	Complex & operator*= (Complex &);
	friend Complex operator/ (const Complex &, const Complex &);
	Complex & operator/= (Complex &);

	//With real numbers

	Complex & operator+= (const double);
	friend Complex operator+ (const Complex &, const double);
	Complex & operator-= (const double);
	friend Complex operator- (const Complex &, const double);
	Complex & operator*= (const double);
	friend Complex operator* (const Complex &, const double);
	Complex & operator/= (const double);
	friend Complex operator/ (const Complex &, const double);

	//IO

	friend ostream & operator<< (ostream &, const Complex);

};

ostream & operator<< (ostream & os, const Complex c){
	return os << '(' << c.x << ',' << c.y << ')';
}

Complex::Complex(){

	x = 0;
	y = 0;

}

Complex::Complex(const double Re){

	x = Re;
	y = 0;

}

Complex::Complex(const double Re, const double Im){

	x = Re;
	y = Im;

}

Complex::Complex(const Complex & c){

	x = c.x;
	y = c.y;

}

Complex::~Complex(){}

bool Complex::isZero() const{
	return !x && !y;
}

bool Complex::isReal() const{
	return !y;
} 

double Complex::Re() const{
	return x;
} 

double Complex::Im() const{
	return y;
} 

double Complex::absoluteValue() const{
	return sqrt(pow(x, 2) + pow(y, 2));
} 

double Complex::absoluteValue2() const{
	return pow(x, 2) + pow(y, 2);
} 

Complex Complex::conjugate() const{
	return Complex(x, y * -1);
}

Complex & Complex::conjugateThis(){

	y *= -1;
	return *this;

}

Complex operator+(const Complex & a, const double Re){
	return Complex(a.x + Re, a.y);
}

Complex operator+(const Complex & a, const Complex & b){
	return Complex(a.x + b.x, a.y + b.y);
}

Complex operator-(const Complex & a, const double Re){
	return Complex(a.x - Re, a.y);
}

Complex operator-(const Complex & a, const Complex & b){
	return Complex(a.x - b.x, a.y - b.y);
}

Complex operator* (const Complex & a, const double mul){
	return Complex(a.x * mul, a.y * mul);
}

Complex operator* (const Complex & a, const Complex & b){

	double Re, Im;

	Re = a.x * b.x - a.y * b.y;
	Im = b.y * a.x + a.y * b.x;

	return Complex(Re, Im);

}

Complex operator/ (const Complex & a, const double div){
	return Complex(a.x / div, a.y / div);
}

Complex operator/ (const Complex & a, const Complex & b){

	Complex c = a * b.conjugate();
	c /= b.absoluteValue2();

	return c;

}

Complex & Complex::operator+= (const double right){

	x += right;
	return *this;

}

Complex & Complex::operator+= (Complex & right){

	x += right.x;
	y += right.y;

	return *this;

}

Complex & Complex::operator-= (const double right){

	x -= right;
	return *this;

}

Complex & Complex::operator-= (Complex & right){

	x -= right.x;
	y -= right.y;

	return *this;

}

Complex & Complex::operator*= (const double mul){

	x *= mul;
	y *= mul;

	return *this;

}

Complex & Complex::operator*= (Complex & right){

	double oldX = x;

	x = x * right.x - y * right.y;
	y = right.y * oldX + y * right.x;

	return *this;

}


Complex & Complex::operator/= (const double div){

	x /= div;
	y /= div;

	return *this;

}

Complex & Complex::operator/= (Complex & right){

	*this *= right.conjugateThis();
	*this /= right.absoluteValue2();

	return *this;

}

#endif

