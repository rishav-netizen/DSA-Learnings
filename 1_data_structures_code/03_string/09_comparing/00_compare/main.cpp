#include <iostream>
using namespace std;

int main()
{
    char A[] = "painter";
    char B[] = "Painting";

    int i, j;
    for(i = 0, j = 0; A[i] && B[i]; i++,j++)
    {
        // to make case insensitive
        A[i] = tolower(A[i]);
        B[j] = tolower(B[j]);
        if (A[i] != B[j])
        {
            break;
        }
        
        
    }
    if (A[i] == B[j])
    {
        cout << "Equal\n"; 
    }
    else if (A[i] < B[j])
    {
        cout << "smaller\n";
    }
    else
    {
        cout << "greater\n";
    }
    return 0;
}