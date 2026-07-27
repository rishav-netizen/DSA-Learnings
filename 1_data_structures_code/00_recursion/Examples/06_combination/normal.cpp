#include <iostream>

using namespace std;

int fact(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int C(int n, int r)
{
    int t1 = fact(n);
    int t2 = fact(r);
    int t3 = fact(n - r);
    return (t1)/(t2 * t3);
}

int main(){
    int n = 5, r = 3;
    cout << C(n ,r) << endl;
    return 0;
}