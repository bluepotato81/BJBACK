#include <stdio.h>

typedef struct{
    int height;
    int num;
}person;

int ppl[500001];
person stack[500001];
person temp;

long long maxcouple=0;
int stacklen=0;
int templen=0;

int see(int i) {
    if(stacklen==0) {
        stack[stacklen].height=ppl[i];
        stack[stacklen++].num=1;
    }
    else if(stack[stacklen-1].height>ppl[i]){
        maxcouple++;
        stack[stacklen].height=ppl[i];
        stack[stacklen++].num=1;
    }
    else if(stack[stacklen-1].height==ppl[i]) {
        maxcouple+=stack[stacklen-1].num;
        stack[stacklen-1].num++;
        temp.height=stack[stacklen-1].height;
        temp.num=stack[stacklen-1].num;
        stacklen--;
        if(stacklen!=0) {
            maxcouple++;
        }
        stack[stacklen].height=temp.height;
        stack[stacklen].num=temp.num;
        stacklen++;
    }
    else {
        maxcouple+=stack[stacklen-1].num;
        stacklen--;
        see(i);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &ppl[i]);
    }


    for(int i=0; i<n; i++) {
        see(i);
    }



    printf("%lld",maxcouple);

    return 0;
}
