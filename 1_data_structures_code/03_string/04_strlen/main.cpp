#include <iostream>

using namespace std;

int main(){
    char name[] = "welcome";
    int i = 0;
    for (; name[i]!='\0'; i++);
    cout << "Length: " << i << endl;
    return 0;
}