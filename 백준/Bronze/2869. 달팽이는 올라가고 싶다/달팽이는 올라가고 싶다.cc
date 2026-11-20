#include <stdio.h>

int main() {
	int a,b,v;
	scanf("%d %d %d", &a, &b, &v);
	
	
	int prev=v-a;
	int day;
	if(prev%(a-b)==0) {
		day=prev/(a-b);
	}
	else {
		day=prev/(a-b)+1;
	}
	
	
	
	printf("%d", day+1);
	return 0;
}