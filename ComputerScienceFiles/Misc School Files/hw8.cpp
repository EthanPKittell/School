#include <iostream>
#include <string>
#include <stdexcept>
#include <math.h>
using namespace std;

long gcd(long d, long n)
{
	long temp;
	n = abs(n);
	d = abs(d);

	while (d > 0)
	{
		temp = n % d;

		n = d;
		d = temp;
	}
	return n;
};


class Rational
{
public:

	Rational() {
		numerator = 0;
		denominator = 0;
	};
	Rational(long n) : numerator(n) {};
	Rational(long n, long d) : numerator(n), denominator(d) {
		//attempts to catch error if denominator is less than 0
		if (denominator == 0)
		{
			try {
				throw invalid_argument("There has been an error");
			}
			catch (invalid_argument& e) {
				cout << "You threw an exception: " << "the denominator is not valid" << endl;
			}
		}
	};
	long returnRational() { return denominator; };
	
	friend void operator+(const Rational& obj1, const Rational& obj2) {
		//long real = comp1.numerator + comp2.numerator;
		//T imaginary = comp1.imaginary + comp2.imaginary;
		


		long newNumerator1 = obj1.numerator / gcd(obj1.numerator, obj1.denominator);
		long newDenominator1 = obj1.denominator / gcd(obj1.numerator, obj1.denominator);

		long newNumerator2 = obj2.numerator / gcd(obj2.numerator, obj2.denominator);
		long newDenominator2 = obj2.denominator / gcd(obj2.numerator, obj2.denominator);

		newNumerator1 = newNumerator1 * newDenominator2;
		newNumerator2 = newNumerator2 * newDenominator1;

		long commonDenominator = newDenominator1 * newDenominator2;

		long newNumerator3 = newNumerator1 + newNumerator2;

		if (commonDenominator < 0)
		{
			newNumerator3 = newNumerator3 * -1;
			commonDenominator = commonDenominator * -1;
		}

		cout << "These rational numbers added together result in the rational number:" << endl;
		cout << newNumerator3 << "/" << commonDenominator << endl;
	};

	friend void operator-(const Rational& obj1, const Rational& obj2) {
		
		long newNumerator1 = obj1.numerator / gcd(obj1.numerator, obj1.denominator);
		long newDenominator1 = obj1.denominator / gcd(obj1.numerator, obj1.denominator);

		long newNumerator2 = obj2.numerator / gcd(obj2.numerator, obj2.denominator);
		long newDenominator2 = obj2.denominator / gcd(obj2.numerator, obj2.denominator);

		newNumerator1 = newNumerator1 * newDenominator2;
		newNumerator2 = newNumerator2 * newDenominator1;

		long commonDenominator = newDenominator1 * newDenominator2;

		long newNumerator3 = newNumerator1 - newNumerator2;

		if (commonDenominator < 0)
		{
			newNumerator3 = newNumerator3 * -1;
			commonDenominator = commonDenominator * -1;
		}

		cout << "The rational numbers subtracted by each other result in the rational number:" << endl;
		cout << newNumerator3 << "/" << commonDenominator << endl;
	};


	friend void operator*(const Rational& obj1, const Rational& obj2) {
		
		long newNumerator1 = obj1.numerator / gcd(obj1.numerator, obj1.denominator);
		long newDenominator1 = obj1.denominator / gcd(obj1.numerator, obj1.denominator);

		long newNumerator2 = obj2.numerator / gcd(obj2.numerator, obj2.denominator);
		long newDenominator2 = obj2.denominator / gcd(obj2.numerator, obj2.denominator);

		
		long newNumerator3 = newNumerator1 * newNumerator2;
		long newDenominator3 = newDenominator1 * newDenominator2;
		
		if (newDenominator3 < 0)
		{
			newNumerator3 = newNumerator3 * -1;
			newDenominator3 = newDenominator3 * -1;
		}


		cout << "These rational numbers multiplied by each other result in the rational number:" << endl;
		cout << newNumerator3 << "/" << newDenominator3 << endl;
	};



	friend void operator/(const Rational& obj1, const Rational& obj2) {
		
		long newNumerator1 = obj1.numerator / gcd(obj1.numerator, obj1.denominator);
		long newDenominator1 = obj1.denominator / gcd(obj1.numerator, obj1.denominator);

		long newNumerator2 = obj2.numerator / gcd(obj2.numerator, obj2.denominator);
		long newDenominator2 = obj2.denominator / gcd(obj2.numerator, obj2.denominator);


		long newNumerator3 = newNumerator1 * newDenominator2;
		long newDenominator3 = newDenominator1 * newNumerator2;

		long temp = gcd(newNumerator3, newDenominator3);

		newNumerator3 = newNumerator3 / temp;
		newDenominator3 = newDenominator3 / temp;

		if (newDenominator3 < 0)
		{
			newNumerator3 = newNumerator3 * -1;
			newDenominator3 = newDenominator3 * -1;
		}

		cout << "These rational numbers divided by each other result in the rational number:" << endl;
		cout << newNumerator3 << "/" << newDenominator3 << endl;
	};

	friend ostream& operator<<(ostream& os,const Rational& obj1)
	{
		return os << "This is a the desired rational number:" << obj1.numerator << "/" << obj1.denominator << endl;
	}

	
	long numerator;
	long denominator;
};




int main()
{
	Rational obj1(270, 192);
	Rational obj2(135, -245);
	
	operator+(obj1, obj2);
	operator-(obj1, obj2);
	operator*(obj1, obj2);
	operator/(obj1, obj2);
	cout << obj1 << endl;
	/*
	Rational obj1;
	obj1.gcd(270, 192);
	*/
}

