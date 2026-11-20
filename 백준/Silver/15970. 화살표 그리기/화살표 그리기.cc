#include <cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int p[n][2];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
            scanf("%d", &p[i][j]);
    }

    int all=0;
    for(int i=0; i<n; i++)
    {
        int clos=100005;
        for(int j=0; j<n; j++)
        {
            if(p[i][1]==p[j][1] && i!=j)
            {
                int a = p[i][0]-p[j][0];
                if(a<0)
                    a=-a;
                if(a<clos)
                    clos=a;
            }
        }
        all+=clos;
    }

    printf("%d", all);

    return 0;

}

