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
Array UnionOf(Array A, Array B);

int main(){
    cout << "Make sure to enter sorted data: \n";
    Array A = Input("A");
    Array B = Input("B");

    cout << "Entered arrays are: " << endl;
    Display(A);
    Display(B);

    cout << "The union of the arrays is: \n";
    Array C = UnionOf(A, B);
    Display(C);

    delete[] A.A;
    delete[] B.A;
    delete[] C.A;
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

Array UnionOf(Array A, Array B)
{
    Array C;
    int total_len = A.length + B.length;
    C.size = A.size + B.size;
    C.length = 0;
    C.A = new int[C.size];
    int k = 0, i = 0, j = 0;

    // 2 3 4 5 
    // 1 5 6 8 9
    while (i < A.length and j < B.length)
    {     
        if (A.A[i] < B.A[j])
        {
            C.A[k++] = A.A[i++];
        }
        else if (A.A[i] > B.A[j])
        {
            C.A[k++] = B.A[j++];
        }
        else // when both are equal
        {
            C.A[k++] = B.A[j];
            i++;
            j++;
        }
    }

    // copies remaining elements
    for(; i < A.length; i++)
    {
        C.A[k++] = A.A[i];
    }

    for(; j < B.length; j++)
    {
        C.A[k++] = B.A[j];
    }
    
    C.length = k;
    return C;
}