#include <iostream>
#include <string>

using namespace std;

auto add(auto... args) 
{                                                                                       
    return (... + args);                                                                                       
}       

//? works c++20 onwards
// auto add(auto a, auto b)
// {
//     return a + b;
// }

// auto add(auto a, auto b, auto c)
// {
//     return a + b + c;
// }

int main(){
    cout << add(1, 2, 3) << endl;
    cout << add(1, 20) << endl;
    cout << add(1.2, 2.0) << endl;
    cout << add(1, 2.0, 3, 4, 5, 6, 7, 90) << endl;
    cout << add((string)"hello ", "world") << endl;
    cout << add("world "s, "hello") << endl; 
    return 0;
}