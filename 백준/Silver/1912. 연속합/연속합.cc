#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long num[100000];

    for(int i=0; i<n; i++) {
        scanf("%lld",&num[i]);
    }
    long long com[100000];
    com[0]=num[0];
    long long tot=com[0];
    for(int i=1; i<n;i++) {
        if(com[i-1]+num[i]>num[i]) {
            com[i]=com[i-1]+num[i];
        }
        else {
            com[i]=num[i];

        }
        if(com[i]>tot) {
            tot=com[i];

        }




    }

    printf("%lld", tot);


    return 0;
}
