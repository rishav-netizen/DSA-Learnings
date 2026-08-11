#include <iostream>

using namespace std;

typedef struct Array
{
    int *A;
    int size;
    int length;
} Array;

void Display(Array arr);
Array Input(string name);
int In(int key, Array A);

int main(){
    Array A = Input("A");
    Display(A);

    int key;
    cout << "Enter element you wanna search: ";
    cin >> key;

    int idx = In(key, A);
    if (idx)
    {
        cout << "Found item at index " << idx << endl;
    }
    else
    {
        cout << "Element not found!\n";
    }
    
    delete[] A.A;
    return 0;
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

Array Input(string name)
{
    Array arr;
    cout << "Enter array " << name << " size: ";
    cin >> arr.size;
    int length;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout << "Enter the number of numbers: ";
    cin >> length;
    while (length < 0 || length > arr.size)
    {
        cout << "Invalid input! Length must be smaller than size!" << endl;
        cout << "Try again: ";
        cin >> length;
    }
    arr.length = length;
    for (int i = 0, l = arr.length; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr.A[i];
    }
    return arr;
}

Array Difference(Array A, Array B)
{
    Array C;
    int total_len = A.length + B.length;
    C.size = A.size + B.size;
    C.length = total_len;
    C.A = new int[C.size];

    int k = 0;
    for (int i = 0; i < A.length; i++)
    {
        if (not In(A.A[i], B) and not In(A.A[i], C))
        {
            C.A[k++] = A.A[i];
        }
    }

    C.length = k;
    return C;
}

int In(int key, Array A)
{
    for (int i = 0; i < A.length; i++)
    {
        if (A.A[i] == key)
        {
            return i;
        }
    }
    return -1;
}