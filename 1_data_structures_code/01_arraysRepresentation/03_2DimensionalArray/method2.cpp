#include <iostream>

using namespace std;
// half stack, half heap memory allocation
int main(){
    //in stack, we initialize a pointer array
    int* A[3]; 

    // each element of pointer array points to memory allocated for int array in heap
    A[0] = new int[4];
    A[1] = new int[4];
    A[2] = new int[4];

    // give value
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[0][3] = 4;

    A[1][0] = 1;
    A[1][1] = 2;
    A[1][2] = 3;
    A[1][3] = 4;
    
    A[2][0] = 1;
    A[2][1] = 2;
    A[2][2] = 3;
    A[2][3] = 4;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << endl;
        }
    }
    
    return 0;
}