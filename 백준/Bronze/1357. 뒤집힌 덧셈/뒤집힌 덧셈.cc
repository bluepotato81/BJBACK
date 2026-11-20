#include <cstdio>


int rev(int x)
{
    int res = 0;

    while(x>0)
    {
        res=res*10 + x%10;
        x/=10;
    }
    return res;
}




int main()
{
    int x, y;
    scanf("%d %d", &x,&y);

    printf("%d", rev(rev(x)+rev(y)));



    return 0;

}

