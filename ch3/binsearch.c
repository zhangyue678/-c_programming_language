#include <stdio.h>
#include <time.h>

#define MAX 100

int bisearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high)
    {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int x = 45;
    int v[MAX];
    int i;
    for (i=0; i<MAX; i++)
        v[i] = i;

    int index = bisearch(x, v, MAX);
    printf("num: %d, index: %d\n", x, index);
    return 0;
}

