#include <stdio.h>

int main() {
    int s[10000]= {1,};

    for(int i=1; i<=10000;i++) {
        int big=0;
        if(i<10) {
            big=2*i;
        }
        else if(i<100) {
            big+=i;
            big+=i/10;
            big+=i%10;
        }
        else if(i<1000) {
            big+=i;
            big+=i/100;
            big+=(i/10)%10;
            big+=i%10;
        }
        else if(i<10000) {
            big+=i;
            big+=i/1000;
            big+=(i/100)%10;
            big+=(i/10)%10;
            big+=i%10;
        }
        else {
            big=10001;
        }
        if(big<=10000)
        s[big-1]--;
    }

    for(int i=0;i<10000;i++) {
        if(s[i]==1 || s[i]==0){
            printf("%d\n",i+1);
        }

    }


    return 0;
}
