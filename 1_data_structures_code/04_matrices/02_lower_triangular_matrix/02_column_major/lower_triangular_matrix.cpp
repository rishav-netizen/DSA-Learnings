// Column Major Lower Triangular Matrix Implementation Placeholder
#include <iostream>

using namespace std;

//? (i, j) are the matrix coordinates hence they start from 1
//? the array we use to store the elements are 0 indexed
//? for Lower Triangular: i >= j

class LowerTriangularMatrix
{
    private:
        int n;
        int *A;
    
    public:
        LowerTriangularMatrix(int n)
        {
            this->n = n;
            A = new int[n*(n+1)/2]();
        }

        void set(int i, int j, int value)
        {
            //! if we use this formula, which can be easily noticed
            //? aij = (sum_till(n) - sum_till(n-j+1)) + i - j 
            if (i >= j)
            {
                A[(n*(n+1)/2 - (n-j+1)*(n-j+2)/2) + (i-j)] = value;
            }
        }

        int get(int i, int j)
        {
            if (i >= j)
            {
                return A[(n*(n+1)/2 - (n-j+1)*(n-j+2)/2) + (i-j)];
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
                    if (i >= j)
                    {
                        cout << A[(n*(n+1)/2 - (n-j+1)*(n-j+2)/2) + (i-j)];
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

        ~LowerTriangularMatrix()
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
    LowerTriangularMatrix m(n);

    cout << "Column Major Lower Triangular Matrix: \n";
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


