#include <iostream>

using namespace std;

class Array
{
    private:
        int *A;
        int size;
        int length;
    
    public:
        Array()
        {
            size = 10;
            A = new int[size];
            length = 0; 
        }
        Array(int sz)
        {
            size = sz;
            A = new int[size];
            length = 0; 
        }
        ~Array()
        {
            cout << "Instance of array object destructed!\n";
            delete[] A;
            A = nullptr;
        }
        // Similarly we can add other functions
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        void Input();
        void Duplicates();
        void DuplicatesWithCount();
    };

void Array::Display()
{
    cout << "Elements of the array are: {";
    for (int i = 0; i < length; i++)
    {   
        cout << A[i];
        if (i < length - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}

void Array::Insert(int index, int x)
{
    if ((index >= 0) and (index <= length) and (length < size))
    {
        for (int i = length - 1; i >= index; i--)
        {
            A[i + 1] = A[i];
        }
        A[index] = x;
        length++;
    }
}


int Array::Delete(int index)
{
    int deleted = -1;
    if ((index >= 0) and (index < length))
    {
        deleted = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
    }
    return deleted;
}

void Array::Input()
{
    cout << "Enter the number of numbers: ";
    cin >> length;
    while (length < 0 || length > size)
    {
        cout << "Invalid input! Length must be smaller than size!" << endl;
        cout << "Try again: ";
        cin >> length;
    }
    for (int i = 0, l = length; i < l; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> A[i];
    }

}

void Array::Duplicates()
{
    int lastDuplicate = 0;
    bool found = false;
    for(int i = 1; i < length; i++)
    {
        if (A[i - 1] == A[i])
        {
            if (lastDuplicate != A[i - 1])
            {
                cout << A[i - 1] << endl;
                found = true;
            }
            lastDuplicate = A[i - 1];
        }
    }
    if (!found)
    {
        cout << "not found!\n";
    }
}

// for sorted array using loop
void Array::DuplicatesWithCount() // O(n)
{
    int lastDuplicate = 531451345, j = 0;
    bool found = false;
    for(int i = 0; i < length - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            if (lastDuplicate != A[i])
            {
                cout << A[i];
            }
            found = true;
            lastDuplicate  = A[i];
            j = i + 1;
            while (j < length and A[j] == A[i])
            {
                j++;
            }
            cout << ": " << j - i << " times\n";
            i = j - 1;
        }
        
    }
    if (!found)
    {
        cout << "not found!\n";
    }
}

int main()
{
    Array A;
    A.Input();
    A.Display();
    cout << "\nDuplicates are: \n";
    A.DuplicatesWithCount();
    return 0;
}