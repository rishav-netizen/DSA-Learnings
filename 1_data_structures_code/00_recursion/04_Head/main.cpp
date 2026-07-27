#include <iostream>

using namespace std;

//? Time O(n)
//? Space O(n)
void func(int n)
{
    if (n > 0)
    {
        func(n-1);
        cout << n << endl;
    }
}

//? Time O(n)
//? Space O(1)
void func2(int n)
{
    int i = 1;
    while (i<=n)
    {
        cout << i << endl;
        i++;
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