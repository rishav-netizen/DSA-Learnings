#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
void Set(Array *arr, int index, int value);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    Set(&arr, 0, 10);
    Display(arr);
    return 0;
}

void Set(Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {   
        arr->A[index] = value;
    }   
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
