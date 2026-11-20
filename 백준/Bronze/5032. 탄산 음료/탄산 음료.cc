#include <stdio.h>

int main() {

	int n,m,o;
	scanf("%d %d %d", &n, &m, &o);
    n+=m;
	int tot=0;
	while(n>=o) {
        tot+=n/o;
        n=(n/o)+(n-(o*(n/o)));
	}


	printf("%d", tot);

	return 0;
}
