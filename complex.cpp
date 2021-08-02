#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

        // print function to output results
        void print()
            {
                std::cout << "complex number: " << "(" << real << ", " << img << ")" << std::endl;
            }
        void print(std::string frm)
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
        double  get_real()
            {
                return real; // Returns value of the real part
            }

        double get_img()
            {
                return img; // Returns value of the imaginary part
            }
        
        double get_mod()
            {
                return mod; // Returns value of the modulus
            }

        double get_arg()
            {
                return arg; // Returns value of the argument
            }


                                /* Operator Overloaders */

        //addition operator overloading
        complex operator +(complex c){
            complex temp;
            //real and img holds value of the expression to the left of the + operator
            // c.real and c.img holds value of the expression to the rigth of the + operator
            temp.real = real + c.real;
            temp.img = img + c.img;

            return temp;
        }

        // Conjugate operator: returns the conjugate of a complex number
        complex operator -(){
            complex temp;
            
            temp.real = real;
            temp.img = img * -1;

            return temp;
        }

        //Subtraction operator
        complex operator -(complex c){
            complex temp;
            //real and img holds value of the expression to the left of the - operator
            // c.real and c.img holds value of the expression to the rigth of the - operator
            temp.real = real - c.real;
            temp.img = img - c.img;

            return temp;
        }

        // Multiplication operator
        complex operator *(complex c){
            complex temp;
            //real and img holds value of the expression to the left of the * operator
            // c.real and c.img holds value of the expression to the rigth of the * operator
            // z = (a+bi) , w = (x+yi)
            // z*w = (ax - by) + i(ay + bx)
            temp.real = (real * c.real) - (img * c.img);
            temp.img = (real * c.img) + (img * c.real);

            return temp;
        }

        complex operator /(complex c){
            complex temp;
            //real and img holds value of the expression to the left of the / operator
            // c.real and c.img holds value of the expression to the rigth of the / operator
            // z = (a+bi) , w = (x+yi)
            // z/w = [ (ax + by)/(x^2 + y^2) ] + i[ (yb - xa)/(x^2 + y^2) ]
            temp.real = ( (real * c.real) + (img * c.img) ) / ( (c.real * c.real) + (c.img * c.img) );
            temp.img = ( (c.real * img) - (c.img * real) ) / ( (c.real * c.real) + (c.img * c.img) );

            return temp;
        }