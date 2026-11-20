#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void shuffle(int *array, size_t n)
{
    if (n > 1)
    {
        size_t i;
        for (i = 0; i < n - 1; i++)
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}


int main() {
    int n;
    scanf("%d", &n);

    int array1[1000];
    int array2[1000];

    for(int i=0; i<1000; i++) {
        array1[i]=i+1;
        array2[i]=i+1;
    }

    while(n) {
        shuffle(array1, 1000);
        shuffle(array2, 1000);

        long long decpoint=(1000*array1[0])+array2[0];

        printf("%lld %lld\n", decpoint, 0);
        fflush(stdout);
        long long r1;
        scanf("%lld", &r1);

        printf("%lld %lld\n", decpoint+1, 0);
        fflush(stdout);
        long long r2;
        scanf("%lld", &r2);

        long long xc=((2*decpoint)+1+r1-r2)/2;

        long long left= (xc-decpoint)*(xc-decpoint);
        long long right= r1-left;
        long long yc=(long long) sqrt((double) right);

        printf("%lld %lld\n", xc, yc);
        fflush(stdout);

        long long res;
        scanf("%lld", &res);


        if(res==0) {
            n-=1;
        }
    }

    return 0;
}
