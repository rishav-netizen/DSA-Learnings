#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// void change(int *n)
// {
//     cout << *n << endl;
//     *n += 6;
//     cout << *n << endl;
//     *n += 6;
//     cout << *n << endl;
// }

//!pass by reference
void change(int &n)
{
    cout << n << endl;
    n += 6;
    cout << n << endl;
    n += 6;
    cout << n << endl;
}

int main()
{
    int n = 6;
    change(n);
    cout << n << endl;
    return 0;
}