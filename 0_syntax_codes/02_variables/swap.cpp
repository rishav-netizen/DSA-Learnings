#include <iostream>
using namespace std;

int main()
{
    int a = 4, b = 5;
    cout << "BEFORE\na: " << a << "| b: " << b << endl; 
    
    int c = a;
    a = b;
    b = c;

    cout << "AFTER\na: " << a << "| b: " << b << endl; 

}