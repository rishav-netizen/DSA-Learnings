#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    // 1. Declaration
    char temp; // Allocates 1 Byte (8 bits) in the Stack frame

    // 2. Valid vs Invalid Assignments:
    
    // [VALID]: Enclosed in single quotes with exactly one character
    temp = 'A'; // 'A' has ASCII value 65, which is stored in binary: 01000001
    
    // [INVALID]: Multi-character constant
    // temp = 'AB'; 
    // Error / Warning: multi-character character constant. 'AB' requires 2 bytes, 
    // but char can only hold 1 byte.

    // [INVALID]: Unquoted identifier
    // temp = A;
    // Error: 'A' undeclared identifier. The compiler looks for a variable named A.

    // [INVALID]: Double quotes (String literal)
    // temp = "A";
    // Error: Cannot assign 'const char*' (pointer to string literal with null-terminator "A\0")
    // to a variable of type 'char'.

    // 3. Output in C style
    printf("Printing using printf:\n");
    printf("Character representation (%%c) : %c\n", temp);   // Outputs: A
    printf("Decimal/ASCII representation (%%d) : %d\n", temp); // Outputs: 65

    printf("\n");

    // 4. Output in C++ style
    cout << "Printing using cout:\n";
    cout << "Character representation       : " << temp << "\n";        // Outputs: A
    cout << "Decimal/ASCII representation   : " << (int)temp << "\n";   // Outputs: 65

    // 5. Memory footprint
    cout << "\nSize of char variable 'temp'  : " << sizeof(temp) << " Byte(s)\n";

    return 0;
}
