#include <stdio.h>
#include <string.h>

int main() {
    char in[6];
    int k;
    int b=4;
    int ans=0;
    while(b--) {
        scanf("%s %d", in, &k);
        if(strcmp(in, "Es")==0) {
            ans+=k*21;
        }
        else {
            ans+=k*17;
        }
    }
    
    printf("%d", ans);
    return 0;
}