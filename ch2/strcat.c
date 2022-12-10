#include <stdio.h>
#include <stdlib.h>

void my_strcat(char s[], char t[])
{
    int i=0, j=0;
    while (s[i] != '\0')
        i++;
    while ((s[i++]=t[j++]) != '\0');
}

int main()
{
    char *s;
    char *t;
    int size=1024;
    s = (char *)malloc(size * 2);
    t = (char *)malloc(size);

    printf("Please input the string s: ");
    gets(s);
    printf("Please input the string t: "); 
    gets(t);

    my_strcat(s, t);
    printf("\"s\": %s\n", s);

    free(s);
    free(t);
    return 0;
}