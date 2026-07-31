#include <iostream>

using namespace std;

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(Array arr);
float Avg(Array arr);

int main()
{
    Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Display(arr);
    cout << "Average: " << Avg(arr) << endl;
    return 0;
}

float Avg(Array arr)
{
    int total = 0;
    for (int i = 0, l = arr.length; i < l; i++)
    {
        total += arr.A[i];
    }
    return (float)total/arr.length;
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
