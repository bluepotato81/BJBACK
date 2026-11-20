#include <stdio.h>

char a[3075][6175];
int k;

void print(int x, int y, int z, int xl, int yl) {
    if(z==k) {
        x-=2;
        y-=4;
        a[x][y]='*';
        a[x+1][y]='*';
        a[x+1][y+2]='*';
        a[x+2][y]='*';
        a[x+2][y+1]='*';
        a[x+2][y+2]='*';
        a[x+2][y+3]='*';
        a[x+2][y+4]='*';
        return;
    }
    print(x-xl,y-yl,z+1,xl/2,yl/2);
    print(x,y-yl,z+1,xl/2,yl/2);
    print(x,y,z+1,xl/2,yl/2);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n*2; j++) {
            a[i][j]=' ';
        }
    }
    int le=n/3;
    while(le>1) {
        k++;
        le/=2;
    }
    print(n, 2*n-1, 0,n/2, n);
    int c=n-1;
    int jc=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=c;j++)
            printf(" ");
        c--;
        for(int j=c+1;j<=2*n-1;j++)
        {
            if(a[i][j-c]=='*')
                printf("*");
            else
                printf(" ");
        }
        if(i==n)
            break;
        printf("\n");
    }

    return 0;
}
