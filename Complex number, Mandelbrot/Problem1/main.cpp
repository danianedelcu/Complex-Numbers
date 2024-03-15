#define _CRT_SECURE_DEBUG_NO_WARNINGS
#include <iostream>
using namespace std;
#include "mandelbrot.h"

#include "complex_test.h"

int main(int argc, char** argv) {
#if ENABLE_TESTS > 0
	run_complex_tests(false);
#endif
	//stack
	Complex c1 = Complex(4, 5);
	//heap
	Complex* c2 = new Complex(40, 50);
	c1.conjugate();
	c2->conjugate();
	c1.add(*c2);
	c2->subtract(c1);
	c2->multiply(c1);
	c1.equals(*c2);
	c1.phase();
	c2->magnitude();

	Complex::setDisplayType(DisplayType::RECTANGULAR_FORM);

	display_mandelbrot(100, 25, 100);
	return 0;
}