#include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    int room[20]={};

    int s, y;
    for(int i=0; i<n; i++)
    {
        scanf("%d %d", &s, &y);
        room[y*2-(2-s)]++;
    }

    int r=0;
    for(int i=0; i<12; i++)
    {
        r+=room[i]/k+(room[i]%k != 0);
    }
    printf("%d",r);

    return 0;

}

