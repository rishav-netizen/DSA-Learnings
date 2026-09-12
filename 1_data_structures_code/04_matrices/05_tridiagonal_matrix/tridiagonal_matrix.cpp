// Tridiagonal Matrix Implementation
#include <iostream>

using namespace std;

//? (i, j) are the matrix coordinates hence they start from 1
//? the array we use to store the elements are 0 indexed
//? for Tridiagonal Matrix: non-zero elements exist only when |i - j| <= 1
//? 1. Lower sub-diagonal (i - j == 1): n - 1 elements
//? 2. Main diagonal (i - j == 0): n elements
//? 3. Upper super-diagonal (i - j == -1): n - 1 elements

class TridiagonalMatrix
{
    private:
        int n;
        int *A;
    
    public:
        TridiagonalMatrix(int n)
        {
            this->n = n;
            A = new int[3 * n - 2]();
        }

        void set(int i, int j, int value)
        {
            if (i - j == 1)
            {
                A[i - 2] = value;
            }
            else if (i - j == 0)
            {
                A[(n - 1) + (i - 1)] = value;
            }
            else if (i - j == -1)
            {
                A[(2 * n - 1) + (i - 1)] = value;
            }
        }

        int get(int i, int j)
        {
            if (i - j == 1) // below diagonal
            {
                return A[i - 2];
            }
            else if (i - j == 0) // diagonal
            {
                return A[(n - 1) + (i - 1)];
            }
            else if (i - j == -1) // above diagonal
            {
                return A[(2 * n - 1) + (i - 1)];
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
                    if (i - j == 1)
                    {
                        cout << A[i - 2];
                    }
                    else if (i - j == 0)
                    {
                        cout << A[(n - 1) + (i - 1)];
                    }
                    else if (i - j == -1)
                    {
                        cout << A[(2 * n - 1) + (i - 1)];
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

        ~TridiagonalMatrix()
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
    TridiagonalMatrix m(n);

    cout << "Tridiagonal Matrix: \n";
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
