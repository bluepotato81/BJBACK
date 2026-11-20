#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char in[101];
    scanf(" %[^\n]", in);

    size_t len= strlen(in);

    char out[1000];

    int pos=0;
    for(size_t i=0;i<len; i++) {
        if(in[i]==' ') {
            out[pos++]='D';
            out[pos++]='O';
            out[pos++]='R';
            out[pos++]='O';
        }
        out[pos++]=in[i];
    }
    out[pos++]='D';
    out[pos++]='O';
    out[pos++]='R';
    out[pos++]='O';

    out[pos]='\0';

    printf("%s", out);


    return 0;
}
