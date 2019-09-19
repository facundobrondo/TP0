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

	Complex & operator= (const Complex &);
	Complex & operator= (const double);

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

	friend ostream & operator<< (ostream &, const Complex &);
	friend istream & operator>> (istream &,  Complex &);

};

#endif
