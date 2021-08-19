#include "complex.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


    // print function to output results
    void complex::print()
        {
            std::cout << "complex number: " << "(" << real << ", " << img << ")" << std::endl;
        }
    void complex::print(std::string frm)
        {
            if(frm == "std")
                {
                    if(img < 0) 
                        std::cout << "complex number(std form): " << real << img << "i" << std::endl;
                    else 
                        std::cout << "complex number(std form): " << real << "+" << img << "i" << std::endl;
                        
                }
            else if(frm == "polr")
                {
                    if(arg < 0) 
                        std::cout << "complex number(polr form): " << std::setprecision(2) << mod << "[cos" << "(" << arg * -1 << ") - isin(" << arg * -1 << ")]" << std::endl;
                    else 
                        std::cout << "complex number(polr form): " << std::setprecision(2) << mod << "[cos" << "(" << arg << ") + isin(" << arg << ")]" << std::endl;
                };
        }

    /* Getters */
    double complex::get_real() { return real; } // Returns value of the real part

    double complex::get_img() { return img; } // Returns value of the imaginary part
    
    double complex::get_mod() { return mod; } // Returns value of the modulus

    double complex::get_arg() { return arg; } // Returns value of the argument


    /* Operator Overloaders */
    //addition operator overloading
    complex complex::operator +(complex c){
        complex temp;
        //real and img holds value of the expression to the left of the + operator
        // c.real and c.img holds value of the expression to the rigth of the + operator
        temp.real = real + c.real;
        temp.img = img + c.img;

        return temp;
    }

    // Conjugate operator: returns the conjugate of a complex number
    complex complex::operator --(){
        complex temp;
        
        temp.real = real;
        temp.img = img * -1;

        return temp;
    }

    // Negator
    complex complex::operator -(){
        complex temp;
        
        temp.real = real * -1;
        temp.img = img * -1;

        return temp;
    }

    //Subtraction operator
    complex complex::operator -(complex c){
        complex temp;
        //real and img holds value of the expression to the left of the - operator
        // c.real and c.img holds value of the expression to the rigth of the - operator
        temp.real = real - c.real;
        temp.img = img - c.img;

        return temp;
    }

    // Multiplication operator
    complex complex::operator *(complex c){
        complex temp;
        //real and img holds value of the expression to the left of the * operator
        // c.real and c.img holds value of the expression to the rigth of the * operator
        // z = (a+bi) , w = (x+yi)
        // z*w = (ax - by) + i(ay + bx)
        temp.real = (real * c.real) - (img * c.img);
        temp.img = (real * c.img) + (img * c.real);

        return temp;
    }

    complex complex::operator /(complex c){
        complex temp;
        //real and img holds value of the expression to the left of the / operator
        // c.real and c.img holds value of the expression to the rigth of the / operator
        // z = (a+bi) , w = (x+yi)
        // z/w = [ (ax + by)/(x^2 + y^2) ] + i[ (yb - xa)/(x^2 + y^2) ]
        temp.real = ( (real * c.real) + (img * c.img) ) / ( (c.real * c.real) + (c.img * c.img) );
        temp.img = ( (c.real * img) - (c.img * real) ) / ( (c.real * c.real) + (c.img * c.img) );

        return temp;
    }

    bool complex::operator ==(complex c){
        complex temp;
        
        if (temp.real == c.real && temp.img == c.img)
        {
            return true;
        }
        
        return false;
    };