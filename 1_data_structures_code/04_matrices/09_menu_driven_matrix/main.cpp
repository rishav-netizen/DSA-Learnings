#include <iostream>

using namespace std;

class Matrix
{
    protected:
        int n;
        int *A;
    
    public: 
        //? the member initializer list initializes values in order of their initialization in the data member list
        Matrix(int length = 0) : n(length), A(nullptr) {}
        // Matrix(int n = 0) : n(n), A(nullptr) {}

        virtual ~Matrix()
        {
            delete[] A;
            A = nullptr;
        }

        virtual void set(int i, int j, int x) = 0;
        virtual int get(int i, int j) const = 0;
        virtual void display() const = 0;

        int getDimension() const 
        {
            return n;
        }
};

class DiagonalMatrix : public Matrix
{
    public: 
        DiagonalMatrix(int n) : Matrix(n)
        {
            A = new int[n]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i == j)
                {
                    A[i - 1] = x;
                }
            }
        }
        
        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i == j)
                {
                    return A[i - 1];
                }
            }
            return 0;
        }

        void display() const override
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << "\t";
                    if (i == j) cout << A[i - 1];
                    else cout << "0";
                    cout << " ";
                }
                cout << "\n";
            }
        }
};

class LowerTriangularMatrix : public Matrix
{
    public: 
        LowerTriangularMatrix(int n) : Matrix(n)
        {
            A = new int[n * (n + 1) / 2]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i >= j)
                {
                    A[(i * (i - 1) / 2) + j - 1] = x;
                }
            }
        } 

        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i >= j)
                {
                    return A[(i * (i - 1) / 2) + j - 1];
                }
            }
            return 0;
        }

        void display() const override
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << '\t';
                    if (i >= j)
                    {
                        cout << A[(i * (i - 1) / 2) + j - 1];
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
};

class UpperTriangularMatrix : public Matrix
{   
    public:
        UpperTriangularMatrix(int n) : Matrix(n)
        {
            A = new int[n * (n + 1) / 2]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i <= j)
                {
                    A[(j * (j - 1) / 2) + i - 1] = x;
                }
            }
        }

        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i <= j)
                {
                    return A[(j * (j - 1) / 2) + i - 1];
                }
            }
            return 0;
        }

        void display() const override
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << '\t';
                    if (i <= j)
                    {
                        cout << A[(j * (j - 1) / 2) + i - 1];
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
};

class SymmetricMatrix : public Matrix
{
    public:
        SymmetricMatrix(int n) : Matrix(n)
        {
            A = new int[n * (n + 1) / 2]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i >= j) // lower triangle
                {
                    A[(i * (i - 1) / 2) + j - 1] = x;
                }
                else
                {
                    A[(j * (j - 1) / 2) + i - 1] = x;
                }
            }
        }

        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i >= j)
                {
                    return A[(i * (i - 1) / 2) + j - 1];
                }
                else
                {
                    return A[(j * (j - 1) / 2) + i - 1];
                }
            }
            return 0;
        }

        void display() const override
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << '\t';
                    if (i >= j)
                    {
                        cout << A[(i * (i - 1) / 2) + j - 1];
                    }
                    else
                    {
                        cout << A[(j * (j - 1) / 2) + i - 1];
                    }
                    cout << ' ';
                }
                cout << '\n';
            }
        }
};

class TridiagonalMatrix : public Matrix
{
    public:
        TridiagonalMatrix(int n) : Matrix(n)
        {
            A = new int[3 * n - 2]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i - j == 1)
                {
                    A[i - 2] = x;
                }
                else if (i - j == 0)
                {
                    A[(n - 1) + (i - 1)] = x;
                }
                else if (i - j == -1)
                {
                    A[(2 * n - 1) + (i - 1)] = x;
                }
            }
        }

        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
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
            }
            return 0;
        }

        void display() const override
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
};

class ToeplitzMatrix : public Matrix
{
    public:
        ToeplitzMatrix(int n) : Matrix(n)
        {
            A = new int[2 * n - 1]();
        }

        void set(int i, int j, int x) override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i <= j)
                {
                    A[j - i] = x;
                }
                else
                {
                    A[n + i - j - 1] = x;
                }
            }
        }

        int get(int i, int j) const override
        {
            if (i >= 1 && i <= n && j >= 1 && j <= n)
            {
                if (i <= j)
                {
                    return A[j - i];
                }
                else
                {
                    return A[n + i - j - 1];
                }
            }
            return 0;
        }

        void display() const override
        {
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
};

int main(){
    int type, n;

    cout << "=== SELECT MATRIX TYPE ===\n";
    cout << "1. Diagonal Matrix\n";
    cout << "2. Lower Triangular Matrix\n";
    cout << "3. Upper Triangular Matrix\n";
    cout << "4. Symmetric Matrix\n";
    cout << "5. Tridiagonal Matrix\n";
    cout << "6. Toeplitz Matrix\n";
    cout << "Enter matrix type (1-6): ";
    cin >> type;
    
    while (type > 6 or type < 1)
    {
        cout << "Invalid type, try again: ";
        cin >> type;
    }

    cout << "Enter matrix dimension (n): ";
    cin >> n;

    Matrix *m = nullptr;

    switch (type)
    {
        case 1:
            m = new DiagonalMatrix(n);
            break;
        case 2:
            m = new LowerTriangularMatrix(n);
            break;
        case 3:
            m = new UpperTriangularMatrix(n);
            break;
        case 4:
            m = new SymmetricMatrix(n);
            break;
        case 5:
            m = new TridiagonalMatrix(n);
            break;
        case 6:
            m = new ToeplitzMatrix(n);
            break;
        default:
            cout << "Enter valid matrix choice!\n";
            return 1;
    }
    
    int choice, i, j, x;

    do
    {
        cout << "\n\n--- OPERATIONS MENU ---\n";
        cout << "1. Set Element\n";
        cout << "2. Get Element\n";
        cout << "3. Display Matrix\n";
        cout << "4. Exit\n";
        cout << "Enter operation (1-4): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter (row, col, value): ";
                cin >> i >> j >> x;
                m->set(i, j, x);
                break;
                
            case 2:            
                cout << "Enter (row, col): ";
                cin >> i >> j;
                cout << "Value at (" << i << ", " << j << "): " << m->get(i, j);
                break;

            case 3:
                cout << "Matrix: \n";
                m->display();
                break;

            case 4: 
                cout << "Exiting";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);
    
    delete m;
    m = nullptr;

    return 0;
}