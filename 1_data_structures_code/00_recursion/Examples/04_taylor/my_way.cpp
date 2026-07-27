#include <iostream>
#include <cmath>

using namespace std;

double fact(int n)
{
    double result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

double e(int x, int n)
{
    if (n == 1)
    {
        return 1;
    }
    return (pow(x, n-1)/fact(n-1)) + e(x, n - 1);

}               

int main(){             
    cout << e(1, 19) << endl;
    return 0;
}

