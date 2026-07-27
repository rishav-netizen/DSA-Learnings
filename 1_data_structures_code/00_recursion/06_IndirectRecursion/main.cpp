//? More than one function call one another in indirect fashion

#include <iostream>

using namespace std;

void funA(int n);
void funB(int n);

int main()
{
    funA(20);
    /*
    funA(3) Activation stack
                B(0)
            A(1)
        B(2)
    A(3)



    OUTPUT:
    3
    2
    1
    */


    funB(20);
    /*
    funB(3) Activation stack
             B(0)
        A(1)
    B(3)

    OUTPUT:
    3
    1
    */

    return 0;
}

void funB(int n)
{
    if (n > 1)
    {
        cout << n << endl;
        funA(n/2);
    }
}

void funA(int n)
{
    if (n>0)
    {
        cout << n << endl;
        funB(n-1);
    }
}
