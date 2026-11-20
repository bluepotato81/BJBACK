#include <stdio.h>
#include <string.h>

int top(char in) {
    if(in=='(') return 0;
    if(in=='+'||in=='-') return 1;
    if(in=='*'||in=='/') return 2;
    return -1;
}

int main() {
    char c[101];
    scanf("%s", c);

    char stack[100];
    int stacklen=0;

    size_t len=strlen(c);

    for(size_t i=0; i<len;i++) {
        if(c[i]>='A'&&c[i]<='Z'){
            printf("%c", c[i]);
        }
        else {
            if(c[i]=='(') {
                stack[stacklen]='(';
                stacklen++;
            }
            else if(c[i]==')') {
                while(stacklen>0 && stack[stacklen-1]!='(') {
                    printf("%c", stack[--stacklen]);
                }
                if(stacklen>0 && stack[stacklen-1]=='(') {
                    stacklen--;
                }
            }
            else {
                while(stacklen>0 && top(stack[stacklen-1])>=top(c[i])) {
                    printf("%c", stack[--stacklen]);
                }
                stack[stacklen++]=c[i];
            }
        }
    }

    while(stacklen>0) {
        printf("%c", stack[stacklen-1]);
        stacklen--;
    }

    return 0;
}
