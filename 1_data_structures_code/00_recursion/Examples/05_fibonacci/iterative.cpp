#include <iostream>

using namespace std;

// Time: O(n)
int fib_iterative(int n)
{
    long long t_0 = 0, t_1 = 1, s, i;
    if (n <= 1) return n;
    for (i = 2; i <= n ; i++)
    {
        s = t_0 + t_1;
        t_0 = t_1;
        t_1 = s;
    }
    return s;
}

int main(){
    int n = 11;
    for (int i = 0; i < n; i++)
    {
        cout << fib_iterative(i);
        if (i < n-1)
        {
            cout << ", ";
        }
        
    }
    
    return 0;
}