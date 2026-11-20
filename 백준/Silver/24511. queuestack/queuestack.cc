#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queuestack[n];
    int value[n];

    for(int i=0; i<n; i++) {
        scanf("%d", &queuestack[i]);
    }

    int valuen=0;
    for(int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        if(queuestack[i]==0){
            value[valuen]=a;
            valuen++;
        }
    }

    int m;
    scanf("%d", &m);

    int addvalues[m];
    for(int i=0; i<m; i++) {
        scanf("%d", &addvalues[i]);
    }
    int svaluen=valuen;

    for(int i=0; i<m; i++) {
        if(valuen>0) {
            valuen--;
            printf("%d ", value[valuen]);
        }
        else {
            printf("%d ", addvalues[i-svaluen]);
        }
    }

    return 0;
}
