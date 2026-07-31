#include <iostream>

using namespace std;

int main(){
    int t, n, max = -1, min = 100;
    cin >> t;
    while (t--)
    {
        max = -1;
        min = 100;
        cin >> n;
        int H[n];
        for (int i = 0; i < n; i++)
        {
            cin >> H[i];
            if (H[i] > max)
            {
                max = H[i];
            }
            if(H[i] < min)
            {
                min = H[i];
            }
        }
        cout << max - min + 1 << endl;
    }
    
    return 0;
}
