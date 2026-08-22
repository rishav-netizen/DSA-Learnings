#include <iostream>

using namespace std;

bool isVowel(char c);
char tolower(char c);
bool isConsonant(char c);
int wordCount(char *c);

int main(){
    char c[] = "How   are you?";
    int v_count = 0, c_count = 0;
    for (int i = 0; c[i]; i++)
    {
        if (isVowel(c[i]))
        {
            v_count++;
        }
        else if (isConsonant(c[i]))
        {
            c_count++;
        }

    }
    cout << "Vowel count: " << v_count << "\nConsonant count: " << c_count << "\nWord Count: " << wordCount(c) << endl;

    return 0;
}

bool isVowel(char c)
{
    c = tolower(c);
    for(char v : "aeiou")
    {
        if (c == v)
        {
            return true;
        }
    }
    return false;
    
}

char tolower(char c)
{
    if ('A' <= c and c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

bool isConsonant(char c)
{
    c = tolower(c);
    if ('a' <= c and c <= 'z')
    {
        if (!isVowel(c))
        {
            return true;
        }
    }
    return false;
}

int wordCount(char *c)
{
    int count = 0;
    for (int i = 1; c[i]; i++)
    {
        if (c[i] == ' ' and c[i - 1] != ' ')
        {
            count++;
        }
    }
    return count + 1;
}