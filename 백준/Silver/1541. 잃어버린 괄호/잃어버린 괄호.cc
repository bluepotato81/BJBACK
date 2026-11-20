#include <stdio.h>
#include <string.h>

int main() {
    char inp[51];
    scanf("%s", inp);

    int curnum=0;
    int result=0;
    int minus=0;
    size_t len=strlen(inp);
    for (size_t i=0; i <= len; i++) {
        if (inp[i]>='0' && inp[i]<='9') {
            curnum=curnum*10+(inp[i]-'0');
        }
        else if (inp[i]=='+'||inp[i]=='-'||inp[i]=='\0') {
            if (minus) {
                result-=curnum;
            } else {
                result+=curnum;
            }
            if (inp[i]=='-') {
                minus = 1;
            }
            curnum = 0;
        }
    }

    printf("%d", result);

    return 0;
}
