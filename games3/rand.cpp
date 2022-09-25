#include <iostream>
#include <random>
#include <time.h>
int main()
{
    srand((unsigned)time(NULL));
    int a = 1;
    int b = 100000;
    int n = (rand() % (b - a + 1)) + a;
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << (rand() % (b - a + 1)) + a << std::endl;
    return 0;
}