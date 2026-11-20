#include <stdio.h>

int val_cal(int bef_val, int op, int op_val) {
    if(op==1) {
        return bef_val+op_val;
    }
    else if(op==2) {
        return bef_val-op_val;
    }
    else if(op==3) {
        return bef_val*op_val;
    }
    else {
        return bef_val/op_val;
    }
}

void minmax(int n, int num[], int pl, int ml, int mu, int di, int *max, int *min, int ref, int val) {
    int next_val;
    if(ref==1 && n!=2) {
        if(pl>0) {
            next_val = val_cal(num[0], 1, num[1]);
            minmax(n, num, pl-1, ml, mu, di, max, min, ref+1, next_val);
        }
        if(ml>0) {
            next_val = val_cal(num[0], 2, num[1]);
            minmax(n, num, pl, ml-1, mu, di, max, min, ref+1, next_val);
        }
        if(mu>0) {
            next_val = val_cal(num[0], 3, num[1]);
            minmax(n, num, pl, ml, mu-1, di, max, min, ref+1, next_val);
        }
        if(di>0) {
            next_val = val_cal(num[0], 4, num[1]);
            minmax(n, num, pl, ml, mu, di-1, max, min, ref+1, next_val);
        }
    }
    else if(ref==n-1) {
        if(pl>0) {
            next_val = val_cal(val, 1, num[ref]);
            if(next_val>(*max)) {
                (*max)=next_val;
            }
            if(next_val<(*min)) {
                (*min)=next_val;
            }
        }
        if(ml>0) {
            next_val = val_cal(val, 2, num[ref]);
            if(next_val>(*max)) {
                (*max)=next_val;
            }
            if(next_val<(*min)) {
                (*min)=next_val;
            }
        }
        if(mu>0) {
            next_val = val_cal(val, 3, num[ref]);
            if(next_val>(*max)) {
                (*max)=next_val;
            }
            if(next_val<(*min)) {
                (*min)=next_val;
            }
        }
        if(di>0) {
            next_val = val_cal(val, 4, num[ref]);
            if(next_val>(*max)) {
                (*max)=next_val;
            }
            if(next_val<(*min)) {
                (*min)=next_val;
            }
        }
    }
    else  {
        if(pl>0) {
            next_val = val_cal(val, 1, num[ref]);
            minmax(n, num, pl-1, ml, mu, di, max, min, ref+1, next_val);
        }
        if(ml>0) {
            next_val = val_cal(val, 2, num[ref]);
            minmax(n, num, pl, ml-1, mu, di, max, min, ref+1, next_val);
        }
        if(mu>0) {
            next_val = val_cal(val, 3, num[ref]);
            minmax(n, num, pl, ml, mu-1, di, max, min, ref+1, next_val);
        }
        if(di>0) {
            next_val = val_cal(val, 4, num[ref]);
            minmax(n, num, pl, ml, mu, di-1, max, min, ref+1, next_val);
        }
    }

}


int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &num[i]);
    }
    int pl, mi, mu, di;
    scanf("%d %d %d %d", &pl, &mi, &mu, &di);
    int max=-1000000000;
    int min=1000000000;

    minmax(n, num, pl, mi, mu, di, &max,  &min, 1, num[0]);

    printf("%d\n%d", max,min);

    return 0;
}
