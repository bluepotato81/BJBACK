#include <stdio.h>
#include <string.h>

int main() {
    char cro[1001];
    scanf("%s", cro);
    size_t len=strlen(cro);
    size_t count=len;

    for(size_t i=0; i<len; i++) {
        if(cro[i]=='c' && cro[i+1]=='=') {
            count--;
            i++;
        }
        if(cro[i]=='c' && cro[i+1]=='-') {
            count--;
            i++;
        }
        if(cro[i]=='d' && cro[i+1]=='z' && cro[i+2]=='=') {
            count--;
            count--;
            i++;
            i++;
        }
        if(cro[i]=='d' && cro[i+1]=='-') {
            count--;
            i++;
        }
        if(cro[i]=='l' && cro[i+1]=='j') {
            count--;
            i++;
        }
        if(cro[i]=='n' && cro[i+1]=='j') {
            count--;
            i++;
        }
        if(cro[i]=='s' && cro[i+1]=='=') {
            count--;
            i++;
        }
        if(cro[i]=='z' && cro[i+1]=='=') {
            count--;
            i++;
        }

    }
    printf("%d", count);

    return 0;
}
