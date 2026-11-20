#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);


	long long o=0, tw=0, tr=1;

	for(int i=0; i<n-1; i++) {
		long long next=tw+tr;
		o=tw;
		tw=tr;
		tr=next;
	}

	printf("%lld", 4*tr+2*tw);

}
