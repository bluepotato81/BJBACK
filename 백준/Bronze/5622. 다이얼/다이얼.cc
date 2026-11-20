#include <stdio.h>
#include <string.h>


int main() {
	char tel[16];
	scanf("%s", tel);
	size_t len =strlen(tel);
	int time=0;
	for(size_t i=0; i<len; i++) {
		if(tel[i]=='A' || tel[i]=='B'|| tel[i]=='C') {
			time +=3;
		}
		if(tel[i]=='D' || tel[i]=='E'|| tel[i]=='F') {
			time +=4;
		}
		if(tel[i]=='G' || tel[i]=='H'|| tel[i]=='I') {
			time +=5;
		}
		if(tel[i]=='J' || tel[i]=='K'|| tel[i]=='L') {
			time +=6;
		}
		if(tel[i]=='M' || tel[i]=='N'|| tel[i]=='O') {
			time +=7;
		}
		if(tel[i]=='P' || tel[i]=='Q'|| tel[i]=='R' || tel[i]=='S') {
			time +=8;
		}
		if(tel[i]=='T' || tel[i]=='U'|| tel[i]=='V') {
			time +=9;
		}
		if(tel[i]=='W' || tel[i]=='X'|| tel[i]=='Y' || tel[i]=='Z') {
			time +=10;
		}
	}
	printf("%d", time);
	
	return 0;
}