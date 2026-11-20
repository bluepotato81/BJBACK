#include <stdio.h>

int main() {
    char k[14];
    scanf("%s",k);

    int aloc;
    int com=0;
    for(int i=0 ;i<12;i++) {
        if(k[i]=='*') {
            aloc=i;
        }
        else {
            if(i%2==0) {
                com+=k[i]-'0';
            }
            else {
                com+=3*(k[i]-'0');
            }
        }
        //printf("%d\n", com);
    }
    com+=k[12]-'0';
    //printf("%d\n", com);
    com=com%10;
    if(com==0) {
        printf("0");
        return 0;
    }

    if(aloc%2==0) {
        printf("%d",10-com);
    }
    else {
        for(int i=1;i<=9;i++) {
            if((com+(3*i))%10==0) {
                printf("%d", i);
                break;
            }
        }
    }



    return 0;
}
