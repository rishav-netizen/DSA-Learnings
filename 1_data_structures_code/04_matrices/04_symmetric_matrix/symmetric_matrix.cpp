// Symmetric Matrix Implementation Placeholder

#include <iostream>

using namespace std;

//? (i, j) are the matrix coordinates hence they start from 1
//? the array we use to store the elements are 0 indexed
//? for Symmetric: M(i, j) == M(j , i)
//! here i am storing as if i use lower triangular row major, thats why i use normal formula for i >= j 

class SymmetricMatrix
{
    private:
        int n;
        int *A;
    
    public:
        SymmetricMatrix(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2]();
        }

        void set(int i, int j, int value)
        {
            if (i >= j)
            {
                A[(i*(i-1)/2) + j - 1] = value;
            }
            else
            {
                A[(j*(j-1)/2) + i - 1] = value;
            }
        }

        int get(int i, int j)
        {
            if (i >= j)
            {
                return A[(i*(i-1)/2) + j - 1];
            }
            else
            {
                return A[(j*(j-1)/2) + i - 1];
            }
        }

        void display()
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << '\t';
                    if (i >= j)
                    {
                        cout << A[(i*(i-1)/2) + j - 1];
                    }
                    else
                    {
                        cout << A[(j*(j-1)/2) + i - 1];
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

        ~SymmetricMatrix()
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
    SymmetricMatrix m(n);

    cout << "Symmetric Matrix: \n";
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