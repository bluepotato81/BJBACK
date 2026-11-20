#include <stdio.h>

int main() {
    int ns;
    scanf("%d", &ns);
    char k[ns+1];
    scanf("%s", k);
    
    int n[5]={0, };
    for(int i=0;i<ns;i++) {
        if(k[i]=='u') {
            n[0]++;
        }
        if(k[i]=='o') {
            n[1]++;
        }
        if(k[i]=='s') {
            n[2]++;
        }
        if(k[i]=='p') {
            n[3]++;
        }
        if(k[i]=='c') {
            n[4]++;
        }
    }
    
    int m=1001;
    for(int i=0; i<5;i++) {
        if(n[i]<m) {
            m=n[i];
        }
    }
    printf("%d", m);
    
    return 0;
}