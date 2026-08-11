// inserting element in a sorted list
#include <iostream>
#include <cctype>

using namespace std;

void Display(int *arr, int length);
void Input(int *arr, int length);
void Segregate(int *arr, int length);
void Swap(int *a, int *b);

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
    
    A = new int[size + 1]; // since i am making an insertion

    Input(A, size);
    Display(A, size);

    cout << "Segregated negatives and positives.\n";
    Segregate(A, size);
    Display(A, size);

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

void Segregate(int *arr, int length) // negatives on left and positives on right
{
    int i = 0, j = length - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++;
        }
        while (arr[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            Swap(arr + i, arr + j);
        }   
    }
    
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}