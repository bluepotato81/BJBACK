#include <stdio.h>
#include <string.h>

int main() {
    char n[8];
    scanf("%s", n);

    int num[9]={0, };

    size_t len=strlen(n);

    for(size_t i=0; i<len;i++) {
        int k = n[i]-'0';
        if(k==9) {
            num[6]++;
        }
        else {
            num[k]++;
        }
    }

    int max=0;

    for(int i=0; i<9;i++) {
        if(i==6) {
            if((num[i]/2)+(num[i]%2)>max) {
                max=(num[i]/2)+(num[i]%2);
            }
        }
        else {
            if(num[i]>max) {
                max=num[i];
            }
        }

    }

    printf("%d", max);

    return 0;
}
