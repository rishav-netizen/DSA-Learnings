#include <iostream>

using namespace std;

double e_loop(int x, int n)
{
    double s = 1;
    while (n > 0)
    {
        s = 1+((x*1.0)/n)*s;
        n--;
    }
    return s;
}

double e_recursive(int x, int n)
{
    static double s = 1;
    if (n == 0)
    {
        return s;
    }
    s = 1+((x*1.0)/n)*s;
    return e_recursive(x, n - 1);
}

int main()
{
    cout << e_recursive(1, 19) << "\n";
    return 0;
}