// Diagonal Matrix Implementation Placeholder
#include <iostream>

using namespace std;

class Matrix
{
    private: 
        int *A;
        int dimension;
    
    public: 
        Matrix(int dimension)
        {
            this->dimension = dimension;
            this->A = new int[dimension]();
        }

        ~Matrix()
        {
            delete[] A;
            A = nullptr;
        }
        
        void set(int i, int j, int x)
        {
            if (i == j)
            {
                A[i - 1] = x;
            }
        }
        int get(int i, int j)
        {
            if (i == j)
            {
                return A[i-1];
            }
            return 0;
        }
        void display()
        {
            for(int i = 0; i < dimension; i++)
            {
                for(int j = 0; j < dimension; j++)
                {
                    cout << "\t";
                    if (i == j) cout << A[i];
                    else cout << "0";
                    cout << " ";
                }
                cout << "\n";
            }
        }
};

int main(){

    int n = 6; // n * n matrix
    Matrix Mat(n);  // 1 indexed
    for (int i = 1; i <= n; i++)
    {
        Mat.set(i, i, 3*i + 1);
    }
    Mat.display();
    cout << "Element at (1, 3): " << Mat.get(1, 3) << "\nElement at (3, 3): " << Mat.get(3,3) << endl;
    return 0;
}
