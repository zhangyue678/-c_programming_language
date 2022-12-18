#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINES 5000
#define MAXLEN 1000

int getline(char s[], int lim);
char *lineptr[MAXLINES];
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void my_qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);

int main()
{
    int nlines;
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        my_qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}


int getline(char *s, int lim)
{
    int c, i;
    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
    {
        s[i] = c;
    }
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 1)
    {
        if(nlines >= maxlines || (p = (char*) malloc(sizeof(char) * len)) == NULL)
        {
            return -1;
        }
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    for(int i=0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}


void my_qsort(char *v[], int left, int right)
{   
    int i, last;
    if(left >= right){
        return;
    }
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left+1; i <= right; i++)
    {
        if(strcmp(v[i], v[last]) < 0)
        {
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    my_qsort(v, left, last-1);
    my_qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
    char * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}