#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Element
{
    int i, j, val;
};

bool compare(const Element &a, const Element &b) // returns if a should come before b
{
    if(a.i == b.i) // if equal rows then compare by column
    {
        return a.j < b.j;
    }
    return a.i < b.i;
}

class SparseMatrix
{
    private:
        int n; // dimension
        int num; // number of non zero elements
        Element *A;

    public: 
        SparseMatrix(int n, int num)
        {
            this->n = n;
            this->num = num;
            A = new Element[num];
        }

        // copy constructor for deep copy
        SparseMatrix(const SparseMatrix &other)
        {
            n = other.n;
            num = other.num;

            A = new Element[num];

            for (int i = 0; i < num; i++)
            {
                A[i] = other.A[i];
            }
        }

        int get(int i, int j) const
        {
            if (i < 1 || i > n || j < 1 || j > n)
            {
                return 0;
            }

            int l = 0, h = num - 1, mid;
            while (l <= h)
            {
                mid = (h - l) / 2 + l;
                if (A[mid].i == i and A[mid].j == j) 
                {
                    return A[mid].val;
                }
                else if ((A[mid].i < i) || (A[mid].i == i and A[mid].j < j)) // since we store row major
                {
                    l = mid + 1;
                }
                else 
                {
                    h = mid - 1;
                }
            }

            return 0;
            
        }

        void read()
        {   
            cout << "Enter the non zero elements(row, col, value): ";
            for (int k = 0; k < num; k++)
            {
                cin >> A[k].i >> A[k].j >> A[k].val;
            }
            sort(A, A + num, compare); // sorting row major wise for binary search in get()
        }

        void display() const
        {
            int k = 0; // tracker for non zero elements

            for (int i = 1; i <= n; i++)
            {
                cout << "\t";
                for (int j = 1; j <= n; j++)
                {
                    if (k < num && A[k].i == i && A[k].j == j)
                    {
                        cout << A[k++].val;
                    }
                    else
                    {
                        cout << "0";
                    }
                    cout << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }

        SparseMatrix operator+(const SparseMatrix &other)
        {
            if(this->n != other.n) // dimension check 
            {
                cout << "They must have the same dimension!\n";
                exit(1);
            }

            int total = this->num + other.num; // in worst case when all are different indexed
            SparseMatrix result(n, total);

            int i = 0, j = 0, k = 0;

            // here basically merging two sorted arrays using compare to compare elements cuz they aint integers
            while(i < this->num && j < other.num)
            {
                if(compare(A[i], other.A[j]))
                {
                    result.A[k] = A[i];
                    i++;
                }
                else if (compare(other.A[j], A[i]))
                {
                    result.A[k] = other.A[j];
                    j++;
                }
                else
                {
                    int sum = A[i].val + other.A[j].val;
                    if(sum != 0)
                    {
                        result.A[k].i = A[i].i; 
                        result.A[k].j = A[i].j; 
                        result.A[k].val = sum;
                        k++;
                    }
                    i++;
                    j++;
                    continue; // if the sum is zero then the array counter for non zeroes shouldnt be incremented hence we ignore the below code of THIS loop
                }
                k++;
            }
            
            while (i < this->num)
            {
                result.A[k++] = A[i++];
            }
            while (j < other.num)
            {
                result.A[k++] = other.A[j++];
            }

            result.num = k;

            return result;
        }

        SparseMatrix& operator=(const SparseMatrix &other) //copy assignment operator
        {
            if (this == &other)
            {
                return *this;
            }

            delete[] A;

            n = other.n;
            num = other.num;

            A = new Element[num];

            for (int i = 0; i < num; i++)
            {
                A[i] = other.A[i];
            }

            return *this;
        }


        ~SparseMatrix()
        {
            delete[] A;
            A = nullptr;
        }

};


int main()
{
    cout << "Enter first square sparse matrix dimension: ";
    int n1;
    cin >> n1;

    cout << "Enter number of non zero elements: ";
    int num1;
    cin >> num1;
    SparseMatrix m1(n1, num1);
    m1.read();

    cout << "\nSparse Matrix: \n";
    m1.display();

    cout << "Enter second square sparse matrix dimension: ";
    int n2;
    cin >> n2;

    cout << "Enter number of non zero elements: ";
    int num2;
    cin >> num2;
    SparseMatrix m2(n2, num2);
    m2.read();

    cout << "\nSparse Matrix: \n";
    m2.display();

    // int row, col;
    // cout << "\nEnter (row, col) for element you wanna see: ";
    // cin >> row >> col;
    // cout << "Element at (" << row << ", " << col << "): " << m.get(row, col) << endl;

    SparseMatrix result = m1 + m2; // this is deep copying right?
    cout << "\nThe resultant matrix is as follows: \n";
    result.display();
    return 0;
}