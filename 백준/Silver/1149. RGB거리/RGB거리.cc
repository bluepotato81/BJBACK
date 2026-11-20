#include <stdio.h>


int min(int a, int b) {
	if(a>b){
 		return b;
	}	
	else {
		return a;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int red[n], green[n], blue [n];
	for(int i=0; i<n; i++) {
		scanf("%d %d %d", &red[i], &green[i], &blue[i]);
	}
	int cost[n][3];
	cost[0][0]=red[0];
	cost[0][1]=green[0];
	cost[0][2]=blue[0];
	for(int i=1; i<n; i++) {
		cost[i][0]=min(cost[i-1][1], cost[i-1][2])+red[i];
		cost[i][1]=min(cost[i-1][0], cost[i-1][2])+green[i];
		cost[i][2]=min(cost[i-1][1], cost[i-1][0])+blue[i];
	}
	
	printf("%d", min(cost[n-1][1], min(cost[n-1][0], cost[n-1][2])));
	return 0;
}