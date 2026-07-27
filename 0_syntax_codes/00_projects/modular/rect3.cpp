#include <iostream>

using namespace std;

// object oriented way of thinking
class Rectangle
{
    private:
        double length, breadth;

    public:
        //default constructor
        Rectangle()
        {
            length = 0;
            breadth = 0;
        }

        // constructor
        Rectangle(double length, double b)
        {
            this->length = length; // this-> points to the current/self object
            breadth = b;
        }

        // area method
        double area()
        {
            return length * breadth;
        }

        // perimeter method
        double peri()
        {
            return 2*(length + breadth);
        }

        // accessor functions
        double getLength()
        {
            return length;
        }

        double getBreadth()
        {
            return breadth;
        }

        // mutator functions
        void setLength(double l)
        {
            length = l;
        }

        void setBreadth(double b)
        {
            breadth = b;
        }

        // destructor
        ~Rectangle()
        {
            cout << "Destructor\n";
        }

};

int main()
{
    double length, breadth;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    // initialisation
    Rectangle rectangle(length, breadth);
    double rect_area, rect_perimeter;
    rect_area = rectangle.area();
    rect_perimeter = rectangle.peri();

    cout << "Area: " << rect_area << endl;
    cout << "Perimeter: " << rect_perimeter << endl;
    return 0;
}

