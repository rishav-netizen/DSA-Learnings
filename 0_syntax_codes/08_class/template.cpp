#include <iostream>

using namespace std;

template <class T>
class Arithmetic
{
    private:
        T a;
        T b;

    public:

        Arithmetic(T a, T b)
        {
            this->a = a;
            this->b = b;
        }

        T add()
        {
            return a + b;
        }

        T subtract()
        {
            return a - b; 
        }
};


int main()
{
    Arithmetic<double> int_obj(4.4, 2.4);
    cout << "Add: " << int_obj.add() << endl;
    cout << "Subtract: " << int_obj.subtract() << endl;

    int *p;
    p = new int[5];
    delete []p;
    
    // char stores ASCII values internally.
    // 'B' = 66 and 'A' = 65.
    //
    // So when add() runs:
    // 66 + 65 = 131
    //
    // But a signed char can only store values from -128 to 127.
    // Since 131 exceeds the limit, overflow happens.
    //
    // The value wraps around like this:
    // 131 - 256 = -125
    //
    // That's why:
    // (int)char_obj.add()
    // prints -125 instead of 131.
    Arithmetic<char> char_obj('B', 'A');
    cout << "Add: " << (int)char_obj.add() << endl;
    cout << "Subtract: " << (int)char_obj.subtract() << endl;

    return 0;
}