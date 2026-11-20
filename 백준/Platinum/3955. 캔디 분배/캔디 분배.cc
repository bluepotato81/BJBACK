#include <stdio.h>


int gcd(int a,int n) {
	int t=0;
	int newt=1;
	int r=n;
	int newr=a;
	
	while(newr!=0) {
		int q = r/newr;
		int newnewt=t-q*newt;
		t=newt;
		newt=newnewt;
		int newnewr=r-q*newr;
		r=newr;
		newr=newnewr;
	}
	if(r>1) {
		return -1;
	}
	else if(t<0){
		t=t+n;
	}
	
	return t;
}

int main() {
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int k, c;
		scanf("%d %d", &k, &c);
		
		if(c==1) {
			if((k+1)/c > 1000000000) {
				printf("IMPOSSIBLE\n");
				continue;
			}
			printf("%d\n", (k+1)/c);
			continue;
		}
		if(k==1) {
			printf("1\n");
			continue;
		}
		
		int res=gcd(c,k);
		
		
		if(res==-1) {
			printf("IMPOSSIBLE\n");
		} 
		else {
			if(res>1000000000) {
				printf("IMPOSSIBLE\n");
				continue;
			}
			printf("%d\n", res);
		}
		
		
	}
	
	return 0;
}