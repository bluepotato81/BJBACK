#include <cstdio>

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);

    int card[105];

    for(int i=0; i<n; i++)
        scanf("%d", &card[i]);

    int clos=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int sum= card[i]+card[j]+card[k];
                if(sum <=m && clos<sum)
                    clos=sum;
            }
        }
    }

    printf("%d", clos);


    return 0;

}

