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
        int Max();
        void ElementsWithSum(int sum);
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

int Array::Max()
{
    int result = A[0];
    for (int i = 1; i < length; i++)
    {
        result = (result > A[i]) ? result : A[i];
    }
    return result;
    
}

// hash table approach gives O(maxElement) time complexity
void Array::ElementsWithSum(int sum)
{
    bool found = false;
    int maxElement = Max();
    int *H = new int[maxElement + 1]();
    
    for (int i = 0; i < length; i++)
    {
        H[A[i]]++;
    }
    
    for (int i = 0; i < length; i++)
    {
        int complement = sum - A[i];
        if (complement >= 0 and complement <= maxElement and H[complement] != 0)
        {
            // if there is just one number then we cant print it, else we can
            if (A[i] != complement or H[A[i]] > 1) 
            {
                cout << A[i] << " + " << complement << " = " << sum << endl;
                found = true;

                // we decrement count cuz we already used them
                H[A[i]]--;
                H[complement]--;
            }
        }
    }

    if (!found)
    {
        cout << "No elements found with that sum!\n";
    }

    delete[] H;
    H = nullptr;
}

int main()
{
    Array A;
    A.Input();
    A.Display();
    int n;
    cout << "Enter sum: ";
    cin >> n;
    A.ElementsWithSum(n);
    return 0;   
}