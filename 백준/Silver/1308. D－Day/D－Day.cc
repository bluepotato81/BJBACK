#include <stdio.h>

int main() {
	int y,m,d;
	int ey, em, ed;
	scanf("%d %d %d", &y, &m, &d);
	scanf("%d %d %d", &ey, &em, &ed);


	if(ey>y+1000 || (ey==y+1000 && em>m) || (ey==y+1000 && em==m && ed>=d)) {
        printf("gg");
        return 0;
	}

	int begdays=0, enddays=0;

	for(int i=1; i<y;i++) {
		if(i%400==0) {
			begdays+=366;
		}
		else if(i%100==0) {
			begdays+=365;
		}
		else if(i%4==0) {
			begdays+=366;
		}
		else {
			begdays+=365;
		}
	}

	for(int i=1; i<m; i++) {
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 ||i==12) {
			begdays+=31;
		}
		else if(i==4 || i==6 || i==9 || i==11) {
			begdays+=30;
		}
		else {
			if(y%400==0) {
				begdays+=29;
			}
			else if(y%100==0) {
				begdays+=28;
			}
			else if(y%4==0) {
				begdays+=29;
			}
			else {
				begdays+=28;
			}
		}
	}

	begdays+=d;

	for(int i=1; i<ey;i++) {
		if(i%400==0) {
			enddays+=366;
		}
		else if(i%100==0) {
			enddays+=365;
		}
		else if(i%4==0) {
			enddays+=366;
		}
		else {
			enddays+=365;
		}
	}
	for(int i=1; i<em; i++) {
		if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 ||i==12) {
			enddays+=31;
		}
		else if(i==4 || i==6 || i==9 || i==11) {
			enddays+=30;
		}
		else {
			if(ey%400==0) {
				enddays+=29;
			}
			else if(ey%100==0) {
				enddays+=28;
			}
			else if(ey%4==0) {
				enddays+=29;
			}
			else {
				enddays+=28;
			}
		}
	}
	enddays+=ed;

    int time=enddays-begdays;

    printf("D-%d", time);


	return 0;
}
