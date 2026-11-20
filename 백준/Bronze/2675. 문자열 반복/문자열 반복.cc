#include <stdio.h>
#include <string.h>

int main() {
	char in[21];
	int t;
	char all[168001];
	scanf("%d", &t);
	
	int rep;
	int place=0;
	for(int i=0;i<t;i++) {
		scanf("%d", &rep);
		scanf("%s", in);
		size_t len= strlen(in);
		for(size_t j=0;j<len;j++) {
			for(int k=0;k<rep;k++) {
				all[place]=in[j];
				place++;
			}
		}
		all[place]='\n';
		place++;
	}
	
	printf("%s", all);

	return 0;
}