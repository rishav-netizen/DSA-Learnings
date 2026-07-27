#include <iostream>

using namespace std;

// All memory is used in the stack
int main(){
    int A[3][4] = {
        {2, 4, 6, 5},
        {1, 5, 9, 0},
        {7, 8, 3, 1}
    };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << endl;
        }
    }
    
    return 0;
}