// Sparse Matrix Implementation Placeholder
#include <iostream>
#include <algorithm>

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
        int n;
        int num;
        Element *A;

    public: 
        SparseMatrix(int n, int num)
        {
            this->n = n;
            this->num = num;
            A = new Element[num];
        }

        int get(int i, int j)
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

        void display()
        {
            int k = 0;
            
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
            
        }

        ~SparseMatrix()
        {
            delete[] A;
            A = nullptr;
        }

};


int main()
{
    cout << "Enter square sparse matrix dimension: ";
    int n;
    cin >> n;

    cout << "Enter number of non zero elements: ";
    int num;
    cin >> num;
    SparseMatrix m(n, num);
    m.read();

    cout << "\nSparse Matrix: \n";
    m.display();

    int row, col;
    cout << "\nEnter (row, col) for element you wanna see: ";
    cin >> row >> col;
    cout << "Element at (" << row << ", " << col << "): " << m.get(row, col) << endl;
    return 0;
}