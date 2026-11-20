#include <stdio.h>
#include <string.h>

int c[1001][1001];
int k=0;

void bt(char a[], char b[], int i, int j) {
    if(i==0 || j==0) {
        return;
    }
    else if(a[i-1]==b[j-1]) {
        bt(a,b,i-1,j-1);
        k++;
    }
    else if(c[i][j-1]>c[i-1][j]) {
        bt(a,b,i,j-1);
    }
    else {
        bt(a,b,i-1,j);
    }
}

int main() {
    char a[1001], b[1001];
    scanf("%s\n%s", a,b);

    size_t lena=strlen(a), lenb=strlen(b);


    for(size_t i=0; i<=lena; i++) {
        c[i][0]=0;
    }
    for(size_t i=0; i<=lenb; i++) {
        c[0][i]=0;
    }
    for(size_t i=1; i<=lena; i++) {
        for(size_t j=1; j<=lenb; j++) {
            if(a[i-1]==b[j-1]) {
                c[i][j]=c[i-1][j-1]+1;
            }
            else {
                if(c[i][j-1]>c[i-1][j]) {
                    c[i][j]=c[i][j-1];
                }
                else {
                    c[i][j]=c[i-1][j];
                }
            }
        }
    }
    bt(a,b,lena,lenb);
    printf("%d", k);
    return 0;
}
