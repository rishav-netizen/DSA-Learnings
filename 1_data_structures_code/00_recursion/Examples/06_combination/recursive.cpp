#include <iostream>

using namespace std;

int C(int n, int r)
{
    if (r==0 || n==r)
    {
        return 1;
    }
    return C(n-1, r-1) + C(n-1, r);
    
}

int main(){
    int n = 5, r = 3;
    cout << C(n ,r) << endl;
    return 0;
}