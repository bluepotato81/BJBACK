#include <stdio.h> 

int main() {
	int tot;
	scanf("%d", &tot);
	
	int s,m,l,xl,xxl,xxxl;
	scanf("%d %d %d %d %d %d", &s, &m, &l, &xl, &xxl, &xxxl);
	
	int t,p;
	scanf("%d %d", &t, &p);
	int tshirt=0;
	tshirt+=((s+t-1)/t);
	tshirt+=((m+t-1)/t);
	tshirt+=((l+t-1)/t);
	tshirt+=((xl+t-1)/t);
	tshirt+=((xxl+t-1)/t);
	tshirt+=((xxxl+t-1)/t);
	
	int penb, peno;
	penb=tot/p;
	peno=tot-(p*penb);
	
	printf("%d\n%d %d", tshirt, penb, peno);
	
	
	
	return 0;
}