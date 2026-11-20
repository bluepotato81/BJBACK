#include <stdio.h>

int main() {
    int n,m;
    scanf("%d", &n);
    scanf("%d", &m);

    char ioi[m];
    scanf("%s",ioi);

    int num=0;
    int cur_len=0;

    for(int i=0; i<m-2; i++) {
        if(ioi[i]=='I' && ioi[i+1]=='O' && ioi[i+2]=='I') {
            cur_len++;
            i++;
        }
        else if(cur_len>=1) {
            if(cur_len-n+1>0){
                num+=cur_len-n+1;
            }
            cur_len=0;
        }
        
    }
    if(cur_len-n+1>0){
        num+=cur_len-n+1;
    }


    printf("%d", num);


    return 0;
}

