#include <stdio.h>

int nums[128][128];

void divide(int x, int y, int len) {

    int check=1;
    int comp=nums[x][y];
    for(int i=x; i<x+len; i++) {
        for(int j=y; j<y+len; j++) {
            if(nums[i][j]!=comp){
                check=0;
                break;
            }
        }
        if(check==0) {
            break;
        }
    }
    if(check==0) {
        int nexlen=len/2;
        printf("(");
        divide(x,y,nexlen);
        divide(x, y+nexlen, nexlen);
        divide(x+nexlen,y,nexlen);
        divide(x+nexlen, y+nexlen, nexlen);
        printf(")");
    }
    else {
        if(comp==1) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
}


int main() {
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
            char c;
			scanf(" %c", &c);
			nums[i][j] = c-'0';
		}
	}


    divide(0,0,n);

	return 0;
}
