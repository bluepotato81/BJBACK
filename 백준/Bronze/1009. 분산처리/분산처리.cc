#include <stdio.h> 

int main() {
	int t;
	scanf("%d ", &t);
	while(t--) {
		int a,b;
		scanf("%d %d", &a, &b);
		int k=1;
		while(b--) {
			k=(a*k)%10;
		}
		if(k==0) {
			printf("10\n");
		}
		else {
			printf("%d\n", k);
		}
		
	}
	return 0;
}