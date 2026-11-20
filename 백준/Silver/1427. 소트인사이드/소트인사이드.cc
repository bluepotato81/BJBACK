#include <stdio.h>
#include <string.h>

int main() {
    char numc[11];
    scanf("%s", numc);
    size_t len=strlen(numc);

    int num[len];
    for (size_t i = 0; i < len; i++) {
        num[i] = numc[i] - '0'; // Convert char to int by subtracting '0'
    }

    size_t check=0;
    while(check!=len-1) {
        check=0;
        for(size_t i=0; i<len-1; i++) {
            if(num[i]<num[i+1]) {
                int pl;
                pl=num[i];
                num[i]=num[i+1];
                num[i+1]=pl;
            }
            else {
                check++;
            }
        }
    }

    for(int i=0; i<len; i++) {
        printf("%d", num[i]);
    }



    return 0;
}

