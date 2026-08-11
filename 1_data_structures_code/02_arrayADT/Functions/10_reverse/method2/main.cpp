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
void Reverse2(Array *arr);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    Reverse(&arr);
    Display(arr);
    return 0;
}

void Reverse(Array *arr)
{
    for (int i = 0, l = arr->length - 1; i < (l+1)/2; i++)
    {
        // swapping
        int temp = arr->A[i];
        arr->A[i] = arr->A[l - i];
        arr->A[l - i] = temp;
    }
}

// much better
void Reverse2(Array *arr)
{
    for (int i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        // swapping
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
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
