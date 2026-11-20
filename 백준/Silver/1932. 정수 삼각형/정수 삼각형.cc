#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int tri[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<i+1; j++) {
			scanf("%d", &tri[i][j]);
		}
	}
	int max[n][n];
	max[0][0]=tri[0][0];
	for(int i=1; i<n; i++) {
		max[i][0]=max[i-1][0]+tri[i][0];
		for(int j=1; j<n; j++) {
			if(max[i-1][j-1]>max[i-1][j]) {
				max[i][j]=max[i-1][j-1]+tri[i][j];
			}
			else {
				max[i][j]=max[i-1][j]+tri[i][j];
			}
		}
		max[i][i]=max[i-1][i-1]+tri[i][i];
	}
	
	int maxa=0;
	for(int i=0; i<n; i++) {
		if(max[n-1][i]>maxa) {
			maxa=max[n-1][i];
		}
	}
	printf("%d", maxa);
	
	return 0;
}