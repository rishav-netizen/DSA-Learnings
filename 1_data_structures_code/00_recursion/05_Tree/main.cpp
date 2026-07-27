#include <iostream>

using namespace std;

//? Time O(2^n)
//? Space O(n) (since same stack space was reused)
void func(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        func(n-1);
        func(n-1);
    }
}

int main()
{
    int x = 3;
    func(x);

    return 0;
}

/* Activation Stack (15 calls)

            f(0)
            f(0)
        f(1)
            f(0)
            f(0)
        f(1)
    f(2)
            f(0)
            f(0)
        f(1)
            f(0)
            f(0)
        f(1)
    f(2)
f(3)

 1   2   4   8

like gp hence, calls = 1(2^4 - 1)/(2-1)
identation to understand level
*/