#include <stdio.h>

int main() {

	int n,m;
	int tot=0;
	scanf("%d %d", &n, &m);
	tot+=n;
	tot+=m;
	scanf("%d %d", &n, &m);
	tot+=n;
	tot+=m;

	printf("%d\n%d", tot/60, tot%60);

	return 0;
}
