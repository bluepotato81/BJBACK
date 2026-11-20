#include <stdio.h>

void HanoiTower(int numOfDisks, int from, int by, int to) {
	if (numOfDisks == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		HanoiTower(numOfDisks - 1, from, to, by);
		printf("%d %d\n", from, to);
		HanoiTower(numOfDisks - 1, by, from, to);
	}
}

int main() {
    int k;
    scanf("%d", &k);
    int a=1;
    for(int i=0; i<k; i++) {
        a*=2;
    }
    a-=1;
    printf("%d\n", a);
	HanoiTower(k, 1,2,3);
}
