#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int Get(Array arr, int index);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    cout << Get(arr, 3) << endl;
    return 0;
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {   
        return arr.A[index];
    }   
    return -1;
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
