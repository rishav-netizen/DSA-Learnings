#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
int Max(Array arr);
int Min(Array arr);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    cout << "Max: " << Max(arr) << endl;
    cout << "Min: " << Min(arr) << endl;
    return 0;
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 1, l = arr.length; i < l; i++)
    {
        max = (arr.A[i] > max) ? arr.A[i] : max;
    }
    return max;
}   

int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 1, l = arr.length; i < l; i++)
    {
        min = (arr.A[i] < min) ? arr.A[i] : min;
    }
    return min;
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
