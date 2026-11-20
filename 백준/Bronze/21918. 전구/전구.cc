#include <cstdio>
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    int bulb[4005];

    for(int i=0; i<n; i++)
    {
        scanf("%d", &bulb[i]);
    }


    int f_num, il, xr;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d", &f_num, &il, &xr);
        if(f_num==1)
        {
            bulb[il-1]=xr;
        }
        else if(f_num==2)
        {
            for(int j=il-1; j<xr; j++)
            {
                if(bulb[j]==0)
                    bulb[j]=1;
                else
                    bulb[j]=0;
            }
        }
        else if(f_num==3)
        {
            for(int j=il-1; j<xr; j++)
            {
                bulb[j]=0;
            }
        }
        else if(f_num==4)
        {
            for(int j=il-1; j<xr; j++)
            {
                bulb[j]=1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d ", bulb[i]);
    }



    return 0;
}

