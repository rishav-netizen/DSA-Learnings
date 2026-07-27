#include <iostream>

using namespace std;

// Time: O(2^n)
/*
we can find exactly the time complexity 
so we assume it to call itself like this
2*fib(n-1)
in this case we get (approximately) O(2^n)
*/
long long fib_recursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fib_recursive(n-1) + fib_recursive(n-2);
}
/* Activation Stack
        f(1)
            f(0)
            f(1)
        f(2)
    f(3)
            f(0)
            f(1)
        f(2)
            f(1)
                f(0)
                f(1)
            f(2)
        f(3)
    f(4)       
f(5)

total 15 function calls for fib(5)
fib(4) - 9 calls
fib(3) - 5 calls
we can see that the same calls are made again and again
hence its called excessive recursive function

OUTPUT:
5

*/

int main(){
    int n = 6;
    cout << fib_recursive(n) << endl;
    return 0;
}