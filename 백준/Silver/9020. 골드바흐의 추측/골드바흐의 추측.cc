#include <stdio.h>

void prime(int is_prime[]) {
    for(int i=0; i<=10000; i++) {
        is_prime[i]=1;
    }

    is_prime[0]=is_prime[1]=0;
    for(int i=2;i*i<=10000; i++) {
        if(is_prime[i]) {
            for(int j=i*i;j<=10000;j+=i) {
                is_prime[j]=0;
            }
        }
    }

}

void goldbach(int num, int is_prime[]) {
    for(int i=num/2; i>0; --i) {
        if(is_prime[i]&&is_prime[num-i]) {
        	printf("%d %d\n", i, num-i);
        	return;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    int is_prime[10001];
    prime(is_prime);

    for(int i=0; i<t; i++) {
        int n;
        scanf("%d", &n);
        goldbach(n, is_prime); 
    }

    return 0;
}
