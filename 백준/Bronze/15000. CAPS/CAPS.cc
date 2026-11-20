#include <stdio.h>
#include <string.h>

char mes[1000001];
int main() {
    scanf("%s", mes);
    size_t a = strlen(mes);
    for(size_t i=0; i<a; i++) {
        mes[i]=mes[i]-'a'+'A';
    }
    for(size_t i=0; i<a; i++) {
        printf("%c", mes[i]);
    }

    return 0;
}
