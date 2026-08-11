#include <iostream>

using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(Array arr);
void Input(Array *arr);
int Delete(Array *arr, int index);

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

    int index;
    cout << "Enter index of value you wanna delete: ";
    cin >> index;

    int deleted;
    while ((deleted = Delete(&arr, index)) == -1)
    {
        cout << "Try again: ";
        cin >> index;
    }

    cout << "\nDeleted value is: " << deleted << endl;
    
    Display(arr);

    delete[] arr.A; // freeing memory after use
    return 0;
}

int Delete(Array *arr, int index)
{
    // didnt know i could write 'and' 'or' like we can in python 

    // ? this check isnt necessary cuz its array ADT 
    // if ((index >= arr->length) and (index < arr->size))
    // {
    //     cout << "Index is already empty, nothing to delete." << endl;
    //     return;
    // }

    if ((index < 0) or (index >= arr->length))
    {
        cout << "Invalid index!" << endl;
        return -1;
    }

    int deleted = arr->A[index];
    for (int i = index, l = arr->length; i < l - 1; i++)
    {
        arr->A[i] = arr->A[i+1];
    }

    arr->length--;
    return deleted;
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

void Input(Array *arr)
{
    for (int i = 0, l = arr -> length; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr -> A[i];
    }   
}
