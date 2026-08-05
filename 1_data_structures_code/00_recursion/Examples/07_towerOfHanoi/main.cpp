#include <iostream>

using namespace std;

long long steps = 0;
// TOH(number of disks, source, helper, destination)
void TOH(int n, char A, char B, char C)
{
    if (n == 0)
    {
        return;
    }

    TOH(n - 1, A, C, B);
    steps++;
    cout << "Moved disk from " << A << " to " << C << endl;
    TOH(n - 1, B, A, C);
    
}

int main()
{
    int n;
    cout << "Disks: ";
    cin >> n;
    TOH(n, 'A', 'B', 'C');
    cout << "Disks: " << n << " | Steps: " << steps << endl;
    // steps = (2^n) - 1
    return 0;
}