#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const double pi = 3.141592;
    double r;
    cout << "Enter the radius of circle: ";
    cin >> r;
    double area = pi * pow(r, 2);

    cout << "Area: " << area << endl;
    return 0;
}