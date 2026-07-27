#include <iostream>

using namespace std;

// to reduce excessive amount of function calls
// make call once and utilize it in further calls
// we can use static/global variables
//! Memoization Approach(storing value of calls for further utilization)

const int len = 20;
long long F[len];

long long fib(int n)
{
    if (n <= 1)
    {
        F[n] = n;
        return n;
    }
    else
    {
        // check if value exists
        if (F[n-2]==-1) 
        {
            F[n-2] = fib(n-2);
        }
        if (F[n-1]==-1)
        {
            F[n-1] = fib(n-1);
        }
    }
    return F[n-2] + F[n-1];
}


int main(){
    for (int i = 0; i < len; i++)
    {
        F[i]  = -1;
    }
    int n = 6;
    cout << fib(n) << endl;
    return 0;
}