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
int LinearSearch(Array arr, int key);

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
    int index = LinearSearch(arr, key);
    if (index == -1)
        cout << "Element not found." << endl;
    else   
        cout << "Element found at index " << index << endl; 

    delete[] arr.A;
    return 0;
}

int LinearSearch(Array arr, int key)
{
    for(int i = 0, l = arr.length; i < l; i++)
    {
        if (key == arr.A[i])
            return i;
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