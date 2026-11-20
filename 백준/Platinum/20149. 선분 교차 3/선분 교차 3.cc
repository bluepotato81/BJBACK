#include <iostream>

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

    long double la=(long double)a;
    long double lb=(long double)b;
    long double lc=(long double)c;
    long double ld=(long double)d;
    long double le=(long double)e;
    long double lf=(long double)f;
    long double lg=(long double)g;
    long double lh=(long double)h;

    if(o1*o2<0 && o3*o4<0) { //normal case
        printf("1\n");
        long double a1=(lb*lc)-(ld*la);
        long double a2=lg-le;
        long double a3=(lf*lg)-(lh*le);
        long double a4=lc-la;
        long double a5=lh-lf;
        long double a6=ld-lb;

        long double x=((a1*a2)-(a3*a4))/((a5*a4)-(a6*a2));
        long double y;
        if(a4!=0){
            y=((x*a6)+a1)/a4;
        }
        else {
            y=((x*a5)+a3)/a2;
        }
        printf("%.11Lf %.11Lf",x,y);

    }
    else if(o1*o2==0 || o3*o4==0) { //one or more points is on the extended line of the other segment
        if ((o1 == 0 && on_segment(a, b, c, d, e, f)) ||
            (o2 == 0 && on_segment(a, b, c, d, g, h)) ||
            (o3 == 0 && on_segment(e, f, g, h, a, b)) ||
            (o4 == 0 && on_segment(e, f, g, h, c, d))) { // the point is on the other segment
                if(o1*o2==0 && o3*o4==0) { //the two segments are on the same line
                    if((o1 ==0 && o2==0 && on_segment(a, b, c, d, e, f) == 1 && on_segment(a, b, c, d, g, h)==1)||(o3==0 && o4==0 && on_segment(e, f, g, h, a, b) == 1 && on_segment(e, f, g, h, c, d)==1)){
                        //a segment is completely 'inside' the other segment
                        printf("1");
                    }
                    //the segments share an end point
                    else if(a==e && b==f){
                        printf("1\n");
                        printf("%lld %lld",a,b);
                    }
                    else if (a==g && b==h) {
                        printf("1\n");
                        printf("%lld %lld", a,b);
                    }
                    else if (c==e && d==f) {
                        printf("1\n");
                        printf("%lld %lld", c,d);
                    }
                    else if (c==g&&d==h) {
                        printf("1\n");
                        printf("%lld %lld", c,d);
                    }
                    else{ //the segments overlap on more than 1 point
                        printf("1");
                    }
                }
                else { //the two segments are not on the same line
                    printf("1\n");
                    long double a1=(b*c)-(d*a);
                    long double a2=g-e;
                    long double a3=(f*g)-(h*e);
                    long double a4=c-a;
                    long double a5=h-f;
                    long double a6=d-b;

                    long double x=((a1*a2)-(a3*a4))/((a5*a4)-(a6*a2));
                    long double y;
                    if(a4!=0){
                        y=((x*a6)+a1)/a4;
                    }
                    else {
                        y=((x*a5)+a3)/a2;
                    }
                    printf("%.11Lf %.11Lf",x,y);
                }

            }
        else { //the segments do not meet
            printf("0");
        }
    }
    else{ //the segments do not meet
        printf("0");
    }
    return 0;
}
