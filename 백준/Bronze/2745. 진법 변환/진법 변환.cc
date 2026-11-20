#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char N[31];
    scanf("%s",N);
    int b;
    scanf("%d",&b);

    size_t len=strlen(N);
    int num=0;
    for(size_t i=0;i<=len-1;i++) {
        if(N[i]>='0' && N[i]<='9') {
            num+=(N[i]-'0')*pow(b,len-i-1);
        }
        if(N[i]>='A' && N[i]<='Z') {
            num+=(N[i]-'A'+10)*pow(b,len-i-1);
        }
    }
    printf("%d",num);

    return 0;
}
