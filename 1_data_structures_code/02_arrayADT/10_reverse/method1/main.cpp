#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
void Reverse(Array *arr);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    Reverse(&arr);
    Display(arr);
    return 0;
}

// using auxillary array
void Reverse(Array *arr)
{
    Array B = {{}, 10, arr->length};

    for (int j = 0, i = arr->length - 1; i>=0; i--, j++)
    {
        B.A[j] =  arr->A[i];
    }
    for (int i = 0, l = arr->length; i < l; i++)
    {
        arr->A[i] = B.A[i];
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
