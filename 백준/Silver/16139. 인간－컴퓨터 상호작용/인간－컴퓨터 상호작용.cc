#include <stdio.h>
#include <string.h>

int main() {
    char str[200001];
    char input;
    int i=0;
    while(scanf("%c", &input) != EOF && input != '\n') {
        str[i]=input;
        i++;
    }
    str[i]=='\0';

    size_t len=strlen(str);

    int charcom[len+1][26];
    for(int j=0; j<26; j++) {
        charcom[0][j]=0;
    }

    for(size_t i=1; i<len+1; i++) {
        int a=str[i-1]-'a';
        for(int j=0; j<26; j++) {
            if(a==j) {
                charcom[i][a]=charcom[i-1][a]+1;
            }
            else {
                charcom[i][j]=charcom[i-1][j];
            }
        }
    }

    int q;
    scanf("%d", &q);
    for(int i=0; i<q; i++) {
        char seek;
        int l, r;
        getchar();
        scanf("%c %d %d",&seek, &l, &r);
        int res = charcom[r+1][seek-'a']-charcom[l][seek-'a'];
        printf("%d\n", res);
    }

    return 0;
}
