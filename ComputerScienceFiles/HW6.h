#include <iostream>
using namespace std;
class MyComplex
{
public:
	//accesor functions
	double returnReal();
	double returnImaginary();
	//mutator functions (not used)
	void setReal(double input);
	void setImaginary(double input);
	//default constructor and value constructors
	MyComplex() {
		real = 0;
		imaginary = 0;
	}
	MyComplex(double inputReal);
	MyComplex(double inputReal, double inputImaginary);


	void conjugate();

	void printComplex(MyComplex& comp) {
		if (imaginary >= 0)
		{
			if ((comp.real != 0) && (comp.imaginary != 0))
			{
				cout << comp.real << "+" << comp.imaginary << "i" << endl;
			}
			else if (comp.real == 0)
			{
				cout << "+" << comp.imaginary << "i" << endl;
			}
			else if (comp.imaginary == 0)
			{
				cout << comp.real << endl;
			}
		}
		else {
			if ((comp.real != 0) && (comp.imaginary != 0))
			{
				cout << comp.real << comp.imaginary << "i" << endl;
			}
			else if (comp.real == 0)
			{
				cout << comp.imaginary << "i" << endl;
			}
			else if (comp.imaginary == 0)
			{
				cout << comp.real << endl;
			}

		}
	}

	friend void operator>>(istream& input, MyComplex& comp) {

		cout << "Please enter complex number in the form a+bi / a-bi: " << endl;

		input >> comp.real;
		input >> comp.imaginary;
		input.ignore(35, 'i');

	}

	friend void operator+(const MyComplex& comp1, const MyComplex& comp2) {
		double real = comp1.real + comp2.real;
		double imaginary = comp1.imaginary + comp2.imaginary;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}

	friend void operator-(const MyComplex& comp1, const MyComplex& comp2) {
		double real = comp1.real - comp2.real;
		double imaginary = comp1.imaginary - comp2.imaginary;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}

	friend void operator*(const MyComplex& comp1, const MyComplex& comp2) {
		double real = (comp1.real * comp2.real) - (comp1.imaginary * comp2.imaginary);
		double imaginary = (comp1.real * comp2.imaginary) + (comp1.imaginary * comp2.real);

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}


	friend void operator/(const MyComplex& comp1, double number) {

		double real = comp1.real / number;
		double imaginary = comp1.imaginary / number;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}


	//overloaded versions of + - *

	friend void operator+(const MyComplex& comp1, double number) {
		double real = comp1.real + number;
		double imaginary = comp1.imaginary;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}


	friend void operator-(const MyComplex& comp1, double number) {
		double real = comp1.real - number;
		double imaginary = comp1.imaginary;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}

	friend void operator*(const MyComplex& comp1, double number) {
		double real = (comp1.real * number);
		double imaginary = comp1.imaginary;

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}


	//overloaded version of / operator
	friend void operator/(const MyComplex& comp1, const MyComplex& comp2) {

		double real = (((comp1.real * comp2.real) + (comp1.imaginary * comp2.imaginary)) / ((comp2.real * comp2.real) + (comp2.imaginary * comp2.imaginary)));
		double imaginary = (((comp1.imaginary * comp2.real) - (comp1.real * comp2.imaginary)) / ((comp2.real * comp2.real) + (comp2.imaginary * comp2.imaginary)));

		if (imaginary >= 0)
		{
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << "+" << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << "+" << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}
		}
		else {
			if ((real != 0) && (imaginary != 0))
			{
				cout << real << imaginary << "i" << endl;
			}
			else if (real == 0)
			{
				cout << imaginary << "i" << endl;
			}
			else if (imaginary == 0)
			{
				cout << real << endl;
			}

		}

	}


	double addComplex(MyComplex& comp1)
	{
		return (comp1.real + comp1.imaginary);
	}



private:
	//private members
	double real;
	double imaginary;
};