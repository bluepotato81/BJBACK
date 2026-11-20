#include <stdio.h>
#include <string.h>

char num[333335];

int main() {
    scanf("%s", num);

    size_t len=strlen(num);
    
    if(num[0]=='0') {
        printf("0");
        return 0;
    }
    
    for(size_t i=0; i<len; i++) {
        if(i==0) {
            if(num[i]=='1') {
                printf("1");
            }
            if(num[i]=='2') {
                printf("10");
            }
            if(num[i]=='3') {
                printf("11");
            }
            if(num[i]=='4') {
                printf("100");
            }
            if(num[i]=='5') {
                printf("101");
            }
            if(num[i]=='6') {
                printf("110");
            }
            if(num[i]=='7') {
                printf("111");
            }
        }
        else {
            if(num[i]=='0') {
                printf("000");
            }
            if(num[i]=='1') {
                printf("001");
            }
            if(num[i]=='2') {
                printf("010");
            }
            if(num[i]=='3') {
                printf("011");
            }
            if(num[i]=='4') {
                printf("100");
            }
            if(num[i]=='5') {
                printf("101");
            }
            if(num[i]=='6') {
                printf("110");
            }
            if(num[i]=='7') {
                printf("111");
            }
        }
    }

    return 0;
}
