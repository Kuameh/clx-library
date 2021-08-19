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

#include "complex.h"
#include <iostream>
// #include <string>


int main() {
	complex z(5,4);
	complex w(1,1.0);
    complex ans;

    // ans = z + z;
    // (z - w).print();
    // (z * w).print("std");
    // (z / w).print("std");
    // w.print("polr");
    // ans.print("std");
    // std::cout << z.get_mod();

    std::cout << (z==z) << std::endl;
    (-z).print("std");
    (z - (--z)).print("std");

    // ans = (z + w) * (z / w) - z;
    // (z - --z).print("std");
    // ans.print();
    // ans.print("std");
    // ans.print("polr");

	return 0;
}
//0543913286