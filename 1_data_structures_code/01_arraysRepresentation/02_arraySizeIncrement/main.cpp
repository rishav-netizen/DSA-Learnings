#include <iostream>

using namespace std;

// we cant resize and array, but we use a way to do so by pointers in heap memory
// arrays are contigious memory locations so you basically cant resize them, 
// because after the array ends we dont have any idea of the memory next to it
// it could have been use by other stuff in memory
void print_arr(int array[], int l);

int main(){
    // initializing pointer for dynamic array
    int* p;
    int l1 = 6;
    p = new int[6];
    for (int i = 0; i < l1; i++)
    {   
        p[i] = (i+1)*(i+1);
    }
    print_arr(p, l1);
    
    
    // resizing array (technically)
    int* q;
    int l2 = 10;
    q = new int[l2];

    // copying old array values into new
    for (int i = 0; i < l1; i++)
    {
        q[i] = p[i];
    }
    delete []p; //delete p after use (i.e. copy)

    // pointing p to where q was and now q points to nothing
    p = q;
    q = NULL;
    print_arr(p, l2);

    // now assigning values to the new index of p
    for (int i = l1; i < l2; i++)
    {
        p[i] = (i+1)*(i+1);
    }

    print_arr(p, l2);
    //! print_arr(q, l2); (this gives seg fault since q is now pointing to NULL)
    
    // deleting q after use
    delete []q;

    return 0;
}

void print_arr(int array[], int l)
{
    cout << "{";
    for(int i = 0; i < l; i++)
    {
        cout << array[i];
        if (i < l - 1)
        {
            cout << ", ";
        }
    }
    cout << "}\n";
}