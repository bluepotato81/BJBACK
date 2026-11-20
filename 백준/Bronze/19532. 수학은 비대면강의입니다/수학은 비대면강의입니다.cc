#include <stdio.h>

int main() {

    int a,b,c,d,e,f;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);

    int ch=0;
    int x,y;
    for(int i=-999;i<1000;i++) {
        for(int j=-999;j<1000;j++) {
            if(i*a+j*b==c && i*d+j*e==f) {
                ch++;
                x=i;
                y=j;
                break;
            }
        }
        if(ch==1) {
            break;
        }
    }

    printf("%d %d",x,y);

    return 0;
}
