#include <stdio.h>
#include <string.h>


int main() {
	char num1[4], num2[4];
	
	scanf("%s %s", num1, num2);
	char space;
	
	space= num1[2];
	num1[2] = num1[0];
	num1[0] = space;
	
	space= num2[2];
	num2[2] = num2[0];
	num2[0] = space;
		
	int one, two;
	sscanf(num1, "%d", &one);
	sscanf(num2, "%d", &two);
	
	if(one>two) {
		printf("%d", one);
	}
	else {
		printf("%d", two);
	}
	
	return 0;
}