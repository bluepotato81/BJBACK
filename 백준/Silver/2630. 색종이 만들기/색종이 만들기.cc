#include <stdio.h>

int nums[128][128];
int white=0;
int blue=0;

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
        divide(x,y,nexlen);
        divide(x+nexlen, y, nexlen);
        divide(x,y+nexlen,nexlen);
        divide(x+nexlen, y+nexlen, nexlen);
    }
    else {
        if(comp==1) {
            blue++;
        }
        else {
            white++;
        }
    }
}


int main() {
	int n;
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			scanf("%d", &nums[i][j]);
		}
	}
    white=0;
    blue=0;
    divide(0,0,n);
    printf("%d\n%d",white,blue);

	return 0;
}
