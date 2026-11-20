#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char in[n];
    scanf("%s", in);

    size_t l = strlen(in);

    for(size_t i=0; i<5;i++) {
        printf("%c", in[l-(5-i)]);
    }

    return 0;
}
