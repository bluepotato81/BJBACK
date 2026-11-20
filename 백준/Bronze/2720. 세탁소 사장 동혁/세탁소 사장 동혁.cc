#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	
	for(int i=0; i<t;i++) {
		int a;
		scanf("%d", &a);
		printf("%d ", a/25);
		a=a-((a/25)*25);
		printf("%d ", a/10);
		a=a-((a/10)*10);
		printf("%d ", a/5);
		a=a-((a/5)*5);
		printf("%d ", a);
		printf("\n");
	}
	return 0;
}