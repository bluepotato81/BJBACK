#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int types[10];

    int tang[200000];
    int tangend=0;
    int tangstart=0;

    int type=0;

    int ans=0;

    while(n--) {
        int in;
        scanf("%d", &in);
        tang[tangend++]=in;
        if(!types[in]++) {
            type++;
        }

        while(type>2) {
            in=tang[tangstart++];
            if(!--types[in]) {
                type--;
            }
        }

        if(tangend-tangstart>ans) {
            ans=tangend-tangstart;
        }
    }

    printf("%d", ans);

    return 0;
}
