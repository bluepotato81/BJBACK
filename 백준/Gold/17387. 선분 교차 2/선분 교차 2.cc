#include <stdio.h>

long long ori(long long a, long long b, long long c, long long d, long long e, long long f) {
    long long k = (d-b)*(e-c) - (c-a)*(f-d);
    if(k>0) {
        return 1;
    }
    else if(k==0) {
        return 0;
    }
    else {
        return -1;
    }
}

long long mi(long long x, long long y) {
    if(x<y) {
        return x;
    }
    else {
        return y;
    }
}
long long ma(long long x, long long y) {
    if(x>y) {
        return x;
    }
    else {
        return y;
    }
}

int on_segment(long long a, long long b, long long c, long long d, long long e, long long f) {
    return mi(a, c) <= e && e <= ma(a, c) && mi(b, d) <= f && f <= ma(b, d);
}

int main() {
    long long a,b,c,d,e,f,g,h;
    scanf("%lld %lld %lld %lld\n%lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &g, &h);

    long long o1=ori(a,b,c,d,e,f);
    long long o2=ori(a,b,c,d,g,h);
    long long o3=ori(e,f,g,h,a,b);
    long long o4=ori(e,f,g,h,c,d);

    if(o1*o2<0 && o3*o4<0) {
        printf("1");
    }
    else if(o1*o2==0 || o3*o4==0) {
        if ((o1 == 0 && on_segment(a, b, c, d, e, f)) ||
            (o2 == 0 && on_segment(a, b, c, d, g, h)) ||
            (o3 == 0 && on_segment(e, f, g, h, a, b)) ||
            (o4 == 0 && on_segment(e, f, g, h, c, d))) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    else{
        printf("0");
    }

    return 0;
}
