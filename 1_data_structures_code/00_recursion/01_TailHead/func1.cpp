#include <iostream>

using namespace std;

void fun1(int n);

int main()
{
    int x = 3;
    fun1(x);
    return 0;
}

//! tail recursion (work happens before the recursive call)
void fun1(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        fun1(n-1);
    }
    
}