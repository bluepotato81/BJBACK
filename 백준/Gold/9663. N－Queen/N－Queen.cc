#include <stdio.h>
#include <stdbool.h>

void NQueen(int n, int row, int *res, bool *cols, bool *diags, bool *antidiags){
    if(row==n) {
        (*res)++;
        return;
    }
    for(int col=0; col<n; col++) {
        int diag = row-col+(n-1);
        int antidiag = row+col;
        if(!cols[col] && !diags[diag]&&!antidiags[antidiag]) {
            cols[col]=true;
            diags[diag]=true;
            antidiags[antidiag]=true;

            NQueen(n, row+1, res, cols, diags, antidiags);

            cols[col]=false;
            diags[diag]=false;
            antidiags[antidiag]=false;

        }
    }
}

int main() {
    int num=0;
    scanf("%d", &num);
    bool cols[num];
    bool diags[2*num-1];
    bool antidiags[2*num-1];

    for(int i=0; i<num; i++) {
        cols[i]=false;
    }
    for(int i=0; i<2*num-1; i++) {
        diags[i]=false;
        antidiags[i]=false;
    }
    int res=0;
    NQueen(num, 0,  &res, cols, diags, antidiags);
    printf("%d", res);

    return 0;
}
