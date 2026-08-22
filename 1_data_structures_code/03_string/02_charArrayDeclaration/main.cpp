#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    // =========================================================================
    // 1. Declaration without initialization (Garbage values)
    // =========================================================================
    char X1[5];
    cout << "--- 1. char X1[5] (Uninitialized) ---\n";
    cout << "Allocated 5 bytes in stack. Holds indeterminate (garbage) values.\n\n";

    // =========================================================================
    // 2. Declaration with explicit size and complete initializer list
    // =========================================================================
    char X2[5] = {'A', 'B', 'C', 'D', 'E'};
    cout << "--- 2. char X2[5] = {'A', 'B', 'C', 'D', 'E'} ---\n";
    cout << "Size: " << sizeof(X2) << " bytes\n";
    cout << "Elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << X2[i] << " ";
    }
    cout << "\nASCII values: ";
    for (int i = 0; i < 5; i++)
    {
        cout << (int)X2[i] << " ";
    }
    cout << "\n\n";

    // =========================================================================
    // 3. Declaration without explicit size (Compiler infers size)
    // =========================================================================
    char X3[] = {'A', 'B', 'C', 'D', 'E'};
    cout << "--- 3. char X3[] = {'A', 'B', 'C', 'D', 'E'} ---\n";
    cout << "Size inferred by compiler: " << sizeof(X3) << " bytes\n";
    cout << "Elements: ";
    for (int i = 0; i < 5; i++)
    {
        cout << X3[i] << " ";
    }
    cout << "\n\n";

    // =========================================================================
    // 4. Initialization using ASCII decimal integer values
    // =========================================================================
    char X4[5] = {65, 66, 67, 68, 69};
    cout << "--- 4. char X4[5] = {65, 66, 67, 68, 69} ---\n";
    cout << "Characters stored (auto-mapped from ASCII codes): ";
    for (int i = 0; i < 5; i++)
    {
        cout << X4[i] << " ";
    }
    cout << "\n\n";

    // =========================================================================
    // 5. Partial Initialization (Remaining elements are Zero-Initialized)
    // =========================================================================
    char X5[5] = {'A', 'B'};
    cout << "--- 5. char X5[5] = {'A', 'B'} (Partial Initialization) ---\n";
    cout << "Size: " << sizeof(X5) << " bytes\n";
    for (int i = 0; i < 5; i++)
    {
        printf("Index %d: char = '%c' (ASCII = %d)\n", i, (X5[i] == '\0' ? ' ' : X5[i]), (int)X5[i]);
    }
    cout << "Note: Indices 2, 3, and 4 are automatically filled with 0 ('\\0').\n";

    return 0;
}
