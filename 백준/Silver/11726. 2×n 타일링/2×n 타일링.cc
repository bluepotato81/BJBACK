#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int ways[t];
    ways[0]=1;
    ways[1]=2;
    for(int i=2; i<t; i++) {
    	ways[i]=(ways[i-1]+ways[i-2])%10007;
    }
    printf("%d", ways[t-1]);




	return 0;
}
