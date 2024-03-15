#include "complex_number.h"
#include <sstream>
#include <iomanip>
#include <iostream>
//using namespace std;
#define M_PI  3.1415926535f 

Complex::Complex() :real{ 0.0f }, imag{ 0.0f } {}
Complex::Complex(float x, float y) {
	real = x;
	imag = y;
}

float Complex::getReal() const {
	return this->real;
}

float Complex::getImag() const {
	return this->imag;
}

void Complex::setReal(float x)  { 
	real = x;
}

void Complex::setImag(float y) { 
	imag = y;
}


DisplayType Complex::DISPLAY_TYPE{DisplayType::POLAR_FORM};

DisplayType Complex::getDisplayType() {
	return DISPLAY_TYPE;
}

void Complex::setDisplayType(DisplayType dt) {
	DISPLAY_TYPE = dt;
}

Complex Complex::conjugate() {
	return Complex(real, -imag);
}

Complex Complex::add(const Complex& c) {
	return Complex(c.real + real, c.imag + imag);
}



Complex Complex::subtract(const Complex& c) {
	return Complex(real-c.real, imag-c.imag);
}



Complex Complex::multiply(const Complex& c) const { //(a+bi)(c+di)=ac+adi+cbi+bdii=ac-bd+i(ad+cb)
	return Complex(real * c.real - imag * c.imag, real * c.imag + c.real * imag);
}




void Complex::multiply(float c) {
	real = c * real;
	imag = c * imag;
}

bool Complex::equals(const Complex& c) const {
	if (real==c.real && imag==c.imag)
		return true;
	return false;
}

float Complex::magnitude() const {
	return sqrt(real * real + imag * imag);
}
float Complex::phase() const {
	return  atan2(imag, real);
}
void Complex::toPolar(float* r, float* theta) const {
	*r = magnitude();
	*theta = phase();
}

Complex Complex::operator+(const Complex& other)  //operator addition
{
	return add(other);
}

Complex Complex::operator-(const Complex& other)  //operator subtraction
{
	return subtract(other);
}

Complex operator*(const Complex& c1, const Complex& c2) //operator multiplication
{
	float real= c1.real * c2.real - c1.imag * c2.imag;
	float imag= c1.real * c2.imag + c1.imag * c2.real;
	return Complex(real, imag);
}


std::string Complex::toString() const {
	std::ostringstream sstr;
	if (real == 0 && imag == 0) {
		return "0";
	}
	else if (DISPLAY_TYPE == DisplayType::RECTANGULAR_FORM) {
		sstr << std::setprecision(2) << std::fixed << real;
		sstr << std::setprecision(2) << std::fixed << imag;

	}
	else {
		float r;
		float theta;
		toPolar(&r, &theta);
		sstr << std::setprecision(2) << std::fixed << r;
		sstr << "*(cos";
		sstr << std::setprecision(2) << std::fixed << theta<<")";
		sstr << "+i*(sin";
		sstr << std::setprecision(2) << std::fixed << theta<<")";
	}
	return sstr.str();

}


std::ostream& operator<<(std::ostream& sstr, const Complex& c) {
	sstr << c.toString();
	return sstr;
 }
std::istream& operator>>(std::istream& is, Complex& c) {
	is >> c.real >> c.imag;
	return is;
 }

