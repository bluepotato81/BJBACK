#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);


    int num=1;
    int t=0;
    while(n>0)
    {
        if(n<num)
            num=1;
        n-=num;
        num++;
        t++;
    }
    printf("%d", t);



    return 0;
}
