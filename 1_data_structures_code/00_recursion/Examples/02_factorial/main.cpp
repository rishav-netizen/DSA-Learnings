#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fact_recursive(int n)
{
    if (n == 0) return 1;
    return n * fact_recursive(n-1);
}

int fact_iterative(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    cout << n << "! = " << fact_recursive(n) << endl;
    return 0;
}