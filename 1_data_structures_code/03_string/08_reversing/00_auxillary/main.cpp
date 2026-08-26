#include <iostream>

using namespace std;

// using auxillary char array
int main(){
    char a[] = "python";
    
    int l = 0;
    for(; a[l]; l++);

    cout << l << endl;

    char b[l + 1];
    l = l - 1;

    int j;
    for(j = 0; l >= 0; l--, j++)
        b[j] = a[l];
    
    b[j] = '\0';

    cout << a << endl << b << endl;
    return 0;
}
