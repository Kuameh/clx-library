#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

class Complex{
    private: 
        double real;
        double img;
        double mod;
        double arg;
    
    public:
        // default constractor
        Complex(){
            real = 0;
            img = 0;
        }
        
        //constructor
        Complex(double r, double i){
            real = r;
            img = i;

            // Modulus
            mod = pow( ((real * real) + (img * img)) , 0.5 );

            // Argument
            arg = atan(img / real);
        }

        // print function to output results
        void print();
        void print(std::string frm);

                                    /* Getters */
        double get_real(); // Returns value of the real part

        double get_img(); // Returns value of the imaginary part
        
        double get_mod(); // Returns value of the modulus

        double get_arg(); // Returns value of the argument


                                /* Operator Overloaders */

        //addition operator overloading
        Complex operator +(Complex c);

        // Conjugate operator: returns the conjugat of a complex number
        Complex operator -();

        //Subtraction operator
        Complex operator -(Complex c);

        // Multiplication operator
        Complex operator *(Complex c);

        Complex operator /(Complex c);


};