#include <iostream>


using namespace std;

// object oriented way of thinking
//? by making template we can use any type, and basically this is how STL headers are coded
template <typename T>
struct Rect
{
    T length, breadth;

    T area()
    {
        return length * breadth;
    }

    T peri()
    {
        return 2*(length + breadth);
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
    Rect<double> rectangle{length, breadth};
    
    double rect_area, rect_perimeter;
    rect_area = rectangle.area();
    rect_perimeter = rectangle.peri();

    cout << "Area: " << rect_area << endl;
    cout << "Perimeter: " << rect_perimeter << endl;
    return 0;
}

