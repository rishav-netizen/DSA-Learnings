#include <iostream> 

using namespace std;

int main(void)
{
    // dynamic memory 
    // all pointers take 8byte memory in stack irrespective of the data type they point to
    int *p;
    p = new int[5];
    // after use
    delete []p;

    return 0;
}