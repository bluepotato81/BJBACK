#include <stdio.h>
#include <string.h>

int main() {
    char n[6];
    
    while(1) {
    	scanf("%s", n);
    	if(n[0]=='0') {
    		break;
    	}
    	size_t len=strlen(n);
    	size_t cen=len/2;
    	size_t a=0;
    	for(size_t i=0;i<cen; i++) {
    		if(n[i]!=n[len-i-1]) {
    			printf("no\n");
    			break;
    		}
    		a++;
    	}
    	if(a==cen) {
    		printf("yes\n");
    	}
    }

    return 0;
}
