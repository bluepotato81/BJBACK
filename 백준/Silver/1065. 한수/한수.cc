#include <cstdio>


int main()
{
    int n;
    scanf("%d", &n);


    int h=0,k,t, a[3];
    for(int i=1;i<=n;i++)
    {
        if(i<100)
            h++;
        else if(i==1000)
            break;
        else
        {
            k=0;
            t=i;
            while(t>0)
            {
                a[k]=t%10;
                t/=10;
                k++;
            }
            if(a[0]-a[1]==a[1]-a[2])
                h++;
        }

    }
    printf("%d", h);


    return 0;
}

