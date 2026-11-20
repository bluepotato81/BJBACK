#include <stdio.h>
#include <string.h>

int main() {
	int art;
	scanf("%d", &art);
	char se[21];
	for(int i=0;i<art;i++) {
		char a[1001];
		scanf("%s",a);
		se[2*i]=a[0];
		se[2*i+1]=a[strlen(a)-1];
	}
	
	for(int i=0; i<art;i++) {
		printf("%c%c\n", se[2*i], se[2*i+1]);
		
	}

	return 0;
}