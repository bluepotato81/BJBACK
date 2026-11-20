#include <stdio.h>

int main() {
	int a,b,d;
	scanf("%d %d %d", &a, &b, &d);
	int m=a*b*d;
	
	int top=0, c=1;
	while(c<m/10) {
		c*=10;
		top++;
	}
	
	int nums[10]={0,};
	
	int m2=m;
	for(int i=top; i>0; i--) {
		int ten=1;
		for(int j=0; j<i; j++) {
			ten*=10;
		}
		nums[m2/ten]++;
		m2-=(m2/ten)*ten;
	}
	
	nums[m2]++;
	
	for(int i=0; i<10; i++) {
		printf("%d\n", nums[i]);
	}
	
	return 0;
}