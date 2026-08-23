#include <iostream>
using namespace std;

int main()
{
    char A[] = "madam";
    char B[6];

    int l = 0, k = 0;
    for(; A[l]; l++);
    l = l - 1;
    for (; l >= 0; k++, l--)
    {
        B[k] = A[l];
    }
    B[k] = '\0';

    int i, j;
    bool pal = true;
    for(i = 0, j = 0; A[i] && B[i]; i++,j++)
    {
        // to make case insensitive
        A[i] = tolower(A[i]);
        B[j] = tolower(B[j]);
        if (A[i] != B[j])
        {
            pal = false;
            break;
        }
    }
    if(pal)
        cout << "Palindrome\n";
    else
        cout << "Not palindrome\n";
    return 0;
}