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
	int costr[n][3];
	int costg[n][3];
	int costb[n][3];

	costr[0][0]=red[0];
	costr[0][1]=costr[0][2]=1000000;
	costg[0][1]=green[0];
	costg[0][0]=costg[0][2]=1000000;
	costb[0][2]=blue[0];
	costb[0][0]=costb[0][1]=1000000;
	for(int i=1; i<n; i++) {
		costr[i][0] = min(costr[i-1][1], costr[i-1][2]) + red[i];
        costr[i][1] = min(costr[i-1][0], costr[i-1][2]) + green[i];
        costr[i][2] = min(costr[i-1][0], costr[i-1][1]) + blue[i];

        costg[i][0] = min(costg[i-1][1], costg[i-1][2]) + red[i];
        costg[i][1] = min(costg[i-1][0], costg[i-1][2]) + green[i];
        costg[i][2] = min(costg[i-1][0], costg[i-1][1]) + blue[i];

        costb[i][0] = min(costb[i-1][1], costb[i-1][2]) + red[i];
        costb[i][1] = min(costb[i-1][0], costb[i-1][2]) + green[i];
        costb[i][2] = min(costb[i-1][0], costb[i-1][1]) + blue[i];
	}

	int minr = min(costr[n-1][1], costr[n-1][2]);
    int ming = min(costg[n-1][0], costg[n-1][2]);
    int minb = min(costb[n-1][0], costb[n-1][1]);


	int finmin = min(minr, min(ming, minb));
	printf("%d", finmin);
	return 0;
}
