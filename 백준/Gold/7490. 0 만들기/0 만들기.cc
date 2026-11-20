#include <stdio.h>
#include <string.h>

char toprint[18];

int compute(int n) {
    int res=0;
    int curval=0;
    int curnum;
    curval+=1;
    char curop;
    for(int i=0; i<n-1;i++) {
        curop=toprint[2*i+1];
        curnum=toprint[2*i+2]-'1'+1;
        if(curop==' ') {
            curval*=10;
            if(curval<0) {
                curval-=curnum;
            }
            else {
                curval+=curnum;
            }
        }
        else if(curop=='+') {
            res+=curval;
            curval=curnum;
        }
        else {
            res+=curval;
            curval=-curnum;
        }
    }

    res+=curval;

    return res;
}

void calc(int n, int stage) {
    if(n==stage) {
        toprint[2*stage-2]='1'+stage-1;
        int cal=compute(n);
        if(cal==0) {
            for(int i=0; i<2*n-1; i++) {
                printf("%c", toprint[i]);
            }
            printf("\n");
        }
    }
    else {
        toprint[2*stage-2]='1'+stage-1;
        toprint[2*stage-1]=' ';
        calc(n,stage+1);
        toprint[2*stage-1]='+';
        calc(n,stage+1);
        toprint[2*stage-1]='-';
        calc(n,stage+1);
    }
}



int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        calc(n,1);
        printf("\n");
    }





    return 0;
}
