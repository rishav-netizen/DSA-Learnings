#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// already initializing the array size without heap memory allocation
typedef struct Array
{
    int A[20];
    int size;
    int length;
} Array;

void Display(Array arr);

int main(){
    Array arr = {{1,2,3,4,5}, 20, 5};

    Display(arr);

    return 0;
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

