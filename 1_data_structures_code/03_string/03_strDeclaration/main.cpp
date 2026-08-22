#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    // =========================================================================
    // 1. Explicit Size Array with Explicit Null Terminator ('\0')
    // =========================================================================
    char name1[10] = {'J', 'o', 'h', 'n', '\0'};
    cout << "=====================================================\n";
    cout << "1. char name1[10] = {'J', 'o', 'h', 'n', '\\0'};\n";
    cout << "=====================================================\n";
    cout << "Printed as string (cout) : " << name1 << "\n";
    printf("Printed as string (%%s)   : %s\n", name1);
    cout << "Array Size (sizeof)      : " << sizeof(name1) << " bytes\n";
    cout << "String Length (strlen)   : " << strlen(name1) << " characters\n\n";

    cout << "Memory Slot Breakdown:\n";
    for (int i = 0; i < 10; i++)
    {
        if (name1[i] == '\0')
        {
            printf("Index %d: '\\0' (ASCII: %d) <-- String Terminator / Delimiter\n", i, (int)name1[i]);
        }
        else
        {
            printf("Index %d: '%c'  (ASCII: %d)\n", i, name1[i], (int)name1[i]);
        }
    }
    cout << "\n";

    // =========================================================================
    // 2. Unsized Array with Explicit Null Terminator ('\0')
    // =========================================================================
    char name2[] = {'J', 'o', 'h', 'n', '\0'};
    cout << "=====================================================\n";
    cout << "2. char name2[] = {'J', 'o', 'h', 'n', '\\0'};\n";
    cout << "=====================================================\n";
    cout << "Printed as string        : " << name2 << "\n";
    cout << "Inferred Size (sizeof)   : " << sizeof(name2) << " bytes (4 chars + 1 '\\0')\n";
    cout << "String Length (strlen)   : " << strlen(name2) << " characters\n\n";

    // =========================================================================
    // 3. String Literal in Double Quotes (Compiler automatically appends '\0')
    // =========================================================================
    char name3[] = "John";
    cout << "=====================================================\n";
    cout << "3. char name3[] = \"John\";\n";
    cout << "=====================================================\n";
    cout << "Printed as string        : " << name3 << "\n";
    cout << "Inferred Size (sizeof)   : " << sizeof(name3) << " bytes (automatically adds '\\0')\n";
    cout << "String Length (strlen)   : " << strlen(name3) << " characters\n";
    printf("Last character name3[4]  : '\\0' (ASCII: %d)\n\n", (int)name3[4]);

    // =========================================================================
    // 4. Fixed-Size Array Initialized with String Literal
    // =========================================================================
    char name4[10] = "John";
    cout << "=====================================================\n";
    cout << "4. char name4[10] = \"John\";\n";
    cout << "=====================================================\n";
    cout << "Printed as string        : " << name4 << "\n";
    cout << "Array Size (sizeof)      : " << sizeof(name4) << " bytes\n";
    cout << "String Length (strlen)   : " << strlen(name4) << " characters\n\n";

    // =========================================================================
    // 5. Partial Initialization Creating an Implicit String
    // =========================================================================
    char X[5] = {'A', 'B'};
    cout << "=====================================================\n";
    cout << "5. char X[5] = {'A', 'B'}; (Partial Initialization)\n";
    cout << "=====================================================\n";
    cout << "Printed as string (cout) : " << X << "\n";
    cout << "Array Size (sizeof)      : " << sizeof(X) << " bytes\n";
    cout << "String Length (strlen)   : " << strlen(X) << " characters\n";
    cout << "Explanation: Since uninitialized slots are filled with 0 ('\\0'),\n";
    cout << "X[2] is 0, making 'X' terminate cleanly as the string \"AB\".\n\n";

    // =========================================================================
    // 6. Manual Traversal Using the Null Terminator
    // =========================================================================
    cout << "=====================================================\n";
    cout << "6. Manual Traversal Using Sentinel While/For Loop\n";
    cout << "=====================================================\n";
    cout << "Iterating through name3 until '\\0':\n";
    int len = 0;
    for (int i = 0; name3[i] != '\0'; i++)
    {
        cout << "name3[" << i << "] = '" << name3[i] << "'\n";
        len++;
    }
    cout << "Calculated length: " << len << "\n";

    return 0;
}
