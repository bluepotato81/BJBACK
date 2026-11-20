#include <stdio.h>
#include <limits.h>

int mincd=INT_MAX;

typedef struct{
    int row;
    int col;
}loc;



void calcd(loc h[], int hn, loc select[], int cn, int m) {
    int totdis=0;

    for(int i=0; i<hn; i++) {
        int houseRow = h[i].row;
        int houseCol = h[i].col;
        int minDistance = INT_MAX;
        for (int j = 0; j < m; j++) {
            int chickenRow = select[j].row;
            int chickenCol = select[j].col;
            int k,d;
            if(houseRow>chickenRow) {
                k=houseRow-chickenRow;
            }
            else {
                k=-(houseRow-chickenRow);
            }
            if(houseCol>chickenCol) {
                d=houseCol-chickenCol;
            }
            else {
                d=-(houseCol-chickenCol);
            }
            int distance = k+d;
            if (distance < minDistance) {
                minDistance = distance;
            }
        }
        totdis += minDistance;
    }
    if (totdis < mincd) {
        mincd = totdis;
    }
}

void gencom(loc ch[], int n, loc select[], int cn, int m, int start, int depth, loc h[], int hn) {
    if (depth == m) {
        calcd(h, hn, select, cn, m);
        return;
    }
    for (int i = start; i < cn; i++) {
        select[depth] = ch[i];
        gencom(ch, n, select, cn, m, i + 1, depth + 1, h, hn);
    }
}

int main() {
    int n,m;
    scanf("%d %d", &n, &m);

    int city[n][n];

    loc ch[13];
    loc h[2*n];

    int cn=0;
    int hn=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &city[i][j]);
            if(city[i][j]==2) {
                loc in;
                in.row=i;
                in.col=j;
                ch[cn]=in;
                cn++;
            }
            if(city[i][j]==1) {
                loc in;
                in.row=i;
                in.col=j;
                h[hn]=in;
                hn++;
            }
        }
    }

    loc selected[m];

    gencom(ch, n, selected, cn, m, 0, 0, h, hn);
    printf("%d", mincd);


    return 0;
}
