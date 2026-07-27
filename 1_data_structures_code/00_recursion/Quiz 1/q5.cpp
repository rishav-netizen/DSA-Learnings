#include <iostream>

using namespace std;

void count(int n) 
{
    static int d = 1; 
    cout << n; 
    cout << d; 
    d++; 
    if (n > 1) count (n-1); 
    cout << d;
} 
/* Activation stack
c(1), d = 4, n = 1, #HOLD print(d) // here d = 4 finally 
c(2), d = 3, n = 2, #HOLD print(d)
c(3), d = 2, n = 3, #HOLD print(d)

OUTPUT: 3 1 2 2 1 3 4 4 4
*/

int main()
{ 
    count(3);
    return 0;
}