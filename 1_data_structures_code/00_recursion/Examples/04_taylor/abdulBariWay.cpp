#include <iostream>

using namespace std;

// using static varibles
double e(int x, int n)
{
    double result;
    static long double p = 1, f = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        result = e(x, n-1);
        p *= x;
        f *= n;
        return result + (p/f);
    }
}

int main(){
    cout << e(1, 19) << endl;
    return 0;
}