#include <stdio.h>

int main() {
	char n[1001];
	int num;
	scanf("%s", n);
	scanf("%d", &num);
	printf("%c", n[num-1]);
}