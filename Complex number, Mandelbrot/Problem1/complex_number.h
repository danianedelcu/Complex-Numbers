#pragma once
#include <string>
#include <istream>
#include <fstream>
#include <ostream>
enum class DisplayType {
	RECTANGULAR_FORM,
	POLAR_FORM,
	
};

class Complex {
	static DisplayType DISPLAY_TYPE;

public:
	Complex();
	Complex(float x, float y);


	float getReal() const;
	float getImag() const;

	void setReal(float x);
	void setImag(float y);

	static void(setDisplayType(DisplayType dt));
	static DisplayType getDisplayType();

	Complex conjugate(); 
	Complex add(const Complex& c);
	Complex subtract(const Complex& c);
	Complex multiply(const Complex& c) const;
	void multiply(float c);

	bool equals(const Complex& c) const;

	float phase() const;
	float magnitude()const;
	void toPolar(float* r, float* theta) const;

	Complex operator+(const Complex& other);
	Complex operator-(const Complex& other);
	friend Complex operator*(const Complex& c1, const Complex& c2);

	std::string toString()const;

	friend std::ostream& operator<<(std::ostream& sstr, const Complex& c);
	friend std::istream& operator>>(std::istream& is, Complex& c);

private:
	float real;
	float imag;
};

void display_mandelbrot(int width, int height, int max_its);










