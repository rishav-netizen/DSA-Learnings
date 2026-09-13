// Toeplitz Matrix Template
#include <iostream>

using namespace std;

//? (i, j) are the matrix coordinates hence they start from 1
//? the array we use to store the elements are 0 indexed
//? for Toeplitz Matrix: A[i][j] == A[i-1][j-1] (descending diagonals have identical elements)
//? Total unique elements = 2n - 1 (First row: n elements, First column: n - 1 elements)

class ToeplitzMatrix
{
    private:
        int n;
        int *A;
    
    public:
        ToeplitzMatrix(int n)
        {
            this->n = n;
            A = new int[2 * n - 1]();
        }

        void set(int i, int j, int value)
        {
            // TODO: Implement set logic
            if (i <= j)
            {
                A[j - i] = value;
            }
            else
            {
                A[n + i - j - 1] = value;
            }
            
        }

        int get(int i, int j)
        {
            // TODO: Implement get logic
            if (i <= j)
            {
                return A[j - i];
            }
            return A[n + i - j - 1];
        }

        void display()
        {
            // TODO: Implement display logic
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << "\t";
                    if (i <= j)
                    {
                        cout << A[j - i];
                    }
                    else
                    {
                        cout << A[n + i - j - 1];
                    }
                    cout << " ";
                }
                cout << "\n";
            }
            
        }

        int getDimension()
        {
            return n;
        }

        ~ToeplitzMatrix()
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
    ToeplitzMatrix m(n);

    // TODO: Populate and display Toeplitz matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            m.set(i, j, i * 2 * j - 1);
        }
    }
    m.display();
    
    return 0;
}
