// inserting element in a sorted list
#include <iostream>
#include <cctype>

using namespace std;

void Display(int *arr, int length);
void Input(int *arr, int length);
bool isSorted(int *arr, int length);

int main()
{
    int *A;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    while (size < 1)
    {
        cout << "Try again: ";
        cin >> size;
    }
    
    A = new int[size];

    Input(A, size);
    Display(A, size);
    bool sorted = isSorted(A, size);
    if (sorted) 
    {
        cout << "Array is sorted!\n";
    }
    else 
    {
        cout << "Array is not sorted!\n";
    }
    delete[] A;

    return 0;
}

void Display(int *arr, int length)
{
    cout << "Elements of the array are: {";
    for (int i = 0; i < length; i++)
    {   
        cout << arr[i];
        if (i < length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void Input(int *arr, int length)
{   
    cout << "Sorted array.\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }   
}

bool isSorted(int *arr, int length)
{
    bool ascendingSorted = true, descendingSorted = true; // flags
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1]) // false condition
        {
            ascendingSorted = false;
        }
        if (arr[i] < arr[i + 1])
        {
            descendingSorted = false;
        }
        
    }
    return ascendingSorted or descendingSorted;
}