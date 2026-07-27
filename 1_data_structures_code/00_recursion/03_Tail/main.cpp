#include <iostream>

using namespace std;

//? Time O(n)
//? Space O(n)
void func(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        func(n-1);
    }
}

//? Time O(n)
//? Space O(1)
void func2(int x)
{
    while (x)
    {
        cout << x << endl;
        x--;
    }
}

int main()
{
    int x = 5;
    func(x);

    cout << endl;
    // same thing using loop
    func2(x);
    
    return 0;
}