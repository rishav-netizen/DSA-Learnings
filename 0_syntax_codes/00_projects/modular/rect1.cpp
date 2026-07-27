#include <iostream>

using namespace std;

// no typedef needed for c++

struct Rect
{
    double length, breadth;
};

// passing reference to function not copies hence the '&' (this is faster)
// const makes sure that no modifications are made
double area(const Rect &r);
double peri(const Rect &r);

int main()
{
    double length, breadth;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter breadth: ";
    cin >> breadth;

    // initialisation
    Rect rectangle{length, breadth};
    
    double rect_area, rect_perimeter;
    rect_area = area(rectangle);
    rect_perimeter = peri(rectangle);

    cout << "Area: " << rect_area << endl;
    cout << "Perimeter: " << rect_perimeter << endl;
    return 0;
}

double area(const Rect &r)
{
    return r.length * r.breadth;
}

double peri(const Rect &r)
{
    return 2*(r.length + r.breadth);
}
