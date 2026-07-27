#include <iostream>

using namespace std;

// Time: O(n)
int exp_recursive(int m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    else if (m == 0)
    {
        return 0;
    }
    return m * exp_recursive(m, n - 1);
}

// Time: O(log n)
int opt_exp_recursive(int m, int n)
{
    if (n == 0 || m == 1)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return opt_exp_recursive(m*m, n/2);
    }
    if (m == 0)
    {
        return 0;
    }
    
    else
    {
        return m * opt_exp_recursive(m*m, (n-1)/2);
    }
}

int main(){
    int n, m;
    cout << "Base m: ";
    cin >> m;
    cout << "Exponent n: ";
    cin >> n;
    cout << m << "^" << n << " = " << opt_exp_recursive(m, n) << endl;
    return 0;
}