#include <stdio.h>

typedef struct{
    char name;
    char parent;
    char childl;
    char childr;
}node;

node tree[26];

void first(int n, char cur) {
    printf("%c", cur);
    if(tree[cur-'A'].childl!='.') {
        first(n, tree[cur-'A'].childl);
    }
    if(tree[cur-'A'].childr!='.') {
        first(n, tree[cur-'A'].childr);
    }
}

void second(int n, char cur) {

    if(tree[cur-'A'].childl!='.') {
        second(n, tree[cur-'A'].childl);
    }
    printf("%c", cur);
    if(tree[cur-'A'].childr!='.') {
        second(n, tree[cur-'A'].childr);
    }
}

void third(int n, char cur) {

    if(tree[cur-'A'].childl!='.') {
        third(n, tree[cur-'A'].childl);
    }

    if(tree[cur-'A'].childr!='.') {
        third(n, tree[cur-'A'].childr);
    }
    printf("%c", cur);
}

int main() {
    int n;
    char a,b,c;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        tree[i].parent='0';
    }


    for(int i=0; i<n; i++) {
        scanf(" %c %c %c", &a, &b, &c);
        tree[a-'A'].name=a;
        tree[a-'A'].childl=b;
        if(b!='.') {
            tree[b-'A'].parent=a;
        }
        tree[a-'A'].childr=c;
        if(c!='.') {
            tree[c-'A'].parent=a;
        }
    }
    char top='0';

    for(int i=0; i<n; i++) {
        if(tree[i].parent=='0'&& tree[i].name != '\0') {
            top='A'+i;
            break;
        }
    }


    first(n,top);
    printf("\n");
    second(n,top);
    printf("\n");
    third(n,top);

    return 0;
}
