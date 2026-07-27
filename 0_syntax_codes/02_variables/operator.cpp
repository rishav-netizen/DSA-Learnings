#include <iostream> 
using namespace std;

int main()
{
    int x1 = 5;
    int x2 = 5;

    int y1 = x1++; //? first assign then increment
    cout << "POSTFIX x: " << x1 << "| y: " << y1 << endl;

    int y2 = ++x2; //? first increment then assign
    cout << "PREFIX x: " << x2 << "| y: " << y2 << endl;
    return 0;
}