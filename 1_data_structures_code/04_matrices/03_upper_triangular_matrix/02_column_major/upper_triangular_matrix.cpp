// Column Major Upper Triangular Matrix Implementation
#include <iostream>

using namespace std;

//? (i, j) are the matrix coordinates hence they start from 1
//? the array we use to store the elements are 0 indexed
//? for Upper Triangular: i <= j

class UpperTriangularMatrix
{
    private:
        int n;
        int *A;
    
    public:
        UpperTriangularMatrix(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2]();
        }

        void set(int i, int j, int value)
        {
            //! Formula for 1-based matrix indexing:
            //? Sum of first (j - 1) columns: j * (j - 1) / 2
            //? Offset within column j: i - 1
            if (i <= j)
            {
                A[(j*(j-1)/2) + i - 1] = value;
            }
        }

        int get(int i, int j)
        {
            if (i <= j)
            {
                return A[(j*(j-1)/2) + i - 1];
            }
            else
            {
                return 0;
            }
        }

        void display()
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << '\t';
                    if (i <= j)
                    {
                        cout << A[(j*(j-1)/2) + i - 1];
                    }
                    else
                    {
                        cout << '0';
                    }
                    cout << ' ';
                }
                cout << '\n';
            }
        }

        int getDimension()
        {
            return n;
        }

        ~UpperTriangularMatrix()
        {
            delete[] A;
            A = nullptr;
        }
};

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    UpperTriangularMatrix m(n);

    cout << "Column Major Upper Triangular Matrix: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            m.set(i, j, i * j + 1);
        }
    }
    
    m.display();
    return 0;
}
