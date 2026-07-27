#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    long elapsedSeconds = time(0); //since Jan 1 1970
    srand(elapsedSeconds);
    int upperLimit = 10;
    int number = rand() % upperLimit; //? assumes lower limit as 0

    //! for both upper and lower limits
    //! [rand() % (upper - lower + 1)] + lower
    // cout << elapsedSeconds << endl;
    cout << number << endl;
    return 0;
}