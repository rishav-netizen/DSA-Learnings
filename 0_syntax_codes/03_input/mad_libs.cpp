#include <iostream>

using namespace std;

int main()
{
    string color, pluralNoun, celeb;
    cout << "Enter a color: ";
    getline(cin, color);
    cout << "Enter a plural noun: ";
    getline(cin, pluralNoun);
    cout << "Enter a celebrity: ";
    getline(cin, celeb);

    cout << "Roses are " << color << ".\n";
    cout << pluralNoun << " are blue.\n";
    cout << "I love " << celeb << ".\n";

    return 0;
}