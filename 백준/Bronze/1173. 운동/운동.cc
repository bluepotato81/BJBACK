#include <cstdio>

int main()
{

    int N, m, M, T, R;
    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);

    if(m+T>M)
    {
        printf("-1");
        return 0;
    }

    int tt=0, b=m, all=0;
    while(tt<N)
    {

        if(b<=M-T)
        {
            b+=T;
            tt++;
        }
        else
        {
            b-=R;
            if(b<m)
            {
                b = m;
            }
        }
        all++;
    }

    printf("%d", all);


    return 0;

}
