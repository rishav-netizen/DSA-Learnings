#include <iostream>

using namespace std;

int main()
{
    string phrase = "Hello World";

    int len = phrase.length();

    char c1 = phrase[0];
    char c2 = phrase[1];
    char c3 = phrase[2];
    char c4 = phrase[3];
    char c5 = phrase[4];

    cout << "Phrase: " << phrase << "\n" << len << endl;

    //modify
    phrase[0] = 'G';
    cout << phrase << endl;
    
    cout << phrase.find("World") << endl;

    string phraseSub = phrase.substr(6, 3);
    cout << phraseSub << endl; // .substr(start index, len)

    return 0;
}