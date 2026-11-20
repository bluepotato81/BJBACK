#include <stdio.h>

void prime(int is_prime[]) {
    for(int i=0; i<=1000000; i++) {
        is_prime[i]=1;
    }

    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=1000000; i++) {
        if(is_prime[i]) {
            for(int j=i*i;j<=1000000;j+=i) {
                is_prime[j]=0;
            }
        }
    }

}

int goldbach(int num, int is_prime[]) {
    int k=0;
    for(int i=2; i<=num/2; ++i) {
        if(is_prime[i]&&is_prime[num-i]) {
            k++;
        }
    }
    return k;
}

int main() {
    int t;
    scanf("%d", &t);

    int is_prime[1000001];
    prime(is_prime);

    for(int i=0; i<t; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", goldbach(n, is_prime));
    }

    return 0;
}
