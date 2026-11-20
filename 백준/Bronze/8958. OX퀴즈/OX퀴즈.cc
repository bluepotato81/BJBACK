#include <stdio.h>
#include <string.h>

int main() {
    int n, p, sum;
    char q[81];
    scanf("%d", &n);
    int a[n];
    for(int j=0; j<n; j++) {
        scanf("%s", q);
        p=0;
        sum=0;
        for(size_t i=0; i<strlen(q); i++) {
            if(q[i]=='O') {
                p++;
                sum+=p;
            }
            else {
                p=0;
            }
        }
        a[j] = sum;
    }

    for(int i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }



    return 0;
}
