// Row Major Lower Triangular Matrix Implementation Placeholder
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
            if (i >= j)
            {
                A[(i*(i-1)/2) + j - 1] = value;
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
                        cout << A[(i*(i-1)/2) + j - 1];
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

    cout << "Row Major Lower Triangular Matrix: \n";
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