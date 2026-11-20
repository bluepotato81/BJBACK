#include <stdio.h>

long long min=1000000000000000;

int check=0;

void mul2(long long n, long long b, int time);
void put1(long long n, long long b, int time);

void mul2(long long n, long long b, int time) {
    if(2*n==b) {
        if(time+1<min) {
            min=time+1;
        }
        check=1;
        return;
    }
    else if(2*n>b) {
        return;
    }
    else {
        mul2(2*n, b, time+1);
        put1(2*n, b, time+1);
        return;
    }
}

void put1(long long n, long long b, int time) {
    if(10*n+1==b) {
        if(time+1<min) {
            min=time+1;
        }
        check=1;
        return;
    }
    else if(10*n+1>b) {
        return;
    }
    else {
        mul2(10*n+1, b, time+1);
        put1(10*n+1, b, time+1);
        return;
    }
}


int main() {
    long long a,b;
    scanf("%lld %lld", &a, &b);

    mul2(a,b,0);
    put1(a,b,0);

    if(check==0) {
        printf("-1");
    }
    else{
        printf("%d", min+1);
    }

    return 0;
}
