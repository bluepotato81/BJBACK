#include <stdio.h>

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int len=1;
        for(int i=0; i<n; i++) {
            len*=3;
        }
        char dashes[len];
        for(int i=0; i<len; i++) {
            dashes[i]='-';
        }
        for(int i=n-1; i>=0; i--) {
            int dellen=1;
            for (int j=0; j<i; j++) {
                dellen*=3;
            }
            int toplen;
            toplen=dellen*3;
            for(int j=0; j<len; j++) {
                if(j%toplen==dellen) {
                    for(int k=0; k<dellen; k++) {
                        dashes[j]=' ';
                        j++;
                    }
                }
            }
        }
        for(int i=0; i<len; i++) {
            printf("%c", dashes[i]);
        }
        printf("\n");
    }

    return 0;
}
