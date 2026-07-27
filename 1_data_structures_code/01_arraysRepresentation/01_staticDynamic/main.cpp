#include <iostream>

using namespace std;

int main()
{
    // Static
    int A[5] = {1, 2, 3, 4, 5}; 
    //? memory is created inside stack, size is decided at compile time
    //? but memory is allocated at run  time

    // Dynamic
    //? memory is created under heap and its size and time both are decided at the run time
    //? for accessing anything from the heap we must use a pointer
    int* p; //! for any lang, memory for variable declaration goes inside stack
    p = new int[6]; // new operator gets us memory from the heap, hence we get 6*4 bytes in heap
    //*IN C: int *p = (int *)malloc(6 * sizeof(int));
    // after use of allocated memory make sure to delete it
    p[0] = 4;
    p[1] = 65;
    p[2] = 55;
    p[3] = 9;
    p[4] = 46;

    cout << "Stack array: A = {";
    for (int i = 0; i < 5; i++)
    {
        cout << A[i];
        if (i < 4) cout << ", ";
    }
    cout << "}\n";

    cout << "Heap array: P = {";
    for (int i = 0; i < 6; i++)
    {   

        cout << i[p];
        if (i < 5) cout << ", ";
    }
    cout << "}\n";
    

    delete []p;
    // * IN C: free(p);

    return 0;
}