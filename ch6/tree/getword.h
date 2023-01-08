#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAXSIZE 100

char buf[MAXSIZE];
int bufp;

int getch(void){
    int p = (bufp > 0) ? buf[--bufp] : getchar();
    return p;
}

void ungetch(int c){
    if(bufp >= MAXSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
        buf[bufp++] = c;
}

int getword(char *word, int lim){
    int c;
    char *w = word;
    
    while(isspace(c = getch()))
        ;
    if(c != EOF){
        *w++ = c; 
    }
    if(!isalpha(c)){
        *w = '\0';
        return c;
    }
    for(; --lim > 0; w++){
        if(!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}