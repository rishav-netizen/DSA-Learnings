#include <iostream>

using namespace std;

int sum_recursive(int n) // Space, Time: O(n)
{
    if(n==0)
    {
        return 0;
    }
    return n + sum_recursive(n-1);
}

int sum_mathematical(int n) // O(1)
{
    return n*(n+1)/2;
}

int sum_iterative(int n) // O(n)
{
    int result = 0;
    for (int i = 1; i < n+1; i++)
    {
        result += i;
    }
    return result;
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    cout << "Sum of first " << n << " natural numbers: " << sum_recursive(n) << endl;
    return 0;
}