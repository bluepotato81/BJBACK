#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();


    for(int i=0; i<n;i++) {
        int f=0;
        char a;

        int mincheck=0;
        while(1) {
            scanf("%c",&a);
            if(a=='\n') {
                break;
            }
            if(a=='(') {
                f++;
            }
            else if(a==')') {
                f--;
            }
            if(f<0) {
                mincheck++;
            }
        }

        if(f==0 && mincheck==0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }


    return 0;
}
