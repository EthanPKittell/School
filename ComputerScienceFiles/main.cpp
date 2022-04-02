#include "HW6.h"

int main()
{
	MyComplex complex;
	MyComplex complex2;
	double number;

	operator >> (cin, complex);
	operator >> (cin, complex2);

	/*operator + (complex, complex2);
	operator - (complex, complex2);
	operator * (complex, complex2);*/
	cout << "enter a number to act as the second operand for the following functions" << endl;
	cin >> number;
	operator + (complex, number);
	operator - (complex, number);
	operator * (complex, number);
	operator / (complex, number);
	operator / (complex, complex2);
	cout << "Before conjugate: " << endl;
	complex.printComplex(complex);
	complex.conjugate();
	cout << "After conjugate" << endl;
	complex.printComplex(complex);



	return 0;
}
