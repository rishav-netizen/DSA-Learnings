#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    int maxValue, minValue;

    cout << "Enter numbers between which you wanna guess.\n";
    cout << "Enter lower limit: ";
    cin >> minValue;
    cout << "Enter upper limit: ";
    cin >> maxValue;

    int random_num = (rand() % (maxValue - minValue + 1)) + minValue;

    cout << "\nThe computer has chosen a random number, try guessing!\n";
    int guess;
    cout << "Enter your guess: ";
    cin >> guess;
    
    int tries = 0;
    while (guess != random_num)
    {
        tries++;
        if (guess > random_num)
        {
            cout << "Try lower!\n";
        }
        else if (guess < random_num)
        {
            cout << "Try higher!\n";
        }
        cout << "Enter your guess: ";
        cin >> guess;

    }
    if (guess == random_num)
    {
        tries++;
        cout << "\nYAY! " << random_num << " was the correct guess!\n";
        cout << "Tries taken: " << tries << endl;
    }
    
    return 0;
}