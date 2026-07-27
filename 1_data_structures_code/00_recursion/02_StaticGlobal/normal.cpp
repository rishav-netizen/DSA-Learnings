#include <iostream>

using namespace std;

int func(int n);

int main()
{
    int x = 5;
    cout << func(x) << endl;
    // 15
    return 0;
}

int func(int n)
{
    if (n > 0)
    {   
        return func(n-1) + n;
    }
    return 0;   
}

/* Activation stack
func(0) + 1
func(1) + 2
func(2) + 3
func(3) + 4
func(4) + 5
func(5)
*/