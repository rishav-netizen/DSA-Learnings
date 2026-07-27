#include <iostream>

using namespace std;

int main()
{
    double temp;
    cout << "Enter the temperature: ";
    cin >> temp;
    char unit;
    cout << "Enter the unit(F/C): ";
    cin >> unit;

    if (unit == 'F' || unit == 'f')
    {
        double celc = (temp-32)*(5.0/9.0);
        cout << "Temperature in celcius: " << celc << "C\n";
    }
    else if (unit == 'C' || unit == 'c')
    {
        double fahr = ((9 * temp)/5.0) + 32;
        cout << "Temperature in fahrenheit: " << fahr << "F\n";
    }
    else
    {
        cout << "Invalid Unit!" << endl;
        return 1;
    }

    return 0;
}