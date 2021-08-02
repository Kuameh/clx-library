# clx-library

[![MIT License](https://img.shields.io/apm/l/atomic-design-ui.svg?)](https://github.com/tterb/atomic-design-ui/blob/master/LICENSEs)

A simple library to help handle complex number arithmetic in C++ code.

In this code I'm trying to perform complex number arithmetic.
Example z=(2,3) and w=(3,5). normally you perform
z+w => (2,3) + (3,5) => (2+3, 3+5) = (5,8)

To archive this as naturally as possible in C++,
we can implement this by redefining the default operator.

Background Check: the + operator is a binary operator. To put it simply, it
always expects a single expression on each side of the operator, ie. (expression + expression).
So doing something like (2,3) + (3,5) in C++ will just not work.
That's where operator overloading comes in. Operator overloading simply put is just re-teaching
C++ how to do already defined operations, like addition.

So in the case of the before mentioned example, We are going to teach C++ that, when we declare
a complex number as (r,i) for two numbers say z and w. In adding them, the + operator should add the real parts
ie. the r's and the imaginary parts ie. the i's

```cpp
  complex operator +(complex c){
    complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    
    return temp;
  }
```

Operator Overloading syntax.
We are defining the new use of the + operator in the scope of complex numbers, Hence we declare
it with data type of complex. Followed by the keyword `operator` and next, the operator to be
overloaded(e.g. +, -, ==). Next we pass in a parameter which usually is the expression to the right of the
operator. The rest of the code in the barceses are not specific to operator overloading but specific 
to how you want the new operation to be performed(i.e. this is where the 'teaching happens').


## Features

- Complex number: \
  \- Addition\
  \- Subtraction\
  \- Multiplication\
  \- Division
- Pretty printing complex numbers in:\
  \- standard form `a + bi` \
  \- polar form `r(cos&theta; + sin&theta;)`

## Installation

Download the files and link to your project.\
Add the code below to `include` statements of your project.

```cpp
  #include "complex.h"
```

## Documentation

The keyword `complex` is used to create an instance of the complex number.

```cpp
    complex my_clx_num;
```
You can initialize the complex number with values. The first value is the real part, and the second value is the imaginary part of the complex number.
```cpp
    complex my_clx_num(4, 5);
```
### Methods
| Method | Arguments | Type | Description |
| ------------ | ------------ | ------------ | ------------- |
| `.print()` | `"std"` , `"polr"` | return: `string` , argument: `string` | Use `"std"` to print standard form, `"polr"` to print polar form. Leave it empty to print in rectangular form.|
| `.get_real()` | none | return: `double` | Returns value of the real part of the complex number  |
| `.get_img()` | none | return: `double` | Returns value of the imaginary part of the complex number  |
| `.get_mod()` | none | return: `double` | Returns value of the modulus of the complex number  |
| `.get_arg()` | none | return: `double` | Returns value of the argument of the complex number  |

### Operators
> Operator precedence follows C++ defaults

| Operation | Symbol | Description |
| ------------ | ------------- | ------------- |
| Addition | `+` | Adds two or more complex numbers. |
| Subtraction | `-` | Subtracts two more complex numbers. |
| Multiplication | `*` | Multiplies two more complex numbers. |
| Division | `/` | Divides two more complex numbers. |
| Inverse/Conjugate | `--` | Makes the conjugate of the given number. |
| Negator | `-` | Negates all the values of the complex number if they are positive, ie. multiplies the complex number with `-1` |


## Usage/Examples

**Pretty Printing**
```cpp
#include "complex.h"

int main() {
    complex z(5.0,4.0);
    complex w(1.0,1.0);
    complex ans;

    ans = z + w;
    
    ans.print();
    ans.print("std");
    ans.print("polr");


 return 0;
}
```
Output
```
  complex number: (6, 5)
  complex number(std form): 6+5i
  complex number(polr form): 0[cos(0) + isin(0)]
```
\
\
**Multiple Operators**
```cpp
#include "complex.h"

int main() {
    complex z(5.0,4.0);
    complex w(1.0,1.0);
    complex ans;

    ans = (z + w) * (z / w) - z;
    
    ans.print();
    ans.print("std");
    ans.print("polr");
    
 return 0;
}
```
Output
```
  complex number: (24.5, 15.5)
  complex number(std form): 24.5+15.5i
  complex number(polr form): 0[cos(2.1e-317) + isin(2.1e-317)]
```
\
\
**Inverse & Subtraction**
```cpp
#include "complex.h"

int main() {
    complex z(5.0,4.0);
    complex w(1.0,1.0);

    (--z).print("std");
    (-z).print("std");
    (z - (--z)).print("std");


return 0;
}
```
Output
```
  complex number(std form): 5-4i
  complex number(std form): -5-4i
  complex number(std form): 0+8i
```

## Roadmap

- Add comparison operator.
- Convert into a shared library.
