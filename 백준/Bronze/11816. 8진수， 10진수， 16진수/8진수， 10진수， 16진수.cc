#include <stdio.h>
#include <string.h>

int main() {
    char num[10];
    scanf("%s", num);

    size_t len=strlen(num);
    int res=0;
    if(num[0]=='0') {
        if(num[1]=='x') {
            for(int i=2; i<len;i++) {
                if(num[i]>='0' && num[i]<='9') {
                    res+=num[i]-'0';
                }
                else {
                    res+=num[i]-'a'+10;
                }

                res*=16;
            }
            printf("%d", res/16);
        }
        else {
            for(int i=1; i<len;i++) {
                res+=num[i]-'0';
                res*=8;
            }
            printf("%d", res/8);
        }
    }
    else {
        printf("%s", num);
    }

    return 0;
}
