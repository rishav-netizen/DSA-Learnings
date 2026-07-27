#include <iostream>
#include <cmath> 

using namespace std;

int main()
{
    //? if size is given, number of elements not declared are zero
    int nums[8] = {1, 2, 3, 4, 5, 6};
    int l = sizeof(nums)/sizeof(int);

    for (int i = 0; i < l; i++)
    {
        cout << nums[i] << endl;
        cout << &nums[i] << endl;
    }
    
    return 0;
}