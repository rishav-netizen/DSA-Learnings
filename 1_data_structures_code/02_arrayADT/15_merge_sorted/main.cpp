#include <iostream>
#include <cctype>

using namespace std;

void Display(int *arr, int length);
void Input(int *arr, int length);
bool isSorted(int *arr, int length);
void merge(int *arr_a, int size_a, int *arr_b, int size_b, int *arr_c);

int main()
{
    int *A, *B;
    int size_a, size_b;
    cout << "Enter the size of array A: ";
    cin >> size_a;
    while (size_a < 1)
    {
        cout << "Try again: ";
        cin >> size_a;
    }
    A = new int[size_a];
    Input(A, size_a);


    cout << "Enter the size of array B: ";
    cin >> size_b;
    while (size_b < 1)
    {
        cout << "Try again: ";
        cin >> size_b;
    }
    B = new int[size_b];
    Input(B, size_b);

    cout << "\nEntered arrays are: "; 
    Display(A, size_a);
    Display(B, size_b);

    bool sorted_a = isSorted(A, size_a);
    bool sorted_b = isSorted(B, size_b);
    int *C;
    C = new int[size_a + size_b];
    if (not (sorted_a and sorted_b)) 
    {
        cout << "One or both arrays are not sorted!\n";
        delete[] C;
        return 1;
    }
    else 
    {
        merge(A, size_a, B, size_b, C);
    }
    Display(C, size_a + size_b);
    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}

void Display(int *arr, int length)
{
    cout << "Elements of the array are: {";
    for (int i = 0; i < length; i++)
    {   
        cout << arr[i];
        if (i < length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void Input(int *arr, int length)
{   
    cout << "Sorted array.\n";
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }   
}

bool isSorted(int *arr, int length)
{
    bool ascendingSorted = true, descendingSorted = true; // flags
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1]) // false condition
        {
            ascendingSorted = false;
        }
        if (arr[i] < arr[i + 1])
        {
            descendingSorted = false;
        }
        
    }
    return ascendingSorted or descendingSorted;
}

void merge(int *arr_a, int size_a, int *arr_b, int size_b, int *arr_c)
{
    int length = size_a + size_b;
    int i = 0, j = 0, k = 0;
    while (i < size_a and j < size_b)
    {
        if (arr_a[i] < arr_b[j])
        {
            arr_c[k] = arr_a[i];
            k++;
            i++;
        }
        else
        {
            arr_c[k] = arr_b[j];
            k++;
            j++;
        }
    }
    
    for (; i < size_a; i++)
    {
        arr_c[k] = arr_a[i];
        k++;
    }
    for (; j < size_b; j++)
    {
        arr_c[k] = arr_b[j];
        k++;
    }
}