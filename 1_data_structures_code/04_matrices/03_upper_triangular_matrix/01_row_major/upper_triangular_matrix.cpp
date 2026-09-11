// Row Major Upper Triangular Matrix Implementation
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
            //? aij = (sum_till(n) - sum_till(n-i+1)) + (j - i)
            //? Equivalently: [((i - 1) * n - (i - 2) * (i - 1) / 2) + (j - i)]
            if (i <= j)
            {
                A[(n*(n+1)/2 - (n-i+1)*(n-i+2)/2) + (j-i)] = value;
            }
        }

        int get(int i, int j)
        {
            if (i <= j)
            {
                return A[(n*(n+1)/2 - (n-i+1)*(n-i+2)/2) + (j-i)];
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
                        cout << A[(n*(n+1)/2 - (n-i+1)*(n-i+2)/2) + (j-i)];
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

    cout << "Row Major Upper Triangular Matrix: \n";
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
