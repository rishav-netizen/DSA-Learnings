#include <iostream>

using namespace std;

int x = 0;
int func(int n);

int main()
{
    int a = 5;
    cout << func(a) << endl;
    // 25
    cout << func(a) << endl;
    // 50
    return 0;
}

int func(int n)
{
    if (n > 0)
    {   
        x++;
        return func(n-1) + x;
    }
    return 0;   
}

/* Activation stack (first call)
func(0) + 5
func(1) + 5
func(2) + 5
func(3) + 5
func(4) + 5
func(5)
*/