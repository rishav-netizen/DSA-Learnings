// inserting element in a sorted list
#include <iostream>
#include <cctype>

using namespace std;

void Display(int *arr, int length);
void Input(int *arr, int length);
void Insert(int *arr, int *length, int item);

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
    
    A = new int[size + 1];

    Input(A, size);
    Display(A, size);
    
    int insertionItem;
    cout << "Enter item to be inserted: ";
    cin >> insertionItem;
    
    Insert(A, &size, insertionItem);
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

void Insert(int *arr, int *length, int item)
{
    int i = *(length) - 1;
    while (i>=0 && arr[i] > item)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = item;
    *(length) += 1;
}