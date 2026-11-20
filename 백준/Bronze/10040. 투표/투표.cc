#include <stdio.h>

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int price[n];
    int rate[m];
    int vote[n];

    for(int i=0; i<n;i++) {
        scanf("%d", &price[i]);
        vote[i]=0;
    }
    for(int i=0; i<m;i++) {
        scanf("%d", &rate[i]);
    }

    for(int i=0; i<m;i++) {
        for(int j=0; j<n;j++) {
            if(price[j]<=rate[i]){
                vote[j]++;
                break;
            }
        }
    }

    int ans=0;
    int ma=0;
    for(int i=0; i<n;i++) {
        if(ma<vote[i]) {
            ans=i;
            ma=vote[i];
        }
    }

    printf("%d", ans+1);


    return 0;
}
