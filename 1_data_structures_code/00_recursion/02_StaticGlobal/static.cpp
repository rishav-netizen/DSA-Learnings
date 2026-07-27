#include <iostream>

using namespace std;

int func(int n);

int main()
{
    int a = 5;
    cout << func(a) << endl;
    // 25
    return 0;
}

int func(int n)
{
    static int x = 0;
    if (n > 0)
    {   
        x++;
        return func(n-1) + x;
    }
    return 0;   
}

/* Activation stack
func(0) + 5
func(1) + 5
func(2) + 5
func(3) + 5
func(4) + 5
func(5)
*/