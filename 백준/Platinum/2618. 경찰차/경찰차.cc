#include <stdio.h>
#include <math.h>

typedef struct{
    int x;
    int y;
}road;

road incident[1003];
int dp[1001][1001];
int moved[1001][1001];
int w;

int discal(road a, road b) {
    return (abs(a.x-b.x)+abs(a.y-b.y));
}

int res(int a, int b) {
    if(a==w+1 || b==w+1) {
        return 0;
    }
    if(dp[a][b]!=0) {
        return dp[a][b];
    }

    int next;
    if(a>b) {
        next=a+1;
    }
    else {
        next=b+1;
    }

    int bmove=res(a,next)+discal(incident[b], incident[next]);
    int amove=res(next,b)+discal(incident[a], incident[next]);

    if(bmove<amove) {
        moved[a][b]=2;
    }
    else {
        moved[a][b]=1;
    }

    if(bmove<amove) {
        dp[a][b]=bmove;
    }
    else {
        dp[a][b]=amove;
    }

    return dp[a][b];
}

void solve() {
    int a=0, b=1;

    for(int i=2; i<w+2;i++) {
        if(moved[a][b]==1) {
            printf("1\n");
            a=i;
        }
        else {
            printf("2\n");
            b=i;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);


    scanf("%d", &w);

    road a;
    a.x=1;
    a.y=1;


    incident[0]=a;


    a.x=n;
    a.y=n;

    incident[1]=a;
    for(int i=2; i<w+2; i++) {
        scanf("%d %d", &a.y, &a.x);
        incident[i]=a;
    }

    printf("%d\n", res(0,1));
    solve();

    return 0;
}
