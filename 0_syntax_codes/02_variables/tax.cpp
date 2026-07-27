#include <iostream>
using namespace std;

int main()
{
    int sales = 95000;

    double stateTaxRate = 0.04;
    double stateTax = stateTaxRate * sales;

    double countyTaxRate = 0.02;
    double countyTax = countyTaxRate * sales;

    double totalTax = stateTax + countyTax;

    cout << "Sales: $" << sales << endl 
         << "State tax: $" << stateTax << endl
         << "County tax: $" << countyTax << endl
         << "Total tax: $" << totalTax << endl;
         
    return 0;
}