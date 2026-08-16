#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    double price;

public:
    // Parameterized Constructor
    Book(string t, double p) {
        title = t;
        price = p;
        cout << "Constructor called for: " << title << " ($" << price << ")" << endl;
    }

    // Destructor
    ~Book() {
        cout << "Destructor called for: " << title << endl;
    }
};

int main() {
    cout << "--- Creating Objects ---" << endl;
    Book b1("C++ Primer", 450.0);
    Book b2("Data Structures", 550.0);

    cout << "\n--- Exiting Scope ---" << endl;
    // Objects are destroyed in reverse order of creation (LIFO)
    return 0;
}
