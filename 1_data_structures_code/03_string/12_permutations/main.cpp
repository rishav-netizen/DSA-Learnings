#include <iostream>

using namespace std;

void permMethod1(char A[], int k);
void permMethod2(char A[], int l, int h);

int main()
{
    int n = 0;
    char A[] = "ABC";
    for(; A[n]; n++);

    // permMethod1(A, 0); // k = 0 means filling first position of result
    permMethod2(A, 0, n - 1);
    return 0;
}

void permMethod1(char A[], int k)
{
    static char res[10];
    static int flag[10] = {0};

    if (A[k] == '\0')
    {
        res[k] = '\0';
        cout << res << endl;
        return;
    }

    for (int i = 0; A[i]; i++) // trying for each character in the string
    {
        if (flag[i] == 0) // check if it has already been used
        {
            res[k] = A[i]; // not used so use it
            flag[i] = 1; // mark as used
            permMethod1(A, k + 1); // filling next position of result
            flag[i] = 0; // backtracking
        }
    }
}

void permMethod2(char A[], int l, int h)
{
    if (l == h)
    {
        cout << A << endl;
        return;
    }

    for (int i = 0; i <= h; i++)
    {
        swap(A[i], A[l]);
        permMethod2(A, l + 1, h);
        swap(A[i], A[l]);
    }
}