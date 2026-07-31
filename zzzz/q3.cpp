#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, a, b, x;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> x;
        int tries = 0;
        if (a == b)
        {
            cout << 0 << endl;
        }
        else
        {
            int max = (a > b) ? a : b;
            int min = a + b - max;
            while ((max - min != 1) && (max - min != -1))
            {
                tries++;
                max /= x;
            }
            cout << tries + 1 << endl;
        }
    }

    return 0;
}