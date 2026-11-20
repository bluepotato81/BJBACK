#include <cstdio>


int main()
{
    int n;
    scanf("%d", &n);

    int place[10];


    int clap=0, a;
    for(int i=0; i<=n; i++)
    {
        a=i;
        for(int j=6; j>=0; j--)
        {
            place[j]=a%10;
            a/=10;
        }
        for(int j=0; j<=6; j++)
        {
            if(place[j]==3 || place[j]==6 || place[j]==9)
            {
                clap++;
            }
        }
    }

    printf("%d", clap);

    return 0;
}

