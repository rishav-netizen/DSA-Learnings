#include <iostream>

int main(void)
{
    std::cout << "hello" << std::endl;

    // narrowing is when we try to shorten type by size like
    int n = 345354;
    short num = n;
    std::cout << num << std::endl;
    return 0;
    

}
