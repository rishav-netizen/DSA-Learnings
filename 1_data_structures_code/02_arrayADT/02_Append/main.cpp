#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct Array
{
    int *A;
    int size;
    int length;
} Array;

void Display(Array array);
void Append(Array *array, int element);

int main(){
    
    Array arr;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    arr.size = n;
    arr.A = new int[n];
    arr.length = 0;
    
    int l;
    cout << "Enter the number of elements in array: ";
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr.A[i];
    }
    arr.length = l;
    
    Display(arr);
    Append(&arr, 69);
    Display(arr);
    
    return 0;
}

void Display(Array array)
{
    cout << "The array is : {";
    for (int i = 0; i < array.length; i++)
    {
        cout << array.A[i];
        if (i < array.length - 1)
        cout << ", "; 
    }
    cout << "}\n";
    
}

void Append(Array *array, int element)
{
    // array->length < array->size
    if ((*array).length < (*array).size)
    {
        array->A[array->length++] = element; 
    }

}   