#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(const Array& arr); // for read only functions i can do this
void Input(Array *arr);
int BinarySearchIterative(Array arr, int key);
int BinarySearchRecursive(Array arr, int key, int l, int h);

int main(){
    Array arr;
    cout << "Enter array size: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    
    int length;
    cout << "Enter the number of numbers: ";
    cin >> length;
    cout << "Enter elements(sorted)" << endl;
    
    while (length < 0 || length > arr.size)
    {
        cout << "Invalid input! Length must be smaller than size!" << endl;
        cout << "Try again: ";
        cin >> length;
    }
    arr.length = length;
    
    Input(&arr);
    Display(arr);
    
    int key;
    cout << "Enter element you wanna binary search: ";
    cin >> key;
    int index = BinarySearchRecursive(arr, key, 0, arr.length - 1);
    if (index == -1)
    cout << "Element not found." << endl;
    else   
    cout << "Element found at index " << index << endl; 
    
    delete[] arr.A;
    return 0;
}

int BinarySearchRecursive(Array arr, int key, int l, int h)
{
    if (l <= h)
    {
        int m = (l + h) / 2;
        if (arr.A[m] == key)
            return m;
        else if (arr.A[m] > key)
            return BinarySearchRecursive(arr, key, l, m - 1);
        else
            return BinarySearchRecursive(arr, key, m + 1, h);
    }
    return -1;
}

int BinarySearchIterative(Array arr, int key)
{
    int l = 0, h = arr.length - 1, m = (h+l)/2;
    while (l <= h)
    {
        m = (h+l)/2;
        if (arr.A[m] == key)
        {
            return m;
        }
        else if (arr.A[m] > key)
        {
            h = m - 1;
        }
        else 
        {
            l = m + 1;
        }
    }
    return -1;
}

void Display(const Array& arr)
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