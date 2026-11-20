#include <stdio.h> 

int main() {
	int a;
	scanf("%d", &a);
	int num[2*a+1];
	
	if(a==1) {
		printf("1");
		return 0;
	}
	
	for(int i=0; i<2*a; i++) {
		num[i]=0;
	}
	
	for(int i=0; i<=a; i++) {
		num[i]=i;
	}
	int i=1;
	int k=1;
	int s;
	while(1) {
		if(num[i+2]==0) {
			s = i+1;
			break;
		}
		num[a+k]=num[i+1];
		k++;
		i+=2;
	}
	
	printf("%d", num[s]);
			
	return 0;
}