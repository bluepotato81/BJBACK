#include <cstdio>

int fr[2000005];

int main()
{
    int n,c;
    scanf("%d %d", &n, &c);


    int a;
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a);
        for(int j=1; j<=c; j++)
        {
            if(j%a==0)
                fr[j]++;
        }
    }

    int cd=0;
    for(int j=1; j<=c; j++)
    {
        if(fr[j]>0)
        {
            cd++;
        }
    }
    printf("%d", cd);

    return 0;
}

