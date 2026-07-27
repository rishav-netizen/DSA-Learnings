#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <ctime> // for seeding srand()
#include <cctype> // for toupper()
using namespace std;

int main()


{   
    cout << "Think of a secret number in your head!\n";

    int maxValue, minValue, guess=0, tries=0;

    cout << "Enter lower limit: ";
    cin >> minValue;
    cout << "Enter upper limit: ";
    cin >> maxValue;


    char mode = ' ';

    while ((mode != 'R') && (mode != 'E'))
    {
        cout << "What type of guesser you want, efficient(E) or random(R)?: ";
        cin >> mode;
        mode = toupper(mode);
    }
    

    //computer's guess
    char hint = ' ';
    
    srand(time(0));
    while (hint != 'C')
    {
        if (mode == 'R')
        {
            guess = (rand() % (maxValue - minValue + 1)) + minValue;
        }
        else
        {
            guess = (maxValue + minValue) / 2;
        }

        tries++;
        cout << "Computer's Guess: " << guess << "\nIs the computer's guess higher(H), lower(L) or correct(C)?: ";
        cin >> hint;
        hint = toupper(hint);
        switch (hint)
        {
        case 'H':
            maxValue = guess - 1;
            break;
        case 'L':
            minValue = guess + 1;
            break;
        case 'C':
            cout << "\nYay the computer guessed it!\n";
            break;
        default:
            cout << "----Invalid! Try again!----\n";
            break;
        }
    }
    cout << "Tries taken: " << tries << endl;
    return 0;
}