#include <stdio.h>
#include <string.h>

char in[101];

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", in);
        size_t l=strlen(in);

        for(size_t j=0; j<l;j++) {
            if(in[j]>='A' && in[j]<='Z') {
                printf("%c", in[j]-'A'+'a');
            }
            else {
                printf("%c", in[j]);
            }
        }
        printf("\n");
    }




    return 0;
}
