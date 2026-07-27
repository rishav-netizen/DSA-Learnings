#include <iostream>
using namespace std;

int main()
{
    // the backslash has to be escaped by using escape operator which is again backslash

    cout << "|\\" << endl;
    cout << "| \\" << endl;
    cout << "|  \\" << endl;
    cout << "|   \\" << endl;
    cout << "|____\\" << endl;
    
    cout << "\n\n"; 
    //! same thing using a loop but you can change height
    int n = 10; // height
    for (int i = 0; i < n; i++)
    {
        cout << "|";
        for (int j = 0; j < i; j++)
        {
            if (i == n-1)
            {
                cout << "_";
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << "\\" << endl;
    }
    
    return 0;
}