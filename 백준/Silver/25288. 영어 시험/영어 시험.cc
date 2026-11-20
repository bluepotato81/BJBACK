#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char in[n+1];
    scanf("%s", in);

    int len = strlen(in);

    for(int i=0; i<n;i++) {
        for(int j=0;j<len;j++) {
            printf("%c", in[j]);
        }
    }

    return 0;
}
