#include <stdio.h>
#include <stdlib.h>
#include "mandelbrot.h"
#define Yellow "\033[0;33m"
#define Red "\033[0;31m"
#include "complex_number.h" 
#include <iostream>
void display_mandelbrot(int width, int height, int max_its)
{

    const float x_start = -3.0f;
    const float x_fin = 1.0f;
    const float y_start = -1.0f;
    const float y_fin = 1.0f;

    double dx = (x_fin - x_start) / (width - 1);
    double dy = (y_fin - y_start) / (height - 1);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {


           
            // create complex number z = 0 + 0i
            // create complex number c =  x_start+ x*dx + (y_start+y*dy)i
             Complex z = Complex(0, 0);
             Complex c = Complex(x_start + (x * dx), (y_start + (y * dy)));
            int iteration = 0;
            // while |z| < 2 and we haven't reach max_its
            while (/* TODO your code here: |z| < 2&& */z.magnitude() < 2 && ++iteration < max_its) {
                // apply the rule:  z =  z*z + c
                z = z * z + c;
            }

            
            if (iteration == max_its) {
                std::cout << "*";
            }
            else {
                std::cout << "-";
            }

        }
        std::cout << std::endl;
    }
}