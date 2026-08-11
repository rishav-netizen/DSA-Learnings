#include <iostream>
#include <cctype>

using namespace std;

void Display(int *arr, int length);
void Input(int *arr, int length);
void Shift(int *arr, int length, int steps, char direction);

int main()
{
    int *A;
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    while (size < 1)
    {
        cout << "Try again: ";
        cin >> size;
    }
    
    A = new int[size];
    Input(A, size);
    Display(A, size);

    Shift(A, size, 3, 'l');
    Display(A, size);

    delete[] A;

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
    for (int i = 0; i < length; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    
}

void Shift(int *arr, int length, int steps, char direction)
{
    direction = toupper(direction);
    steps = steps % length;

    int first, last;
    
    // O(n * steps) here n = length
    switch (direction)
    {
        case 'R':
            for (int i = 0; i < steps; i++)
            {
                last = arr[length - 1];
                for (int i = length - 1; i > 0; i--)
                {
                    arr[i] = arr[i - 1];
                }
                arr[0] = last;
            }
        break;
        
        case 'L':
            for (int i = 0; i < steps; i++)
            {
                first = arr[0];
                for (int i = 0; i < length - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                arr[length - 1] = first;
            }
        break;
    
        default:
            cout << "Invalid Input!" << endl;
    }
}