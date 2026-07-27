#include <iostream>

using namespace std;

class Arithmetic
{
    private:
        int a;
        int b;

    public:

        Arithmetic(int a, int b)
        {
            this->a = a;
            this->b = b;
        }

        int add()
        {
            return a + b;
        }

        int subtract()
        {
            return a - b; 
        }

};


int main()
{
    Arithmetic obj(4, 2);
    cout << "Add: " << obj.add() << endl;
    cout << "Subtract: " << obj.subtract() << endl;
    return 0;
}