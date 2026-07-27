#include <iostream>

using namespace std;

class Book
{
    public:
        string title;
        string author;
        int pages;
        
        //default contructor
        Book()
        {
            title = "NUL";
            author = "NUL";
            pages = 0;
        }

        //constructor function
        Book(string aTitle, string aAuthor, int aPages)
        {
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }

        // method
        void bookName()
        {
            cout << title << endl;
        }
};

int main()
{
    // creating an instance of a class
    Book book1; 
    Book book2("Harry Potter", "J K Rowling", 500);

    book2.bookName();

    return 0;
}