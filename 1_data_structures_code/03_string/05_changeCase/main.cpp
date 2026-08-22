
#include <iostream>

char toupper(char c);
char tolower(char c);
char toggle(char c);

using namespace std;

int main(){
    char c = 'A';
    cout << toupper(c) << tolower(c) << toggle(c) << endl;
    return 0;
}

char toupper(char c) 
{
    if ('a' <= c and c <= 'z')
    {
        return c - ('a' - 'A');
    }
    return c;
}

char tolower(char c)
{
    if ('A' <= c and c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}

char toggle(char c)
{
    if ('a' <= c and c <= 'z')
    {
        return c - ('a' - 'A');
    }
    else if ('A' <= c and c <= 'Z')
    {
        return c + ('a' - 'A');
    }
    return c;
}
