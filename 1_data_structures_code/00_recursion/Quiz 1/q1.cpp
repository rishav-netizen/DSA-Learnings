#include <iostream>

using namespace std;

int f(int n)
{
    static int i = 1;
    if (n>=5)return n;
    n = n+i;
    i++;
    return f(n);
}
/* Activation Stack
f(7) = 7
f(7)  n = 7, i = 4 
f(4)  n = 4, i = 3
f(2)  n = 2, i = 2
f(1)  n = 1, i = 1
*/

int main(void)
{
    cout << f(1) << endl;
    return 0;
}