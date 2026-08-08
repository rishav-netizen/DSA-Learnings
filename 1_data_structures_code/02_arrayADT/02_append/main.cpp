#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(const Array &array);
void Append(Array *array, int element);
void Input(Array *array);

int main(){
    
    Array arr;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    arr.size = n;
    arr.A = new int[n];
    arr.length = 0;

    Input(&arr);
    
    Display(arr);
    Append(&arr, 69);
    Display(arr);
    
    delete[] arr.A;
    return 0;
}

void Input(Array *array)
{
    int length;
    cout << "Enter the number of elements in array: ";
    cin >> length;

    while (length < 0 || length > array->size)
    {
        cout << "Invalid input! Number of elements must be between 0 and the array size.\nTry again: ";
        cin >> length;
    }

    array->length = length;

    for (int i = 0; i < array->length; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array->A[i];
    }
}

void Display(const Array &array)
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

void Append(Array *array, int element)
{
    // array->length < array->size
    if (array->length < array->size)
    {
        array->A[array->length++] = element; 
    }
    else
    {
        cout << "Array is full! Cannot append element.\n";
    }

}   