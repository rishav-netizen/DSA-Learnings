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
void Insert(Array *array, int index, int element);

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

    int insert_index, element;
    cout << "Enter index where u wanna insert element: ";
    cin >> insert_index;
    cout << "Enter element: "; 
    cin >> element;

    Insert(&arr, insert_index, element);
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

void Insert(Array *array, int index, int element)
{
    if ((index >= 0) && (index <= array->length) && array->length < array->size)
    {
        // shift all elements one place forward to leave space at the index for new element
        for(int i = array -> length; i > index; i--)
        {
            array->A[i] = array -> A[i - 1];
        }
        array->A[index] = element;
        array->length++;
    }
}