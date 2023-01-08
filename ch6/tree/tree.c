#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "getword.h" 

#define MAXWORD 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
struct tnode *talloc(void);
// char *strdup(char *);

int main(int argc, char const *argv[]){
    struct tnode *root = NULL;
    char word[MAXWORD];
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

struct tnode *talloc(void){
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// char *strdup(char *s) {
//     char *p;
//     p = (char *) malloc(strlen(s) + 1);
//     if (p != NULL)
//         strcpy(p, s);
//     return p;
// }

struct tnode *addtree(struct tnode *p, char *w) {
    int cond;
    if (p == NULL){
        p = talloc();  // 创建新的节点
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0){
        p->count++;
    } else if (cond > 0) {
        p->left = addtree(p->left, w);
    } else {
        p->right = addtree(p->right, w);
    }
    return p;
}

void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}