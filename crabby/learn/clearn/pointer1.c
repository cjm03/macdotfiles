#include <stdio.h>

// The unary operator & gives the address of an object, so the statement
//                  p = &c;
// assigns the address of c to the variable p, and p is said to 'point to' c.
// The & operator only applies to objects in memory: variables and array elements. 
// It cannot be applied to expressions, constants, or 'register' variables.

// The unary operator * is the indirection or dereferencing operator; when applied
// to a pointer, it accesses the object the pointer points to. Suppose that x and y
// are integers and ip is a pointer to int. This artificial sequence shows how to 
// declare a pointer and how to use & and *:
void point()
{
    int x = 1, y = 2, z[10];
    int *ip;        // ip is a pointer to int
    ip = &x;        // ip now points to address of x
    y = *ip;        // y is now 1, the value stored at the address that ip points to (x)
    *ip = 0;        // x is now 0, this changes the value stored at the address that ip points to 
    ip = &z[0];     // ip now points to the address of z[0]
}
