#include <iostream>

using namespace std;

void permMethod1(char A[], int k);
void permMethod2(char A[], int l, int h);

int main()
{
    int n = 0;
    char A[] = "ABC";
    for(; A[n]; n++);

    cout << "Using flag array and state space tree" << endl;
    permMethod1(A, 0); // k = 0 means filling first position of result
    
    cout << "\n\nUsing in place swapping\n";
    permMethod2(A, 0, n - 1);
    return 0;
}

// Method 1: Using Flag/Visited array and Result array
// state space tree
void permMethod1(char A[], int k)
{
    // we must changes these statics for other examples or just use in main or function definition
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

// Method 2: In-place Swapping
void permMethod2(char A[], int l, int h)
{
    if (l == h)
    {
        cout << A << endl;
        return;
    }

    for (int i = 1; i <= h; i++)
    {
        swap(A[i], A[l]);
        permMethod2(A, l + 1, h);
        swap(A[i], A[l]); // backtrack
    }
}