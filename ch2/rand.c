#include <stdio.h>

unsigned long int next = 1;
int rand()
{
    next = next * 912849742 + 29749;
    return (unsigned int)(next/63953) % 2973;
}

void srand(unsigned int seed)
{
    next = seed;
}

int main()
{
    unsigned int seed = 68909;
    srand(seed);
    unsigned int r;
    r = rand();
    printf("The rand unsigned int is: %d\n", r);
    return 0;
}