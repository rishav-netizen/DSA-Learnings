#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int Sum(Array arr, int l);
int Sum2(Array arr, int l);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    cout << "Sum: " << Sum2(arr, arr.length - 1) << endl;
    // same result
    // cout << "Sum: " << Sum(arr, arr.length) << endl;
    return 0;
}

//! i feel like this is better
int Sum(Array arr, int l)
{
    // l is length not index hence, it cant be = 0
    if (l <= 0 || l > arr.length)
    {
        return 0;
    }
    return Sum(arr, l - 1) + arr.A[l - 1];
}

int Sum2(Array arr, int l)
{
    // l is index, then
    if (l < 0 || l >= arr.length)
    {
        return 0;
    }
    return Sum2(arr, l - 1) + arr.A[l];
}

void Display(Array arr)
{
    cout << "Elements of the array are: {";
    for (int i = 0; i < arr.length; i++)
    {   
        cout << arr.A[i];
        if (i < arr.length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}
