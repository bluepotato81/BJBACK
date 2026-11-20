#include <stdio.h>
#include <string.h>

int main() {
	int a;
	scanf("%d", &a);

	int de[2000001];


	char in[6];

	int deend=0;
	int destart=0;
	for(int i=0; i<a; i++) {
		scanf("%s", in);
		if(strcmp(in,"push")==0) {
			int s;
			scanf("%d", &s);
			de[deend]=s;
			deend++;
		}
		if(strcmp(in,"pop")==0) {
			if(deend==destart) {
				printf("-1\n");
			}
			else {
				printf("%d\n", de[destart]);
				destart++;
			}
		}
		if(strcmp(in,"size")==0) {
			printf("%d\n", deend-destart);
		}
		if(strcmp(in,"empty")==0) {
			if(deend==destart) {
				printf("1\n");
			}
			else {
				printf("0\n");
			}
		}
		if(strcmp(in,"front")==0) {
			if(deend==destart) {
				printf("-1\n");
			}
			else {
				printf("%d\n", de[destart]);
			}
		}
		if(strcmp(in,"back")==0) {
			if(deend==destart) {
				printf("-1\n");
			}
			else {
				printf("%d\n", de[deend-1]);
			}
		}
	}

	return 0;
}
