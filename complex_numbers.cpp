    /* In this code I'm trying to perform addition of complex numbers. 
     * Example z=(2,3) and w=(3,5). normally you perform
     * z+w => (2,3) + (3,5) => (2+3, 3+5) = (5,8)
     * 
     * To archieve this as naturally as possible in C++, 
     * we can implement this by redefining how the + operator does addition.
     * 
     * Backgroud Check: the + operator is a binary operator. To put it simply, it 
     * always expects a single expression on each side of the operator, ie. (expression + expression).
     * So doing somthing like (2,3) + (3,5) in C++ will just not work.
     * That's where operator overloading comes in. Operator overloading simply put is just re-teaching 
     * C++ how to do alreadey definded operations, like addition.
     * 
     * So in the case of the before mentioned example, We are going to teach C++ that, when we delcear
     * a complex number as (r,i) for two numbers say z and w. In adding them, the + operator should add the real parts
     * ie. r's and the imaginary parts ie. the i's
     * 
     * <pre>
     * complex operator +(complex c){
            complex temp;
            temp.real = real + c.real;
            temp.img = img + c.img;

            return temp;
        }
        </pre>
     * Operator Overloading syntax.
     * We are defining the new use of the + operator in the scope of complex numbers, Hence we declear
     * it with data type of complex. Followed by the keyword <code>operator</code> and next, the operator to be
     * overloaded(eg. +, -, ==). Next we pass in a parameter which usaully is the expression to the rigth of the
     * operator. The rest of the code in the barceses are not specific to operator overloading but specific 
     * to how you want the new operation to be performed(ie. this is where the teaching happens).
     *
     */

    // TODO: 
    // Add conjugate operator

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>


class complex{
    private: 
        double real;
        double img;
        double mod;
        double arg;
    
    public:
        // default constractor
        complex(){
            real = 0;
            img = 0;
        }
        //constructor
        complex(double r, double i){
            real = r;
            img = i;

            // Modulus
            mod = pow( ((real * real) + (img * img)) , 0.5 );

            // Argument
            arg = atan(img / real);
        }

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
        double get_real() { return real; } // Returns value of the real part

        double get_img() { return img; } // Returns value of the imaginary part
        
        double get_mod() { return mod; } // Returns value of the modulus

        double get_arg() { return arg; } // Returns value of the argument



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


};

int main() {
	complex z(5.0,4.0);
	complex w(1.0,1.0);
    complex ans;

    // ans = z + z;
    // (z - w).print();
    // (z * w).print("std");
    // (z / w).print("std");
    // w.print("polr");
    // ans.print("std");
    // std::cout << z.get_mod();

    ans = (z + w) * (z / w) - z;
    (z * -z).print("std");
    // ans.print();
    // ans.print("std");
    // ans.print("polr");

	return 0;
}
//0543913286