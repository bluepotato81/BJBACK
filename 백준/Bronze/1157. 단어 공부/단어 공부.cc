#include <stdio.h>
#include <string.h>
char c[1000001];
int main() {
	int alpha[27]={0,};

	scanf("%s", c);
	size_t len=strlen(c);

	for(size_t i=0; i<len;i++) {
		if(c[i]>='a' && c[i]<'a'+27) {
			alpha[c[i]-'a']++;	
		}
		else if(c[i]>='A' && c[i]<'A'+27) {
			alpha[c[i]-'A']++;	
		}	

	}
	int max=0;
	int big=0;
	int doub=0;
	
	for(int i=0; i<27; i++) {
		if(alpha[i]>max) {
			max=alpha[i];
			big=i;
			doub=0;
		}
		else if(alpha[i]==max && max!=0) {
			doub++;
		}
	}
	if(doub!=0) {
		printf("?");
		return 0;
	}
	
	printf("%c", 'A'+big);
	
	return 0;
}