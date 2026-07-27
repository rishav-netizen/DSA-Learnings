// What is the return value of f(p, p), 
// if the value of p is initialised to 5 before the call?
// Note that the first parameter is passed by reference, 
// whereas the second parameter is passed by value.
#include <iostream>
using namespace std;
int f(int &x, int c) 
{
    c = c - 1; 
    if (c == 0) return 1; 
    x = x + 1; 
    return f(x,c) * x;
}
/*  Activation stack
f(10, 0) = 1, p = 9 (at last step)
f(9, 1) * p
f(8, 2) * p
f(7, 3) * p
f(6, 4) * p
f(5, 5)
*/

int main()
{
    int p = 5;
    cout << f(p, p) << endl;
    return 0;
}