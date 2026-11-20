#include <cstdio>

int main()
{
    int time[105]= {};

    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);

    int s, e;
    for(int i=0; i<3; i++)
    {
        scanf("%d %d", &s, &e);
        for(int j=s; j<e; j++)
        {
            time[j]+=1;
        }
    }

    int all=0;
    for(int i=0 ; i<=100; i++)
    {
        if(time[i]==1)
            all+=a;
        else if(time[i]==2)
            all+=2*b;
        else if(time[i]==3)
            all+=3*c;
    }

    printf("%d", all);



    return 0;

}

