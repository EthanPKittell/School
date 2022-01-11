#include "HW6.h"

double MyComplex::returnReal()
{
	return MyComplex::real;
}
double MyComplex::returnImaginary()
{
	return MyComplex::imaginary;
}
void MyComplex::setReal(double input) {
	real = input;
}
void MyComplex::setImaginary(double input) {

	imaginary = input;
}
MyComplex::MyComplex(double inputReal) {

	real = inputReal;
}
MyComplex::MyComplex(double inputReal, double inputImaginary) {

	real = inputReal;
	imaginary = inputImaginary;
}

void MyComplex::conjugate() {
	imaginary = imaginary * (-1);
}