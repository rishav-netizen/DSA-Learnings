#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Array
{
    int *A;
    int size;
    int length;
} Array;

void Display(Array arr);
void Input(Array *arr);

int main(){
    Array arr;
    cout << "Enter array size: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;

    int length;
    cout << "Enter the number of numbers: ";
    cin >> length;
    while (length < 0 || length > arr.size)
    {
        cout << "Invalid input! Length must be smaller than size!" << endl;
        cout << "Try again: ";
        cin >> length;
    }
    arr.length = length;

    Input(&arr);
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

void Input(Array *arr)
{
    for (int i = 0, l = arr -> length; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr -> A[i];
    }

}