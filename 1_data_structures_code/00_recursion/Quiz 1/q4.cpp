#include <iostream>

using namespace std;

int fun (int n)
{ 
    int x = 1, k; 

    if (n == 1) return x;

    for (k=1; k < n; ++k)
    {
        x = x + fun (k) * fun (n - k);
    }

    return x; 
}
/*
x = 1
x += f(4) * f(1)
x += f(3) * f(2)
x += f(2) * f(3)
x += f(1) * f(4)

[since f(1) = 1 we ignore it]
FOR F(5) = 51
x = 1
x += f(4)
x += f(3) * f(2)
x += f(2) * f(3)
x += f(4)

FOR F(4) = 15
x = 1
x += f(3)
x += f(2) * f(2)
x += f(3)

FOR F(3) = 5
x = 1
x += f(2)
x += f(2)

FOR F(2) = 2
x = 1
x += 1

F(1) = 1

*/
int main()
{
    cout << fun(5) << endl;
    return 0;
}