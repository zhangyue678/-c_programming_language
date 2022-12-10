#include <stdio.h>

int atoi(char s[])
{
    int i, n;
  
    n = 0;
    for(i=0; s[i]>='0' && s[i]<='9'; ++i)
        n = 10*n + (s[i]-'0');
    return n;
}

int main()
{
    int num;
    char s[6] = "12345";
    num = atoi(s);
    printf("\"%s\": %d\n", s, num);
    return 0;
}