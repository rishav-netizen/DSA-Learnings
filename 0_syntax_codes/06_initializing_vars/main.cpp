#include <iostream>

using namespace std;

int main()
{
    double price = 2.55;
    float interestRate = 4.5f; // or F
    long fileSize = 23455L;
    char letter = 'a';
    bool isValid = false;
    
    // we can use the auto keyword and it makes compiler identify type itself
    // auto price = 2.55;
    // auto interestRate = 4.5F;
    // auto fileSize = 23455L;
    // auto letter = 'a';
    // auto isValid = false;

    int number = 1.5; //? type error, but still compiles
    cout << number << endl; //? prints out 1
    
    // brace initialization (wont let compilation to happen incase of conflicting types)
    int num {1}; 
    cout << num << endl; // prints 1
    int num2 {}; //sets to 0 by default
    cout << num2 << endl; // prints 0
    
    return 0;
}