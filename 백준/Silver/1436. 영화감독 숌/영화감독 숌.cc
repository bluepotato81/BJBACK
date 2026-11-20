#include <cstdio>

int six(int a)
{
    int cnt=0, num=1;
    while(cnt<a)
    {
        int i=num;
        int h=0, t=0, o=0;

        while(i>0)
        {
            h=t;
            t=o;
            o=i%10;

            if(h==6 && t==6 && o==6)
            {
                cnt++;
                break;
            }
            i/=10;
        }

        num++;
    }
    return num;
}


int main()
{
    int n;
    scanf("%d", &n);


    printf("%d", six(n)-1);
    return 0;

}

