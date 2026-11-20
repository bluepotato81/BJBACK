#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    float poi[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &poi[i]);
    }

    float max=0;
    for(int i=0; i<n; i++) {
        if(poi[i]>max) {
            max=poi[i];
        }
    }

    for(int i=0; i<n; i++) {
        poi[i]= (poi[i]/max)*100;
    }

    float av=0;
    for(int i=0; i<n; i++) {
        av+=poi[i];
    }

    av= av/n;

    printf("%f", av);

    return 0;
}

