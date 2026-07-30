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
int LinearSearchTransposition(Array arr, int key);
int LinearSearchMoveToHead(Array arr, int key);
void swap(int *a, int *b);

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

    int key;
    cout << "Enter element you wanna linear search: ";
    cin >> key;

    int index = LinearSearchMoveToHead(arr, key);
    // int index = LinearSearchTransposition(arr, key);

    if (index == -1)
        cout << "Element not found." << endl;
    else   
        cout << "Element found at index " << index << endl; 

    Display(arr);
    delete[] arr.A;
    return 0;
}

// slow reduction in time for searching
int LinearSearchTransposition(Array arr, int key) 
{
    for(int i = 0, l = arr.length; i < l; i++)
    {
        if (key == arr.A[i])
        {
            if (i > 0)
            {
                swap(&(arr.A[i]), &(arr.A[i-1]));
                return i - 1;
            }
            return 0; //best case scenario
        }
    }
    return -1;
}

// sudden reduction in searching time
int LinearSearchMoveToHead(Array arr, int key) 
{
        for(int i = 0, l = arr.length; i < l; i++)
    {
        if (key == arr.A[i])
        {
            swap(&arr.A[0], &arr.A[i]);
            return 0;
        }
    }
    return -1;
}

void swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
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

