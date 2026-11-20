#include <stdio.h>
#include <string.h>

int main() {
	int a;
	scanf("%d", &a);

	int o=0;
	int t=1;

	int ch=0;
	for(int i=0; i<a; i++) {
        if(ch%2==0) {
            o+=t;
        }
        else {
            t+=o;
        }
        ch++;
	}
	if(ch%2==1) {
        printf("%d",t);
	}
	else {
        printf("%d",o);
	}



	return 0;
}
