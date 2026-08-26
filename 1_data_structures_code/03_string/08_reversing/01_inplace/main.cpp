#include <iostream>

using namespace std;

// using in space char array
int main(){
    char a[] = "python";
    
    int j, i;
    for(j = 0; a[j]; j++);
    j = j - 1; // since we dont wanna reverse '\0'

    char temp;
    for (i = 0; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    
    cout << a << endl;
    return 0;
}
