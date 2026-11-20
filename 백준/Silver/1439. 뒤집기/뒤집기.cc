#include <stdio.h>
#include <string.h>

char in[1000000];

int main() {
    scanf("%s", in);

    size_t l=strlen(in);

    int z=0;
    int o=0;

    for(size_t i=1; i<l;i++) {
        if(in[i]!=in[i-1]) {
            if(in[i-1]=='0') {
                z++;
            }
            else {
                o++;
            }
        }
    }

   if(in[l-1]=='1') {
        o++;
    }
    else {
        z++;
    }

    if(z<o) {
        printf("%d", z);
    }
    else {
        printf("%d", o);
    }

    return 0;
}
