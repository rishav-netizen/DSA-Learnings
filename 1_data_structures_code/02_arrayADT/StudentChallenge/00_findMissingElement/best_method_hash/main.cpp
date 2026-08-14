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
            A = new int[size](); //adding () initializes all elements with zero
            length = 0; 
        }
        Array(int sz)
        {
            size = sz;
            A = new int[size]();
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
        int Min();
        int Max();
        void missingElement();
};

int Array::Min()
{
    if (length == 0)
    {
        return -1;
    }
    int min = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] < min)
        {
            min = A[i];
        }
    }
    return min;
}

int Array::Max()
{
    if (length == 0)
    {
        return -1;
    }
    int max = A[0];
    for (int i = 1; i < length; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

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

//! this is just O(n) 
void Array::missingElement()
{
    int max = Max();
    int min = Min();
    Array Hash(max - min + 1); // to handle negatives and also saves space
    Hash.length = max - min + 1;
    for (int i = 0; i < length; i++)
    {
        Hash.A[A[i] - min]++; //here too we shift by the min
    }
    for (int i = min; i <= max; i++)
    {
        int found = Hash.A[i - min]; // here also
        if (!found)
        {
            cout << "Found missing element: " << i << endl;
        }
    }
}

int main(int argc, const char * argv[])
{

    Array A;
    A.Input();
    A.Display();
    A.missingElement(); // using hash table method
    return 0;
}