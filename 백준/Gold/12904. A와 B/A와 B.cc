#include <stdio.h>
#include <string.h>

char s[1000];
char t[1001];


void swap(size_t curlen) {
    for(int i=0; i<(curlen-1)/2; i++) {
        char a=t[i];
        char b=t[curlen-2-i];
        char temp;
        temp=b;
        t[curlen-2-i]=a;
        t[i]=b;
    }
    t[curlen-1]='\0';
}

int check(size_t slen, size_t tlen) {
    while(1) {
        if(t[tlen-1]=='A') {
            t[tlen-1]='\0';
        }
        else {
            swap(tlen);
        }
        tlen--;
        if(slen==tlen) {
            if(strcmp(s,t)==0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        //printf("%s\n", t);

    }

}

int main() {
    scanf("%s", s);
    scanf("%s", t);

    size_t slen=strlen(s);
    size_t tlen=strlen(t);

    int k=check(slen, tlen);

    printf("%d", k);

    return 0;
}
