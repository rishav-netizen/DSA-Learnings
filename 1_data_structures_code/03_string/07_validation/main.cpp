#include <iostream>

using namespace std;

bool valid(const char *name);

int main(){
    const char* name1 = "Anil123";
    const char* name2 = "Ani?123";
    cout << valid(name1) << endl << valid(name2) << endl;
    return 0;
}

bool valid(const char *name)
{
    for (int i = 0; name[i]; i++)
    {
        if (!('a' <= name[i] and name[i] <= 'z') and !('A' <= name[i] and name[i] <= 'Z') and !('0' <= name[i] and name[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}